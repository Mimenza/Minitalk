/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 00:28:30 by emimenza          #+#    #+#             */
/*   Updated: 2023/11/03 12:53:27 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_writeData(int binary) {
	int res;
	int base;
	int digit;

	res = 0;
	base = 1;
	digit = 0;
	if (binary == 0010000)
		{
			ft_printf("\n");
			return;
		}
	while (binary > 0)
	{
		digit = binary % 10;
		res += digit * base;
		base *= 2;
		binary /= 10;
	}
	ft_printf("%c", res);
}

void	ft_handler(int signal, siginfo_t *info, void *config)
{
	static int	bit = 0;
	static int	word_size = 0;

	if (signal == SIGUSR1)
	{
		bit = (bit * 10) + 1;
	}
	else
	{
		bit = (bit * 10) + 0;
	}
	word_size++;
	if (word_size == 8)
	{
		ft_writeData(bit);
		kill(info->si_pid, SIGUSR2);
		word_size = 0;
		bit = 0;
	}
}


int	main(int argc, char **argv)
{
	int                 pid;
    struct sigaction    sig;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Try ./server\n");
		return (0);
	}
	pid = getpid();
	ft_printf("The id of the server is : %i \n", pid);
	ft_printf("Waiting...\n");
    sig.sa_sigaction = ft_handler;
    sigemptyset(&sig.sa_mask);
    sig.sa_flags = 0;
	while (1)
	{
        sigaction(SIGUSR1, &sig, NULL);
        sigaction(SIGUSR2, &sig, NULL);
		pause();
	}
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 00:28:30 by emimenza          #+#    #+#             */
/*   Updated: 2023/12/06 11:10:14 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int signal, siginfo_t *info, void *config)
{
	static int	byte;
	static int	word_size;

	(void)info;
	(void)config;
	if (signal == SIGUSR1)
		byte |= (0x01 << word_size);
	word_size++;
	if (word_size == 8)
	{
		ft_printf("%c", byte);
		kill(info->si_pid, SIGUSR2);
		word_size = 0;
		byte = 0;
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Try ./server\n");
		return (0);
	}
	pid = getpid();
	ft_printf("The id of the server is : %i \n", pid);
	ft_printf("Waiting...\n");
	sa.sa_sigaction = ft_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 08:28:02 by emimenza          #+#    #+#             */
/*   Updated: 2023/11/02 18:53:52 by emimenza         ###   ########.fr       */
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

void	ft_handler(int signal)
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
		word_size = 0;
		bit = 0;
	}
}

int	main(int argc, char **argv)
{
	int pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Try ./server\n");
		return (0);
	}
	pid = getpid();
	ft_printf("The id of the server is : %i \n", pid);
	ft_printf("Waiting...\n");	
	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	while (1)
	{
		pause();
	}
	return (0);
}
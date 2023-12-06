/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 08:28:02 by emimenza          #+#    #+#             */
/*   Updated: 2023/12/06 11:11:02 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int signal)
{
	static int	byte;
	static int	word_size;

	if (signal == SIGUSR1)
		byte |= (0x01 << word_size);
	word_size++;
	if (word_size == 8)
	{
		ft_printf("%c", byte);
		word_size = 0;
		byte = 0;
	}
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		ft_printf("Try ./server\n");
		return (0);
	}
	ft_printf("The id of the server is : %i \n", getpid());
	ft_printf("Waiting...\n");
	while (1)
	{
		signal(SIGUSR1, ft_handler);
		signal(SIGUSR2, ft_handler);
		pause();
	}
	return (0);
}

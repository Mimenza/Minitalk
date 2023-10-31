/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 08:28:02 by emimenza          #+#    #+#             */
/*   Updated: 2023/10/31 13:02:29 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


void	ft_handler(int signal)
{
	(void)signal;
	printf("acabo de recibir algo");
}
int	main(int argc, char **argv)
{
	int pid;

	(void)argv;
	if (argc != 1)
	{
		printf("Try ./server\n");
		return (0);
	}
	pid = getpid();
	printf("The id of the server is : %i \n", pid);
	printf("Waiting...\n");
	while (argc == 1)
	{
		signal(SIGUSR1, ft_handler);
		signal(SIGUSR2, ft_handler);
		pause();
	}
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 08:28:02 by emimenza          #+#    #+#             */
/*   Updated: 2023/10/31 11:05:02 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


void	ft_handler(int signal)
{
	(void)signal;
	//traducir de bytes binarios a texto.
	printf("acabo de recibir algo");
}
int	main(int argc, char **argv)
{
	int pid;

	(void)argc;
	(void)argv;	
	pid = getpid();
	ft_printf("The id of the server is : %i \n", pid);
	//ft_printf("The id of the server is : %i \n", pid);
	while(argc == 1)
	{
		signal(SIGUSR1, ft_handler);
		signal(SIGUSR2, ft_handler);
		pause();
	}
	
}
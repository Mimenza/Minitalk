/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 00:28:26 by emimenza          #+#    #+#             */
/*   Updated: 2023/11/04 16:47:54 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void    ft_receiver(int signal)
{
	(void)signal;
    ft_printf("The msg has been delivered and received correctly");
}

void	ft_sendData(int pid, char c)
{
	int	bit;

	bit = 0;
    while (bit < 8)
	{
        if ((c & (0x01 << bit)) != 0)
            kill(pid, SIGUSR1);
 		else 
            kill(pid, SIGUSR2);
		usleep(200);
        bit ++;
    }
}

int main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			signal(SIGUSR1, ft_receiver);
			signal(SIGUSR2, ft_receiver);
			ft_sendData(pid, argv[2][i]);
			i++;
		}
		ft_sendData(pid, '\n');			
	}
	else
	{
		ft_printf("Wrong number of arguments");
		return(1);
	}
	return(0);
}
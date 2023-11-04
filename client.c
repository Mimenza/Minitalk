/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 08:27:59 by emimenza          #+#    #+#             */
/*   Updated: 2023/11/04 16:38:36 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
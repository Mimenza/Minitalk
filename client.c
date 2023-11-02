/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 08:27:59 by emimenza          #+#    #+#             */
/*   Updated: 2023/10/31 12:57:40 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_sendData(int pid, char c)
{
	int	i;
	int	bit;

	i = 7;
	bit = 0;
    while (i >= 0)
	{
        bit = (c >> i) & 1;
        if (bit == 1) {
            kill(pid, SIGUSR1);

        } else {
            kill(pid, SIGUSR2);
        }
		usleep(100);
        i--;
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 08:27:59 by emimenza          #+#    #+#             */
/*   Updated: 2023/10/31 12:01:00 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_sendData(int pid, char c)
{
	int i;

	i = 0;
	(void)pid;
	while (i <= 8)
	{
		ft_printf("%i" ,(c & (1 << i)) ? '1' : '0');
		i++;
	}
	ft_printf("%c", '\n');
}

int main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
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
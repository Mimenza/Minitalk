/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 08:01:48 by emimenza          #+#    #+#             */
/*   Updated: 2023/11/06 08:04:43 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	number;
	int	sign;
	int	i;

	number = 0;
	sign = 1;
	i = 0;
	while (*(str + i) == 32 || (*(str + i) >= 9 && *(str + i) <= 13))
		i++;
	if (*(str + i) == '-')
		sign = -1;
	if (*(str + i) == '+' || *(str + i) == '-')
		i++;
	while (*(str + i) >= '0' && *(str + i) <= '9')
	{
		number = number * 10 + (*(str + i) - 48);
		i++;
	}
	return (number * sign);
}

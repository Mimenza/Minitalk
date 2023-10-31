/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:05:11 by emimenza          #+#    #+#             */
/*   Updated: 2023/10/31 08:58:59 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_getformat(va_list args, char	const sign, int *length)
{
	if (*length == -1)
		return ;
	if (sign == 'c')
		ft_printchar(va_arg(args, int), length);
	else if (sign == 's')
		ft_printstring(va_arg(args, char *), length);
	else if (sign == 'p')
		ft_printptr(va_arg(args, unsigned long long int), length);
	else if (sign == 'd')
		ft_printnbr(va_arg(args, int), length);
	else if (sign == 'i')
		ft_printnbr(va_arg(args, int), length);
	else if (sign == 'u')
		ft_printu(va_arg(args, int), length);
	else if (sign == 'x')
		ft_to_base(va_arg(args, int), "0123456789abcdef", length);
	else if (sign == 'X')
		ft_to_base(va_arg(args, int), "0123456789ABCDEF", length);
	else if (sign == '%')
		ft_printchar('%', length);
	else
		return ;
}

int	ft_printf(char const *str, ...)
{
	int		length;
	int		i;
	va_list	args;

	i = 0;
	length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_getformat(args, str[i], &length);
		}
		else
			ft_printchar(str[i], &length);
		i++;
	}
	va_end(args);
	return (length);
}


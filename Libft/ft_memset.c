/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:52:50 by emimenza          #+#    #+#             */
/*   Updated: 2023/10/11 10:45:14 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*str;

	str = (char *)b;
	while (len > 0)
	{
		str[len - 1] = c;
		len --;
	}
	return (b);
}

// int main(void)
// {
// 	char str[50];
// 	strcpy(str, "Hello World");
// 	puts(str);
// 	ft_memset(str, '$', 5);
// 	puts(str);
// 	return (0);
// }
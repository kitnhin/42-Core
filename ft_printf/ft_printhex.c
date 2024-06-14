/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheelim <cheelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:33:36 by ethanlim          #+#    #+#             */
/*   Updated: 2024/06/14 17:12:07 by cheelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	size(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}

int	printhex(unsigned int n, char *base)
{
	unsigned int	nsize;

	nsize = size(n);
	if (n >= 16)
	{
		printhex(n / 16, base);
		printhex(n % 16, base);
	}
	if (n < 16)
		write(1, &base[n], 1);
	return (nsize);
}
// int printhex(int n, char *base)
// {
//     int len;
//     char *str;
//     int i;
//     int nb;

//     len = 1;
//     nb = n;
// 	if (nb < 0)
// 	{
// 		nb *= -1;
// 		len++;
// 	}
//     while(nb > 16)
//     {
//         nb /= 16;
//         len++;
//     }
//     i = len - 1;
//     str = (char *)malloc(len + 1);
// 	if (n < 0)
// 	{
// 		str[0] = '-';
// 		n *= -1;
// 	}
//     while (i >= 0)
//     {
//         str[i] = base[n % 16];
//         n /= 16;
//         i--;
//     }
//     str[len] = '\0';
//     write(1,str,len);
//     free(str);
//     return (len);
// }

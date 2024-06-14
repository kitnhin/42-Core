/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheelim <cheelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:54:06 by cheelim           #+#    #+#             */
/*   Updated: 2024/06/14 17:11:54 by cheelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	size(int nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		len++;
		nb *= -1;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

int	printint(int n)
{
	int	len;

	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	len = size(n);
	if (n < 0)
	{
		printchar('-');
		n = -n;
	}
	if (n > 9)
	{
		printint(n / 10);
		printint(n % 10);
	}
	if (n <= 9)
		printchar(n + '0');
	if (n == 0)
		return (1);
	return (len);
}

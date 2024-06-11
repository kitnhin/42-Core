/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheelim <cheelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:54:06 by cheelim           #+#    #+#             */
/*   Updated: 2024/06/11 17:54:07 by cheelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printint(int n)
{
	int len;
	int nb;
	
	nb = n;
	len = 0;
	while (nb > 0)
	{
	    nb /= 10;
	    len++;
	}
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
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
	return (len);
}
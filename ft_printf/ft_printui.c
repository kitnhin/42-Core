/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printui.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheelim <cheelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:48:47 by cheelim           #+#    #+#             */
/*   Updated: 2024/06/14 17:10:18 by cheelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printui(unsigned int n)
{
	unsigned int	len;
	unsigned int	nb;

	nb = n;
	len = 0;
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	if (n > 9)
	{
		printui(n / 10);
		printui(n % 10);
	}
	if (n <= 9)
		printchar(n + '0');
	if (n == 0)
		return (1);
	return (len);
}

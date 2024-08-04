/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheelim <cheelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:53:06 by cheelim           #+#    #+#             */
/*   Updated: 2024/06/14 17:13:10 by cheelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*string(char *str, int len, uintptr_t tempptr, char *base)
{
	int	i;

	i = len;
	while (--i >= 0)
	{
		str[i] = base[tempptr % 16];
		tempptr /= 16;
	}
	str[len] = '\0';
	return (str);
}

int	printptr(void *ptr, char *base)
{
	int			len;
	uintptr_t	tempptr;
	uintptr_t	tempptr2;
	char		*str;

	len = 0;
	tempptr = (uintptr_t)ptr;
	tempptr2 = (uintptr_t)ptr;
	write(1, "0x", 2);
	if (!ptr)
		len += printchar('0');
	else
	{
		while (tempptr2 > 0)
		{
			tempptr2 /= 16;
			len++;
		}
		str = (char *)malloc(len + 1);
		str = string(str, len, tempptr, base);
		write(1, str, len);
		free(str);
	}
	len += 2 ;
	return (len);
}

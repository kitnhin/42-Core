/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheelim <cheelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:54:01 by cheelim           #+#    #+#             */
/*   Updated: 2024/06/14 16:48:39 by cheelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printformat(va_list args, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = printchar(va_arg(args, int));
	else if (c == 's')
		len = printstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		len = printint(va_arg(args, int));
	else if (c == '%')
		len = printchar('%');
	else if (c == 'p')
		len = printptr(va_arg(args, void *), "0123456789abcdef");
	else if (c == 'u')
		len = printui(va_arg(args, unsigned int));
	else if (c == 'X')
		len = printhex(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (c == 'x')
		len = printhex(va_arg(args, unsigned int), "0123456789abcdef");
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	len = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
			len += printchar(str[i]);
		if (str[i] == '%')
		{
			len += printformat(args, str[i + 1]);
			i++;
		}
		i++;
	}
	va_end(args);
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethanlim <ethanlim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:33:36 by ethanlim          #+#    #+#             */
/*   Updated: 2024/06/12 21:40:36 by ethanlim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int printhex(int n, char *base)
{
    int len;
    char *str;
    int i;
    int nb;

    len = 1;
    nb = n;
    while(nb > 16)
    {
        nb /= 16;
        len++;
    }
    i = len - 1;
    str = (char *)malloc(len + 1);
    while (i >= 0)
    {
        str[i] = base[n % 16];
        n /= 16;
        i--;
    }
    str[len] = '\0';
    write(1,str,len);
    free(str);
    return (len);
}

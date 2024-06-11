/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheelim <cheelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:54:13 by cheelim           #+#    #+#             */
/*   Updated: 2024/06/11 20:30:10 by cheelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main() 
{
    char c = '!';
    char str1[20] = "I am";
    char str2[20] = "years";
    int n = 20;
    int a = 0x5B;
    int len = ft_printf("%s %d %s old %c\n", str1, n, str2, c);
    // printf ("value in deci = %d value in hex = %X at address = %p", n, n, &a);
	printint(len);
	unsigned int b = 
    return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethanlim <ethanlim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:54:13 by cheelim           #+#    #+#             */
/*   Updated: 2024/06/12 16:45:47 by ethanlim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h> // Include the necessary header for va_list

int printchar(int c)
{
    write(1, &c, 1);
    return (1);
}

int printformat(va_list args, char c)
{
    int len;

    len = 0;
    if (c == 'c')
        len = printchar(va_arg(args, int));

    return (len);
}

int ft_printf(const char *str, ...)
{
    va_list args; // Declare a va_list variable
    int i;
    int len;

    len = 0;
    i = 0;
    va_start(args, str); // Initialize the va_list
    while (str[i])
    {
        if (str[i] == '%')
        {
            len += printformat(args, str[i + 1]);
            i += 2;
        }
        else
        {
            len += printchar(str[i]); // Print regular characters
            i++;
        }
    }
    va_end(args); // Clean up the va_list
    return (len);
}

int main()
{
    ft_printf(" %c %c ", 49, 50); // Pass the ASCII values 49 ('1') and 50 ('2')
    write(1, "\n", 1);
    printf(" %c %c ", '1', '2'); // Use character literals directly
    return 0;
}

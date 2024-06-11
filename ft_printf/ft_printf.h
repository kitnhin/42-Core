/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheelim <cheelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:54:03 by cheelim           #+#    #+#             */
/*   Updated: 2024/06/11 18:50:16 by cheelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H 
#define FT_PRINT_H

#include <unistd.h>
#include <stdarg.h>

int	printint(int n);
int printchar(int c);
int printstr(char *str);
int ft_printf(const char *str, ...);
int	printui(unsigned int n);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethanlim <ethanlim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:54:03 by cheelim           #+#    #+#             */
/*   Updated: 2024/06/12 23:08:30 by ethanlim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H 
#define FT_PRINT_H

#include <unistd.h>
#include <stdarg.h>
#include <stdint.h>

int	printint(int n);
int printchar(int c);
int printstr(char *str);
int ft_printf(const char *str, ...);
int	printui(unsigned int n);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheelim <cheelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:54:03 by cheelim           #+#    #+#             */
/*   Updated: 2024/06/14 17:08:32 by cheelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H 
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>

int	printint(int n);
int	printchar(int c);
int	printstr(char *str);
int	ft_printf(const char *str, ...);
int	printui(unsigned int n);
int	printhex(unsigned int n, char *base);
int	printptr(void *ptr, char *base);

#endif
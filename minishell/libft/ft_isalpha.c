/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheelim <cheelim@student.42.fr.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:47:34 by cheelim           #+#    #+#             */
/*   Updated: 2024/06/03 18:05:03 by cheelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int n)
{
	if ((n >= 'A' && n <= 'Z') || (n >= 'a' && n <= 'z'))
		return (1);
	else
		return (0);
}
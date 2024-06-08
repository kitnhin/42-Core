/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheelim <cheelim@student.42.fr.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:57:38 by cheelim           #+#    #+#             */
/*   Updated: 2024/06/03 18:06:04 by cheelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t size)
{
	size_t	i;
	char	*pointer;

	pointer = ptr;
	i = 0;
	while (i < size)
	{
		pointer[i] = c;
		i++;
	}
	return (ptr);
}

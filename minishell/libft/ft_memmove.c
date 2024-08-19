/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheelim <cheelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:29:33 by cheelim           #+#    #+#             */
/*   Updated: 2024/06/04 21:34:47 by cheelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t size)
{
	size_t		i;
	char		*dest;
	const char	*src;

	dest = destination;
	src = source;
	i = -1;
	if (!dest && !src)
		return (NULL);
	if (src < dest)
	{
		i = size;
		while (i > 0)
		{
			i--;
			dest[i] = src[i];
		}
	}
	else
	{
		while (++i < size)
			dest[i] = src[i];
	}
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheelim <cheelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 21:40:38 by cheelim           #+#    #+#             */
/*   Updated: 2024/06/04 22:04:14 by cheelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	j;
	size_t	src_len;

	src_len = ft_strlen((char *)src);
	if (size == 0 && dest == NULL)
		return (src_len);
	dest_len = ft_strlen(dest);
	while (src[src_len] != '\0')
		src_len++;
	if (size == 0 || dest_len > size)
		return (src_len + size);
	j = 0;
	if (dest_len < size - 1 && size > 0)
	{
		while (dest_len < size - 1 && src[j] != '\0')
			dest[dest_len++] = src[j++];
		dest[dest_len] = '\0';
	}
	j--;
	while (src[++j] != '\0')
		dest_len++;
	return (dest_len);
}

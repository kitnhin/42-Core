/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethanlim <ethanlim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:07:03 by cheelim           #+#    #+#             */
/*   Updated: 2024/06/09 12:44:52 by ethanlim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*str;

	if (num == 0 || size == 0)
	{
		str = ft_strdup("");
		if (!str)
			return (NULL);
		return (str);
	}
	// if (num > 4294967295 || size > 4294967295)
	// 	return (NULL);
	if (num > 4294967295 / size)
		return (NULL);
	str = (void *)malloc(num * size);
	if (!str)
		return (NULL);
	ft_bzero(str, num * size);
	return (str);
}

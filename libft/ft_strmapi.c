/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheelim <cheelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:10:34 by cheelim           #+#    #+#             */
/*   Updated: 2024/06/08 18:13:54 by cheelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*dest;

	i = 0;
	if (!s || !f)
		return (NULL);
	dest = ft_strdup(s);
	if (!dest)
		return (NULL);
	while (dest[i] != '\0')
	{
		dest[i] = (*f)(i, dest[i]);
		i++;
	}
	return (dest);
}

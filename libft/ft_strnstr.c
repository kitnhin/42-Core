/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheelim <cheelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:25:00 by cheelim           #+#    #+#             */
/*   Updated: 2024/06/06 17:25:24 by cheelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *string, const char *to_find, size_t len)
{
	int		i;
	size_t	count;
	char	*str;

	i = 0;
	count = 1;
	str = (char *)string;
	if (!str && !len)
		return (NULL);
	if (*to_find == '\0')
	{
		return (str);
	}
	while (*str != '\0' && *str != *to_find && count < len)
	{
		str++;
		count++;
	}
	while (str[i] == to_find[i])
	{
		i++;
		if (to_find[i] == '\0')
			return (str);
	}
	return (0);
}

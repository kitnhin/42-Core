/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheelim <cheelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 23:41:32 by ethanlim          #+#    #+#             */
/*   Updated: 2024/06/08 18:13:38 by cheelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	total_size(char const *s, unsigned int start, size_t len)
{
	int	size;

	if (!s)
		return (0);
	if (ft_strlen((char *)s) - start < len)
		size = ft_strlen((char *)s) - start;
	else
		size = len;
	return (size);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		size;
	char	*str;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	size = total_size(s, start, len);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	i = start;
	j = 0;
	while (j < len && s[i] != '\0' && start < ft_strlen((char *)s) && len > 0)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}

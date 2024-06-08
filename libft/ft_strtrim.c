/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheelim <cheelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:41:57 by cheelim           #+#    #+#             */
/*   Updated: 2024/06/08 20:59:21 by cheelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

int	isset(char const *set, int c)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		len;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (isset(set, s1[start]) == 1)
		start++;
	while (isset(set, s1[end]) == 1)
		end--;
	len = end - start + 1;
	str = ft_substr(s1, start, len);
	if (str)
		return (str);
	return (NULL);
}

// int main()
// {
// 	printf("%s", ft_strtrim("abcdba", "acb"));
// }

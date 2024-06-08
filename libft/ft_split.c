/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheelim <cheelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 18:11:38 by cheelim           #+#    #+#             */
/*   Updated: 2024/06/08 18:13:00 by cheelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_strings(char const *s, char c)
{
	int	i;
	int	count;

	count = 1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			if (s[i + 1] != c)
				count++;
		}
		i++;
	}
	if (s[0] == c)
		count--;
	if (s[i - 1] == c)
		count--;
	return (count);
}

int	ft_delimstrl(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	return (len);
}

void	putstr(char *dest, char const *str, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	count = count_strings(s, c);
	str = malloc (sizeof(char *) * (count + 1));
	if (!str)
		return (NULL);
	while (i < ft_strlen(s) && j < count)
	{
		while (s[i] == c)
			i++;
		str[j] = (char *)malloc(sizeof(char) * (ft_delimstrl(s + i, c) + 1));
		if (!str[j])
			return (NULL);
		putstr(str[j++], s + i, ft_delimstrl(s + i, c));
		i += ft_delimstrl(s + i, c);
	}
	str[j] = NULL;
	return (str);
}

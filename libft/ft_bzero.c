/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheelim <cheelim@student.42.fr.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:40:13 by cheelim           #+#    #+#             */
/*   Updated: 2024/06/03 17:42:13 by cheelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *ptr, size_t size)
{
	size_t	i;
	char	*str;

	if (size == 0)
		return ;
	i = 0;
	str = ptr;
	while (i < size)
	{
		str[i] = 0;
		i++;
	}
}

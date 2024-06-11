/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheelim <cheelim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:27:29 by cheelim           #+#    #+#             */
/*   Updated: 2024/06/10 16:45:50 by cheelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lst_ptr;

	if (!lst || !del)
		return ;
	else
	{
		while (*lst)
		{
			lst_ptr = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = lst_ptr;
		}
		lst = NULL;
	}
}

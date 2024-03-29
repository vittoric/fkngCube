/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarrod < alvarrod@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:15:26 by alvarrod          #+#    #+#             */
/*   Updated: 2022/09/15 12:43:08 by alvarrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*pn;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		pn = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = pn;
	}
}

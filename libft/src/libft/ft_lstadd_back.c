/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarrod < alvarrod@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 02:31:21 by alvarrod          #+#    #+#             */
/*   Updated: 2022/09/14 02:48:18 by alvarrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*pn;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	pn = *lst;
	while (pn->next)
	{
		pn = pn->next;
	}
	pn->next = new;
	return ;
}

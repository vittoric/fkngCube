/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarrod <alvarrod@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:41:32 by alvarrod          #+#    #+#             */
/*   Updated: 2022/09/18 15:22:26 by alvarrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_ch;
	t_list	*pn;

	if (!lst)
		return (0);
	lst_ch = ft_lstnew(f(lst->content));
	if (!lst_ch)
		return (0);
	lst = lst->next;
	while (lst)
	{
		pn = ft_lstnew(f(lst->content));
		if (!pn)
		{
			ft_lstclear(&lst_ch, del);
			return (0);
		}
		ft_lstadd_back(&(lst_ch), pn);
		lst = lst->next;
	}	
	return (lst_ch);
}

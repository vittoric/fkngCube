/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarrod < alvarrod@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 02:27:08 by alvarrod          #+#    #+#             */
/*   Updated: 2022/09/14 02:30:11 by alvarrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*pn;

	if (!lst)
		return (0);
	pn = lst;
	while (pn->next)
	{
		pn = pn->next;
	}
	return (pn);
}

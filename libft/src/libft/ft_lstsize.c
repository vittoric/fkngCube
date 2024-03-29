/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarrod < alvarrod@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 02:21:40 by alvarrod          #+#    #+#             */
/*   Updated: 2022/09/14 02:25:34 by alvarrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*pn;
	int		counter;

	if (!lst)
		return (0);
	counter = 1;
	pn = lst->next;
	while (pn)
	{
		counter++;
		pn = pn->next;
	}
	return (counter);
}

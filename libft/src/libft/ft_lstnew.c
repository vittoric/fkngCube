/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarrod <a.rr02_cuentas@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 02:03:52 by alvarrod          #+#    #+#             */
/*   Updated: 2023/07/10 17:39:27 by alvarrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*pn;

	if (!content)
		return (NULL);
	pn = (t_list *) malloc(sizeof(t_list));
	if (!pn)
		return (NULL);
	pn->content = content;
	pn->next = NULL;
	return (pn);
}

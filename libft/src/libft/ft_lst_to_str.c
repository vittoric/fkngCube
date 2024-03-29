/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarrod <a.rr02_cuentas@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:32:37 by alvarrod          #+#    #+#             */
/*   Updated: 2023/07/10 17:33:20 by alvarrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_lst_to_str(t_list **token_list)
{
	t_list	*aux;
	int		i;
	char	**array;

	array = malloc(sizeof(char *) * (ft_lstsize(*token_list) + 1));
	if (!array)
		return (NULL);
	aux = *token_list;
	i = 0;
	while (aux != NULL)
	{
		array[i++] = ft_strdup(aux->content);
		if (!array[i - 1])
		{
			ft_free_str_arr(array);
			return (NULL);
		}
		aux = aux->next;
	}
	array[i] = NULL;
	return (array);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_double_pointer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarrod <a.rr02_cuentas@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:23:09 by alvarrod          #+#    #+#             */
/*   Updated: 2023/11/06 22:07:24 by alvarrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	**ft_init_double_pointer(size_t size_of_struct, size_t number_of_elems, \
void *(*init_elem)(), void (free_funct)(void *))
{
	void	**new_ptr;
	size_t	i;

	new_ptr = malloc(size_of_struct * number_of_elems);
	if (!new_ptr)
		return (NULL);
	i = 0;
	while (i < number_of_elems)
	{
		new_ptr[i] = init_elem();
		if (!new_ptr[i])
		{
			ft_free_double_void_pointer(new_ptr, \
			number_of_elems, free_funct);
			return (NULL);
		}
		i++;
	}
	return (new_ptr);
}

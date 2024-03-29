/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_double_void_pointer.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarrod <a.rr02_cuentas@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:07:44 by alvarrod          #+#    #+#             */
/*   Updated: 2023/11/08 18:44:15 by alvarrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/**
 * @brief Function used to free a double void ** of size size
 * The function makes sure that the pointer can be freed so no double
 * frees are posible
 * 
 * @param ptr Pointer to be freed
 * @param size size of the pointer
 * @param funct function to free the each element
 */
void	ft_free_double_void_pointer(void **ptr, int size, void (*funct)(void *))
{
	int	i;

	i = 0;
	if (!ptr)
		return ;
	while (i < size)
	{
		if (ptr[i])
		{
			funct(ptr[i]);
			ptr[i] = NULL;
		}
		i++;
	}
	free(ptr);
	ptr = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarrod <a.rr02_cuentas@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:53:53 by alvarrod          #+#    #+#             */
/*   Updated: 2023/07/17 16:13:10 by alvarrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*alloc_new_pointer(size_t size)
{
	char	*new_ptr;

	new_ptr = (char *) malloc(sizeof(char) * size);
	if (!new_ptr)
		return (NULL);
	ft_bzero(new_ptr, size);
	return (new_ptr);
}

char	*ft_realloc_str(char *ptr, size_t size)
{
	char	*new_ptr;
	size_t	old_size;

	if (ptr == NULL)
		return (alloc_new_pointer(size));
	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = (char *) malloc((size + 1) * sizeof(char));
	if (new_ptr != NULL)
	{
		ft_bzero(new_ptr, size + 1);
		new_ptr[0] = '\0';
		old_size = ft_strlen(ptr);
		if (old_size < size)
			ft_strncpy(new_ptr, ptr, old_size);
		else
			ft_strncpy(new_ptr, ptr, size);
		free(ptr);
	}
	return (new_ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarrod <a.rr02_cuentas@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:47:01 by alvarrod          #+#    #+#             */
/*   Updated: 2023/11/06 16:42:40 by alvarrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	size_src;
	unsigned int	size_dest;
	unsigned int	i;

	i = 0;
	size_src = 0;
	size_dest = 0;
	while (dest[size_dest])
		size_dest++;
	while (src[size_src])
		size_src++;
	if (size == 0)
	{
		return (size_src);
	}
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (size_src);
}

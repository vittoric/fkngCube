/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarrod <alvarrod@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:44:07 by alvarrod          #+#    #+#             */
/*   Updated: 2022/09/19 13:50:42 by alvarrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	size_dest;
	unsigned int	size_src;
	unsigned int	counter;
	unsigned int	counter_2;

	size_src = ft_strlen(src);
	if (!dest && size == 0)
		return (0);
	size_dest = ft_strlen(dest);
	if (size == 0)
		return (size_src);
	if (size_dest >= size)
		return (size + size_src);
	counter = size_dest;
	counter_2 = 0;
	while (counter < size - 1 && src[counter_2])
	{
		dest[counter] = src[counter_2];
		counter++;
		counter_2++;
	}
	dest[counter] = '\0';
	return (size_dest + size_src);
}

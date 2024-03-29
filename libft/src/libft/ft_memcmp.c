/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarrod <alvarrod@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 01:43:17 by alvarrod          #+#    #+#             */
/*   Updated: 2022/09/18 14:07:02 by alvarrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	counter;
	char	*src;
	char	*dest;

	src = (char *) s1;
	dest = (char *) s2;
	counter = 0;
	if (n == 0)
		return (0);
	while ((counter + 1) < n)
	{
		if (src[counter] != dest[counter])
		{
			return ((unsigned char)src[counter] - (unsigned char)dest[counter]);
		}
		counter++;
	}
	return ((unsigned char)src[counter] - (unsigned char)dest[counter]);
}

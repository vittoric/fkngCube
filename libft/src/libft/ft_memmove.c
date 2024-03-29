/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarrod < alvarrod@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:48:22 by alvarrod          #+#    #+#             */
/*   Updated: 2022/09/15 11:42:19 by alvarrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int		i;
	size_t	k;

	i = n;
	if (n == 0 || src == dest)
		return (dest);
	if (dest - src > 0 && dest - src < (int)n)
	{
		while (i > 0)
		{
			*((char *)dest + i - 1) = *((char *)src + i - 1);
			i--;
		}
		return (dest);
	}
	else
	{
		k = 0;
		while (k < n)
		{
			*((char *)dest + k) = *((char *)src + k);
			k++;
		}
		return (dest);
	}
}

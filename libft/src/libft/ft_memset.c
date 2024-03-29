/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarrod < alvarrod@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:29:01 by alvarrod          #+#    #+#             */
/*   Updated: 2022/09/14 00:36:36 by alvarrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*src;	
	size_t	i;

	i = 0;
	src = (char *) s;
	while (i < n)
	{
		src[i] = c;
		i++;
	}
	return (s);
}

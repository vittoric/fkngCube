/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarrod <alvarrod@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 18:01:49 by alvarrod          #+#    #+#             */
/*   Updated: 2022/09/18 17:18:35 by alvarrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	flag;

	i = 0;
	flag = -1;
	if (c == '\0')
	{
		while (s[i])
			i++;
		return ((char *)(s + i));
	}
	while (s[i])
	{
		if ((unsigned char) s[i] == (unsigned char) c)
			flag = i;
		i++;
	}
	if (flag != -1)
		return ((char *)(s + flag));
	return (0);
}

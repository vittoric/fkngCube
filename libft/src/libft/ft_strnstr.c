/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarrod <alvarrod@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:07:45 by alvarrod          #+#    #+#             */
/*   Updated: 2022/09/18 17:22:31 by alvarrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_substring(const char *big, const char *little, \
size_t counter, size_t counter_2)
{
	while (little[counter_2])
	{
		if (big[counter + counter_2] != little[counter_2])
		{
			return (1);
		}
		counter_2++;
	}
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	counter;
	size_t	counter_2;
	size_t	length_lil;
	int		flag;

	counter = 0;
	length_lil = ft_strlen(little);
	counter_2 = 0;
	flag = 0;
	if (little[0] == '\0' || (!big && len == 0) || \
	(ft_strncmp((char *)big, (char *)little, length_lil) == 0))
		return ((char *) big);
	while (big[counter] && counter + length_lil <= len)
	{
		if (big[counter] == little[counter_2])
		{
			flag = ft_check_substring(big, little, counter, counter_2);
			if (flag == 0)
				return ((char *) big + counter);
			flag = 0;
			counter_2 = 0;
		}
		counter++;
	}
	return (0);
}

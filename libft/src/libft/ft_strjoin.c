/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarrod <alvarrod@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:25:42 by alvarrod          #+#    #+#             */
/*   Updated: 2022/09/18 17:52:05 by alvarrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;	
	size_t	tam;
	size_t	tam2;

	if (!s2 || !s1)
		return (0);
	tam = ft_strlen(s1) + ft_strlen(s2);
	ret = (char *) malloc(sizeof(char) * (tam + 1));
	if (!ret)
		return (0);
	tam = 0;
	while (s1[tam])
	{
		ret[tam] = s1[tam];
		tam++;
	}
	tam2 = 0;
	while (s2[tam2])
	{
		ret[tam] = s2[tam2];
		tam2++;
		tam++;
	}
	ret[tam] = '\0';
	return (ret);
}

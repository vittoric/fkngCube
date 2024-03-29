/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarrod <alvarrod@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:28:13 by alvarrod          #+#    #+#             */
/*   Updated: 2022/09/18 17:56:49 by alvarrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_char(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_allocate_null(void)
{
	char	*ret;

	ret = (char *) malloc(sizeof(char));
	ret[0] = '\0';
	return (ret);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		init;
	int		final;
	char	*cut;
	int		counter;

	if (!s1 || !set)
		return (0);
	counter = 0;
	init = 0;
	final = ft_strlen(s1) - 1;
	while (s1[init] && ft_check_char(s1[init], set))
		init++;
	if (init >= final)
		return (ft_allocate_null());
	while (s1[final] && ft_check_char(s1[final], set))
		final--;
	cut = (char *) malloc(sizeof(char) *(final - init + 2));
	if (!cut)
		return (0);
	while (init <= final)
		cut[counter++] = s1[init++];
	cut[counter] = '\0';
	return (cut);
}

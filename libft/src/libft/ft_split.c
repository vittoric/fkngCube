/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarrod <alvarrod@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:28:06 by alvarrod          #+#    #+#             */
/*   Updated: 2022/09/19 14:07:44 by alvarrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_allocate_null(int flag, int count, char **s)
{
	char	**ret;
	int		i;

	i = 0;
	if (flag == 1)
	{
		while (i < count)
		{
			free(s[i]);
		}
		i++;
		free(s);
	}
	ret = (char **) malloc(sizeof(char *));
	if (!ret)
		return (0);
	ret[0] = 0;
	return (ret);
}

static char	*ft_create_word(char const *s, char c)
{
	int		i;
	int		len;
	char	*word;

	i = 0;
	len = 0;
	while (s[len] != c && s[len])
		len++;
	if (len == 0)
		return ("");
	word = (char *) malloc(sizeof(char) * len + 1);
	if (!word)
		return (0);
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**ft_create_split(char const *s, char c, int words)
{
	char	**res;
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (!s[0])
		return (ft_allocate_null(0, 0, 0));
	res = (char **) malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (0);
	while (count < words)
	{
		res[count] = ft_create_word(s + i, c);
		if (!res[count])
			return (ft_allocate_null(1, count, res));
		while (s[i] != c && s[i])
			i++;
		while (s[i] == c)
			i++;
		count++;
	}
	res[count] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	int	words;
	int	i;
	int	flag;
	int	delim;

	flag = 0;
	i = 0;
	delim = 0;
	words = 1;
	if (!s)
		return (0);
	while (s[delim] == c && s[delim])
		delim++;
	while (s[i + delim])
	{
		if (s[i + delim] == c)
			flag = 1;
		else if (flag == 1)
		{
			flag = 0;
			words++;
		}
		i++;
	}
	return (ft_create_split(s + delim, c, words));
}

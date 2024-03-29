/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarrod <alvarrod@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:57:32 by alvarrod          #+#    #+#             */
/*   Updated: 2022/09/18 17:59:17 by alvarrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_get_substr(char const *s, size_t len)
{
	char	*ret;
	size_t	i;
	size_t	real_len;

	real_len = ft_strlen(s);
	if (real_len < len)
		len = real_len;
	ret = (char *) malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	i = 0;
	while (s[i] && i < len)
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

static char	*ft_allocate_null(void)
{
	char	*ret;

	ret = (char *) malloc(sizeof(char));
	ret[0] = '\0';
	return (ret);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;	
	int				flag;

	i = 0;
	flag = 1;
	if (!s || start >= ft_strlen(s))
		return (ft_allocate_null());
	while (s[i])
	{
		if (i == start)
		{
			flag = -1;
			break ;
		}
		i++;
	}
	if (flag == 1)
		return (ft_allocate_null());
	return (ft_get_substr(s + i, len));
}

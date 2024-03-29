/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarrod <a.rr02_cuentas@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:09:42 by arr02             #+#    #+#             */
/*   Updated: 2023/11/06 15:11:45 by alvarrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_gnl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

t_boolean	str_has_char(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (FALSE);
	if (c == '\0')
		return (TRUE);
	while (str[i])
	{
		if (str[i] == c)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	if (!s2)
	{
		s2 = (char *) malloc(sizeof(char));
		s2[0] = '\0';
	}
	if (!s1 || !2)
		return (NULL);
	i = -1;
	j = 0;
	new = malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (!new)
		return (NULL);
	while (s2[++i])
		new[i] = s2[i];
	while (s1[j])
		new[i++] = s1[j++];
	new[i] = '\0';
	free(s2);
	return (new);
}

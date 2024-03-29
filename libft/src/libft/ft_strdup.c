/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarrod <a.rr02_cuentas@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 01:49:12 by alvarrod          #+#    #+#             */
/*   Updated: 2023/07/05 13:50:31 by alvarrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		counter;

	if (!s)
		return (NULL);
	counter = 0;
	while (s[counter])
			counter++;
	dest = (char *) malloc(sizeof (char) * counter + 1);
	if (!dest)
		return (0);
	counter = 0;
	while (s[counter])
	{
		dest[counter] = s[counter];
		counter++;
	}
	dest[counter] = '\0';
	return (dest);
}

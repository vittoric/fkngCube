/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarrod <a.rr02_cuentas@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:22:42 by alvarrod          #+#    #+#             */
/*   Updated: 2023/07/03 13:52:54 by alvarrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strncpy(char *destination, const char *source, size_t num)
{
	char	*dest;

	dest = destination;
	while (num > 0 && *source != '\0')
	{
		*dest = *source;
		dest++;
		source++;
		num--;
	}
	while (num > 0)
	{
		*dest = '\0';
		dest++;
		num--;
	}
	*dest = '\0';
	return (destination);
}

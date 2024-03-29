/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rm_char_from_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarrod <a.rr02_cuentas@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:35:01 by alvarrod          #+#    #+#             */
/*   Updated: 2023/11/08 19:56:26 by alvarrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_rm_char_from_str(char *str, char c)
{
	char	*dest;

	if (!str)
		return ;
	dest = str;
	while (*str)
	{
		if (*str != c)
		{
			*dest = *str;
			dest++;
		}
		str++;
	}
	*dest = '\0';
}

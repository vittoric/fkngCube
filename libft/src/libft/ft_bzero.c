/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarrod <a.rr02_cuentas@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:37:31 by alvarrod          #+#    #+#             */
/*   Updated: 2023/07/07 12:15:11 by alvarrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*src;
	size_t	i;

	if (!s)
		return ;
	src = (char *) s;
	i = 0;
	while (i < n)
	{
		src[i] = 0;
		i++;
	}
}

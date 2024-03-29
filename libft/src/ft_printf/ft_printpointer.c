/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarrod <alvarrod@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:52:52 by arr02             #+#    #+#             */
/*   Updated: 2022/10/15 12:44:28 by alvarrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printpointer(unsigned long long x)
{
	long	dir;
	char	*pointer;
	int		i;
	int		len;

	i = 0;
	len = 0;
	dir = (unsigned long long) x;
	if (x <= 0)
	{
		write(1, "0x0", 3);
		return (3);
	}
	pointer = ft_dec_to_hexa(dir, 0);
	write(1, "0", 1);
	write(1, "x", 1);
	len += 2;
	while (pointer[i])
	{
		write (1, &pointer[i], 1);
		len++;
		i++;
	}
	free(pointer);
	return (len);
}

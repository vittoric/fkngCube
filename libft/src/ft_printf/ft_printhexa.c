/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarrod <alvarrod@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:18:34 by arr02             #+#    #+#             */
/*   Updated: 2022/10/15 12:50:19 by alvarrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhexa(unsigned long long hexa, int flag)
{
	long	dir;
	char	*pointer;
	int		i;
	int		len;

	i = 0;
	len = 0;
	dir = (unsigned long long) hexa;
	if (flag == 0)
		pointer = ft_dec_to_hexa(dir, 0);
	else
		pointer = ft_dec_to_hexa(dir, 1);
	if (!pointer)
		return (0);
	while (pointer[i])
	{
		write (1, &pointer[i], 1);
		len++;
		i++;
	}
	free(pointer);
	return (len);
}

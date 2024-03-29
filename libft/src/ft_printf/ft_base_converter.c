/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_converter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arr02 <arr02@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:12:25 by arr02             #+#    #+#             */
/*   Updated: 2022/10/05 16:53:27 by arr02            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_length(unsigned long long d)
{
	unsigned long long	dec;
	int					counter;

	counter = 1;
	dec = 16;
	while (d >= dec)
	{
		d /= 16;
		counter++;
	}
	return (counter);
}

char	*ft_dec_to_hexa(unsigned long long d, int flag)
{
	char		*num_in_hexa;
	int			len;
	char		*hexax;
	char		*hexa_xx;
	int			extra;

	hexax = "0123456789abcdef";
	hexa_xx = "0123456789ABCDEF";
	len = ft_hex_length(d);
	num_in_hexa = (char *) malloc(sizeof(char) * len + 1);
	num_in_hexa[len] = '\0';
	while (len != 0)
	{
		extra = d % 16;
		if (flag == 0)
			num_in_hexa[len - 1] = hexax[extra];
		else
			num_in_hexa[len - 1] = hexa_xx[extra];
		d = d / 16;
		len--;
	}
	return (num_in_hexa);
}

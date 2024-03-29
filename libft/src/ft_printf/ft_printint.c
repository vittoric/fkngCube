/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arr02 <arr02@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:52:07 by arr02             #+#    #+#             */
/*   Updated: 2022/10/05 17:01:40 by arr02            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(char c, int *len)
{
	*(len) += 1;
	write(1, &c, 1);
}

static int	ft_calculate_z(int nb)
{
	int	bool;
	int	z;

	bool = 0;
	z = 1;
	while (bool == 0)
	{
		if (nb / z < 10)
		{
			bool = 1;
		}
		else
		{
			z *= 10;
		}
	}
	return (z);
}

static int	ft_is_negative_or_overflow(int nb, int *len)
{
	if (nb == -2147483648)
	{
		ft_putchar('-', len);
		ft_putchar('2', len);
		return (147483648);
	}
	else if (nb < 0)
	{	
		ft_putchar('-', len);
		return (nb * -1);
	}
	return (nb);
}

static int	ft_putint(int n)
{
	int		x;
	int		z;
	int		bool;
	char	k;
	int		len;

	len = 0;
	if (n > 2147483647)
		return (0);
	n = ft_is_negative_or_overflow(n, &len);
	z = ft_calculate_z(n);
	bool = 0;
	while (bool != 1)
	{
		x = n / z;
		n = n % z;
		k = x + '0';
		ft_putchar(k, &len);
		if (z == 1)
			bool = 1;
		else
			z /= 10;
	}
	return (len);
}

int	ft_printint(int n)
{
	return (ft_putint(n));
}

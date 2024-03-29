/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarrod <alvarrod@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:50:13 by alvarrod          #+#    #+#             */
/*   Updated: 2022/09/18 15:11:33 by alvarrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
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

static int	ft_is_negative_or_overflow(int nb, int fd)
{
	if (nb == -2147483648)
	{
		ft_putchar('-', fd);
		ft_putchar('2', fd);
		return (147483648);
	}
	else if (nb < 0)
	{	
		ft_putchar('-', fd);
		return (nb * -1);
	}
	return (nb);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		x;
	int		y;
	int		z;
	int		bool;
	char	k;

	if (n > 2147483647)
	{
		return ;
	}
	n = ft_is_negative_or_overflow(n, fd);
	z = ft_calculate_z(n);
	bool = 0;
	while (bool != 1)
	{
		x = n / z;
		y = n % z;
		n = y;
		k = x + '0';
		ft_putchar(k, fd);
		if (z == 1)
			bool = 1;
		else
			z /= 10;
	}
}

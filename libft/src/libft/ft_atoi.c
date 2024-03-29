/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarrod <alvarrod@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 02:50:33 by alvarrod          #+#    #+#             */
/*   Updated: 2022/09/18 15:09:54 by alvarrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	ft_get_number(const char *str)
{
	int			counter;
	double		mult;
	long int	number;
	long int	extra;

	mult = 0.1;
	counter = 0;
	extra = 0;
	number = 0;
	while (str[counter] > 47 && str[counter] < 58)
	{
		counter++;
		mult *= 10;
	}
	counter = 0;
	while (str[counter] > 47 && str[counter] < 58)
	{
		extra = (str[counter] - 48) * mult;
		number += extra;
		counter++;
		mult /= 10;
	}
	return (number);
}

static long int	ft_find_number(const char *str)
{
	long int	number;
	int			counter;
	int			signo ;

	signo = 1;
	counter = 0;
	number = 0;
	if (str[counter] == 45)
	{
		signo *= -1;
		number = ft_get_number(str + counter + 1);
	}
	else if (str[counter] == 43)
		number = ft_get_number(str + counter + 1);
	else if (str[counter] >= '0' && str[counter] <= '9')
		number = ft_get_number(str + counter);
	else
		return (0);
	number *= signo;
	return (number);
}

static int	ft_check_space(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == '\n' || str[i] == '\f' || \
	str[i] == '\r' || str[i] == '\t' || str[i] == '\v' || str[i] == ' ')
		i++;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	long int	number;
	int			spaces;

	spaces = ft_check_space(nptr);
	number = ft_find_number(nptr + spaces);
	if (number > 2147483647)
		return (2147483647);
	if (number < -2147483648)
		return (-2147483648);
	return ((int)(number));
}

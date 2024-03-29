/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arr02 <arr02@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:54:40 by arr02             #+#    #+#             */
/*   Updated: 2022/10/05 14:22:43 by arr02            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_calculate_length( unsigned int n)
{
	double	dec;
	int		counter;

	counter = 0;
	dec = 1;
	while (n / dec >= 1)
	{
		counter++;
		dec *= 10;
	}
	return (counter);
}

static char	*ft_uitoa(unsigned int u)
{
	char	*num_in_char;
	int		len;
	int		extra;

	len = ft_calculate_length(u);
	num_in_char = (char *) malloc(sizeof(char) * (len + 1));
	if (!num_in_char)
		return (0);
	num_in_char[len] = 0;
	len--;
	while (len != -1)
	{
		extra = u % 10;
		extra += 48;
		num_in_char[len] = extra;
		u = u / 10;
		len--;
	}
	return (num_in_char);
}

int	ft_printunint(unsigned int u)
{
	int		len;
	char	*num;

	len = 0;
	if (u == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	num = ft_uitoa(u);
	if (!num)
		return (0);
	while (num[len])
	{
		write(1, &num[len], 1);
		len++;
	}
	free(num);
	return (len);
}

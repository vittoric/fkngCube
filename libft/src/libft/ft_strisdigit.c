/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarrod <a.rr02_cuentas@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:33:00 by arr02             #+#    #+#             */
/*   Updated: 2023/11/06 21:41:22 by alvarrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_space(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == '\n' || str[i] == '\f' || \
	str[i] == '\r' || str[i] == '\t' || str[i] == '\v' || str[i] == ' ')
		i++;
	return (i);
}

int	ft_strisdigit(char *str)
{
	int	i;
	int	flag;

	i = 0;
	i = ft_check_space(str);
	flag = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		flag = 1;
		if (ft_isspace(str[i]))
			return (1);
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (flag == 0)
		return (0);
	return (1);
}

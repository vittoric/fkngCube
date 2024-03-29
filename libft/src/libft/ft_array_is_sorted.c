/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_is_sorted.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarrod <a.rr02_cuentas@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 00:33:13 by arr02             #+#    #+#             */
/*   Updated: 2023/11/06 15:10:04 by alvarrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

t_status	ft_array_is_sorted(int *array, int len, int desc)
{
	int	i;

	i = 0;
	if (desc == 0)
	{
		while (i < len - 1)
		{
			if (array[i] > array[i + 1])
				return (GENERAL_ERROR);
			i++;
		}
	}
	else
	{
		while (i < len - 1)
		{
			if (array[i] < array[i + 1])
				return (GENERAL_ERROR);
			i++;
		}
	}
	return (SUCCESS);
}

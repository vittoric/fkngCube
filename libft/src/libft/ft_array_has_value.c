/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_has_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arr02 <arr02@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:46:47 by arr02             #+#    #+#             */
/*   Updated: 2022/12/27 00:44:19 by arr02            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_array_has_value(int *arr, int value, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (arr[i] == value)
			return (1);
		i++;
	}
	return (0);
}
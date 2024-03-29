/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 08:01:09 by alaparic          #+#    #+#             */
/*   Updated: 2023/09/20 11:15:32 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Checks all values of a string to verify they are numeric.
 * Return 1 if true and 0 if false.
*/
int	ft_strisnum(char *c)
{
	while (*c)
	{
		if (*c < 48 || *c > 57)
			return (0);
		c++;
	}
	return (1);
}

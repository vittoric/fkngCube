/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarrod <a.rr02_cuentas@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:43:43 by alvarrod          #+#    #+#             */
/*   Updated: 2023/11/08 20:20:44 by alvarrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/**
 * @brief Standard message of error
 * 
 * @param error the message
 */
void	show_error(char *error)
{
	write(2, "Error\n", 7);
	write(2, error, ft_strlen(error));
	write(2, "\n", 1);
	return ;
}

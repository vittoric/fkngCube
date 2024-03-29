/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarrod <a.rr02_cuentas@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:34:16 by arr02             #+#    #+#             */
/*   Updated: 2023/11/06 14:52:40 by alvarrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef enum s_boolean{
	FALSE,
	TRUE
}	t_boolean;

typedef enum s_status{
	SUCCESS,
	GENERAL_ERROR,
	FILE_NOT_FOUND,
	INSUFFICIENT_PERMISSIONS,
	INVALID_COMMAND,
	INPUT_DATA_FORMAT_ERROR,
	MALLOC_ERROR
}	t_status;
#endif
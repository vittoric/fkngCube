/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarrod <a.rr02_cuentas@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:09:20 by arr02             #+#    #+#             */
/*   Updated: 2023/11/06 21:41:55 by alvarrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "types.h"
# define BUFFER_SIZE 10

t_boolean	str_has_char(char *str, char c);
char		*ft_strjoin_gnl(char *s1, char *s2);
char		*get_next_line(int fd);
#endif
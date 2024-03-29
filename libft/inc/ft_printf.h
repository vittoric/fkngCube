/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarrod <a.rr02_cuentas@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:24:18 by arr02             #+#    #+#             */
/*   Updated: 2023/11/06 15:08:04 by alvarrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include<stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "types.h"

int		ft_printunint(unsigned int u);
int		ft_printf(char const *format, ...);
int		ft_printstring(char *s);
int		ft_printint(int n);
int		ft_printhexa(unsigned long long n, int flag);
int		ft_printchar(char c);
int		ft_printpointer(unsigned long long x);
char	*ft_dec_to_hexa(unsigned long long decimal, int flag);
#endif

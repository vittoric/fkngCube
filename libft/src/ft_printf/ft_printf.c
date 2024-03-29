/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarrod <a.rr02_cuentas@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:59:17 by arr02             #+#    #+#             */
/*   Updated: 2023/11/06 15:08:49 by alvarrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printall(va_list args, char c)
{
	if (c == 'c')
		return (ft_printchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_printstring(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_printpointer(va_arg(args, unsigned long long)));
	else if (c == 'd' || c == 'i')
		return (ft_printint(va_arg(args, int)));
	else if (c == 'u')
		return (ft_printunint(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_printhexa(va_arg(args, unsigned int), 0));
	else if (c == 'X')
		return (ft_printhexa(va_arg(args, unsigned int), 1));
	else if (c == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (GENERAL_ERROR);
}

int	ft_printf(char const *format, ...)
{
	va_list	ptr;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(ptr, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_printall(ptr, format[i + 1]);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			len++;
		}
		i++;
	}	
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarrod <alvarrod@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 11:36:41 by alvarrod          #+#    #+#             */
/*   Updated: 2022/09/18 18:14:49 by alvarrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_calculate_length(int n)
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

static char	*ft_get_itoa(int n, float dec, size_t length, int signo)
{
	int		extra;
	char	ascii_char;
	char	*num;
	int		i;

	i = 0;
	num = (char *) malloc(sizeof(char) * length);
	if (!num)
		return (0);
	if (signo == -1)
	{
		num[0] = '-';
		i++;
	}
	while (dec >= 1)
	{
		extra = n / dec;
		n = n % (int) dec;
		ascii_char = (char) extra + 48;
		dec /= 10;
		num[i] = ascii_char;
		i++;
	}	
	num[i] = '\0';
	return (num);
}

static char	*ft_prepare_itoa(int n, size_t length, int signo)
{
	float	dec;

	dec = 1;
	while (n / dec >= 1)
		dec *= 10;
	dec /= 10;
	return (ft_get_itoa(n, dec, length, signo));
}

static char	*malloc_ret(int n)
{
	char	*str;

	if (n == -2147483648)
	{
		str = (char *) malloc(sizeof(char) * 12);
		ft_strlcpy(str, "-2147483648", 12);
		return (str);
	}
	if (n == 0)
	{
		str = (char *) malloc(sizeof(char) * 2);
		ft_strlcpy(str, "0", 2);
		return (str);
	}
	return (0);
}

char	*ft_itoa(int n)
{
	size_t	length;
	int		signo;	
	char	*str;

	signo = 1;
	length = 1;
	if (n == -2147483648)
		return (malloc_ret(n));
	if (n == 0)
		return (malloc_ret(n));
	if (n < 0)
	{
		n *= -1;
		length += 1;
		signo = -1;
	}
	length += ft_calculate_length(n);
	str = ft_prepare_itoa(n, length, signo);
	return (str);
}

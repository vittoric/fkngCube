/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarrod <a.rr02_cuentas@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:09:11 by arr02             #+#    #+#             */
/*   Updated: 2023/11/06 20:35:58 by alvarrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_new_contenedor(char **contenedor, int tam)
{
	int		i;
	char	*new_contenedor;

	if (!contenedor)
		return ;
	if (!(*contenedor)[tam])
	{
		free(*contenedor);
		*contenedor = NULL;
		return ;
	}
	i = 0;
	while ((*contenedor)[i + tam])
		i++;
	new_contenedor = (char *) malloc(sizeof(char) * (i + 1));
	if (!new_contenedor)
		return ;
	i = -1;
	while ((*contenedor)[++i + tam])
		new_contenedor[i] = (*contenedor)[i + tam];
	new_contenedor[i] = '\0';
	free(*contenedor);
	*contenedor = new_contenedor;
}

char	*ft_get_line_end(char *contenedor, int fd)
{
	ssize_t		bytes_leidos;
	char		*buffer;

	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_leidos = BUFFER_SIZE;
	while (!str_has_char(contenedor, '\n') && bytes_leidos == BUFFER_SIZE)
	{
		bytes_leidos = read(fd, buffer, BUFFER_SIZE);
		if (bytes_leidos <= 0 && !contenedor)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_leidos] = '\0';
		contenedor = ft_strjoin_gnl(buffer, contenedor);
		if (!contenedor)
		{
			free(contenedor);
			return (NULL);
		}
	}
	free(buffer);
	return (contenedor);
}

char	*ft_get_line(char **contenedor)
{
	int		i;
	int		tam;
	char	*line;

	i = 0;
	tam = 0;
	if (!(*contenedor))
		return (NULL);
	while ((*contenedor)[tam] && (*contenedor)[tam] != '\n')
		tam++;
	line = (char *) malloc(sizeof(char) * (tam + 2));
	if (!line)
		return (NULL);
	while ((*contenedor)[i] && (*contenedor)[i] != '\n')
	{
		line[i] = (*contenedor)[i];
		i++;
	}
	if ((*contenedor)[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	ft_new_contenedor(contenedor, i);
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*contenedor[5000];
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	contenedor[fd] = ft_get_line_end(contenedor[fd], fd);
	if (!contenedor[fd])
		return (NULL);
	line = ft_get_line(&contenedor[fd]);
	return (line);
}

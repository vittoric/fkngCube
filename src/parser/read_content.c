/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:21:28 by alvarrod          #+#    #+#             */
/*   Updated: 2024/03/29 14:54:29 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

static void	check_extension(char **argv)
{
	char	*file_ext;

	file_ext = ft_strrchr(argv[1], '.');
	if (!file_ext || ft_strncmp(file_ext + 1, "cub", ft_strlen(argv[1])) != 0)
		print_error("Invalid extension map ❌ use only '.cub'");
}
static void	check_map_empty_line(char *line)
{
	static unsigned int	count = 0;
	static int			flag_enter = 0;
	static int			flag_exit = 0;

	if (count == 6 && ft_strlen(line) > 1 && !flag_enter)
		flag_enter = 1;
	if (count < 6 && ft_strlen(line) > 1)
		count++;
	if (flag_enter && ft_strlen(line) == 1 && !flag_exit)
		flag_exit++;
	if ((ft_strlen(line) > 1 || *line != '\n') && flag_exit)
		print_error("Empty line in map");
}
static char	*get_lines(int fd)
{
	char	*file;
	char	*line;

	line = get_next_line(fd);
	file = ft_calloc(1, 1);
	if (!file)
		exit(1);
	while (line != NULL)
	{
		check_map_empty_line(line);
		file = ft_fstrjoin(file, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (file);
}

char	**read_content(char **argv)
{
	char	*file;
	int		fd;
	char	**content;

	check_extension(argv);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error("File access error. Check if the file exists ⛔️");
	if (read(fd, 0, 1) == 0)
		print_error("Map file is blank 📁");
	file = get_lines(fd);
	close(fd);
	content = ft_split(file, '\n');
	free(file);
	return (content);
}
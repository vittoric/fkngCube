/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:05:44 by alvarrod          #+#    #+#             */
/*   Updated: 2024/03/29 14:51:08 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	free_value(char **value)
{
	int	i;

	i = 0;
	while (value[i] != NULL)
	{
		free(value[i]);
		i++;
	}
	free(value);
}

static enum e_values	identify_line_value(char *line)
{
	while (*line && (*line == ' ' || *line == '	'))
		line++;
	if (ft_strnstr(line, "NO ", 3) || ft_strnstr(line, "NO	", 3))
		return (NO);
	if (ft_strnstr(line, "SO ", 3) || ft_strnstr(line, "SO	", 3))
		return (SO);
	if (ft_strnstr(line, "WE ", 3) || ft_strnstr(line, "WE	", 3))
		return (WE);
	if (ft_strnstr(line, "EA ", 3) || ft_strnstr(line, "EA	", 3))
		return (EA);
	if (ft_strnstr(line, "F ", 2) || ft_strnstr(line, "F	", 2))
		return (F);
	if (ft_strnstr(line, "C ", 2) || ft_strnstr(line, "C	", 2))
		return (C);
	return (ERROR);
}

static t_color	get_color_value(char *line)
{
	t_color	color;
	char	*aux;
	char	**values;

	color.alpha = 0;
	while (*line && (*line == ' ' || *line == '	'))
		line++;
	line++;
	aux = ft_strtrim(line, " 	");
	if (ft_strlen(aux) == 0)
		print_error("Empty value found for floor or ceiling");
	values = ft_split(aux, ',');
	if (ft_get_matrix_size(values) != 3)
		print_error("Value for colors must be in R,G,B");
	if (!ft_strisnum(values[0]) || !ft_strisnum(values[1])
		|| !ft_strisnum(values[2]))
		print_error("Non numeric value found in floor or ceiling");
	color.red = ft_atoi(values[0]);
	color.green = ft_atoi(values[1]);
	color.blue = ft_atoi(values[2]);
	if (color.red > 255 || color.green > 255 || color.blue > 255
		|| color.red < 0 || color.green < 0 || color.blue < 0)
		print_error("Value for colors must be between 0 and 255");
	(free(aux), free_value(values));
	return (color);
}

static char	*get_texture_value(char *line)
{
	char	*texture_path;

	while (*line && (*line == ' ' || *line == '	'))
		line++;
	line += 2;
	texture_path = ft_strtrim(line, " 	");
	if (!ft_strlen(texture_path))
		print_error("Empty value found for wall textures");
	return (texture_path);
}

void	get_textures(t_game *game, char **file_con)
{
	int				i;
	enum e_values	value_type;

	i = -1;
	while (++i < 6)
	{
		value_type = identify_line_value(file_con[i]);
		if (value_type == ERROR)
			print_error("Invalid value for textures and colors");
		if (value_type == NO)
			game->map_data.texture_no = get_texture_value(file_con[i]);
		else if (value_type == SO)
			game->map_data.texture_so = get_texture_value(file_con[i]);
		else if (value_type == WE)
			game->map_data.texture_we = get_texture_value(file_con[i]);
		else if (value_type == EA)
			game->map_data.texture_ea = get_texture_value(file_con[i]);
		else if (value_type == C)
			game->map_data.ceiling = get_color_value(file_con[i]);
		else if (value_type == F)
			game->map_data.floor = get_color_value(file_con[i]);
	}
}

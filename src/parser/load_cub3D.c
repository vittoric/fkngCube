/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_cub3D.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:21:25 by alvarrod          #+#    #+#             */
/*   Updated: 2024/03/29 14:50:53 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

static int	check_chars(t_game *game, char value, int x, int y)
{
	if (value != '1' && value != '0' && value != 'N'
		&& value != 'S' && value != 'E' && value != 'W' && value != ' ')
		print_error("Invalid value found in map");
	if (value == 'N' || value == 'S' || value == 'E' || value == 'W')
	{
		game->player.y = (x * WALL_SIZE) + WALL_SIZE / 2;
		game->cam.grid_y = y;
		game->player.x = (y * WALL_SIZE) + WALL_SIZE / 2;
		game->cam.grid_x = x;
		return (1);
	}
	return (0);
}

static void	check_map_chars(t_game *game, char **map)
{
	int	x;
	int	y;
	int	player_flag;

	y = -1;
	player_flag = 0;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			player_flag += check_chars(game, map[y][x], x, y);
	}
	if (player_flag > 1)
		print_error("Mutiple players");
	if (!player_flag)
		print_error("Couldn't find the player's position");
}

void	load_cub3D(char **argv, t_game *game)
{
	char	**content;
	char	**map;

	content = read_content(argv);
	get_textures(game, content);
	map = content + 6;
	check_map_chars(game, map);
	check_closed_walls(map);
	game->map = map;
}

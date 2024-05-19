/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_direction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:42:21 by vcodrean          #+#    #+#             */
/*   Updated: 2024/05/19 16:45:44 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

static void	set_player_direction_xy(t_game *game, double dirX, int dirY)
{
	game->player.dir.x = dirX;
	game->player.dir.y = dirY;
}

static void	set_player_direction_pln(t_game *game, double planeX, double planeY)
{
	game->cam.plane.x = planeX;
	game->cam.plane.y = planeY;
}

void	get_player_direction(t_game *game)
{
	char	player_pos;

	player_pos = game->map[(int)game->player.x
		/ WALL_SIZE][(int)game->player.y / WALL_SIZE];
	if (player_pos == 'N')
	{
		set_player_direction_xy(game, -1, 0);
		set_player_direction_pln(game, 0, 0.66);
	}
	else if (player_pos == 'E')
	{
		set_player_direction_xy(game, 0, 1);
		set_player_direction_pln(game, 0.66, 0);
	}
	else if (player_pos == 'W')
	{
		set_player_direction_xy(game, 0, -1);
		set_player_direction_pln(game, -0.66, 0);
	}
	else if (player_pos == 'S')
	{
		set_player_direction_xy(game, 1, 0);
		set_player_direction_pln(game, 0, -0.66);
	}
}

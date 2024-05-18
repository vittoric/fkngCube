/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 02:12:06 by alvarrod          #+#    #+#             */
/*   Updated: 2024/03/29 20:03:48 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

//revisado

static int	check_for_walls(t_game *game)
{
	int	is_wall;

	is_wall = 1;
	if (game->player.old_y < WALL_SIZE || (int)game->player.old_x / WALL_SIZE
		> ft_get_matrix_size(game->map))
		is_wall = 0;
	else if (game->player.old_x < WALL_SIZE || (int)game->player.old_y
		/ WALL_SIZE > (int)ft_strlen(game->map
			[(int)game->player.old_x / WALL_SIZE]))
		is_wall = 0;
	return (is_wall);
}

static void	move_player(t_game *game, double dir_x, double dir_y)
{
	game->player.old_x = game->player.x + dir_x * SPEED;
	game->player.old_y = game->player.y + dir_y * SPEED;
	if (!check_for_walls(game))
		return ;
	if (game->map[(int)game->player.old_x / WALL_SIZE]
		[(int)game->player.y / WALL_SIZE] != '1')
		game->player.x += dir_x * SPEED;
	if (game->map[(int)game->player.x / WALL_SIZE]
		[(int)game->player.old_y / WALL_SIZE] != '1')
		game->player.y += dir_y * SPEED;
}

static void	handle_arows(t_game *game, enum e_keys key)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rot_speed;

	rot_speed = 0.1;
	if (key == RIGHT)
		rot_speed *= -1;
	old_dir_x = game->player.dir.x;
	game->player.dir.x = game->player.dir.x * cos(rot_speed)
		- game->player.dir.y * sin(rot_speed);
	game->player.dir.y = old_dir_x * sin(rot_speed)
		+ game->player.dir.y * cos(rot_speed);
	old_plane_x = game->cam.plane.x;
	game->cam.plane.x = game->cam.plane.x * cos(rot_speed)
		- game->cam.plane.y * sin(rot_speed);
	game->cam.plane.y = old_plane_x * sin(rot_speed)
		+ game->cam.plane.y * cos(rot_speed);
	printf("dir.x: %f\n", game->player.dir.x);
	printf("dir.y: %f\n", game->player.dir.y);
}

int	event_handler(enum e_keys key, t_game *game)
{
	if (key == ESC)
		exit_game(game);
	if (key == LEFT || key == RIGHT)
		handle_arows(game, key);
	else if (key == W || key == UP)
		move_player(game, game->player.dir.x, game->player.dir.y);
	else if (key == S || key == DOWN)
		move_player(game, -game->player.dir.x, -game->player.dir.y);
	else if (key == A)
		move_player(game, -game->player.dir.y, game->player.dir.x);
	else if (key == D)
		move_player(game, game->player.dir.y, -game->player.dir.x);
	re_draw_screen(game);
	return (0);
}

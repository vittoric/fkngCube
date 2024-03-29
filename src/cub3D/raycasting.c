/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:35:31 by vcodrean          #+#    #+#             */
/*   Updated: 2024/03/29 19:54:04 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

//revisado

static void	dda_algorithm(t_game *game)
{
	game->cam.hit = 0;
	while (game->cam.hit == 0)
	{
		if (game->cam.sidedx < game->cam.sidedy)
		{
			game->cam.sidedx += game->cam.dx;
			game->cam.grid_x += game->cam.stepx;
			game->cam.offset = 0;
		}
		else
		{
			game->cam.sidedy += game->cam.dy;
			game->cam.grid_y += game->cam.stepy;
			game->cam.offset = 1;
		}
		if (game->map[game->cam.grid_x][game->cam.grid_y]
			== '1')
			game->cam.hit = 1;
	}
}

static void check_ray_direction(t_game *game)
{
    if (game->cam.raydirx < 0)
        game->cam.stepx = -1;
    else
        game->cam.stepx = 1;

    if (game->cam.raydiry < 0)
        game->cam.stepy = -1;
    else
        game->cam.stepy = 1;

    if (game->cam.raydirx < 0)
        game->cam.sidedx = 
		((game->player.x / WALL_SIZE) - game->cam.grid_x) * game->cam.dx;
    else
        game->cam.sidedx = 
		(game->cam.grid_x + 1 - (game->player.x / WALL_SIZE)) * game->cam.dx;

    if (game->cam.raydiry < 0)
        game->cam.sidedy = 
		((game->player.y / WALL_SIZE) - game->cam.grid_y) * game->cam.dy;
    else
        game->cam.sidedy = 
		(game->cam.grid_y + 1 - (game->player.y / WALL_SIZE)) * game->cam.dy;
}


void	raycasting(t_game *game)
{
	int	x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		game->cam.camerax = (2 * x / (double)SCREEN_WIDTH) - 1;
		game->cam.raydirx = game->player.dir.x
			+ game->cam.plane.x * game->cam.camerax;
		game->cam.raydiry = game->player.dir.y
			+ game->cam.plane.y * game->cam.camerax;
		game->cam.grid_y = game->player.y / WALL_SIZE;
		game->cam.grid_x = game->player.x / WALL_SIZE;
		game->cam.dx = fabs(1 / game->cam.raydirx);
		game->cam.dy = fabs(1 / game->cam.raydiry);
		check_ray_direction(game);
		dda_algorithm(game);
		if (game->cam.offset == 0)
			game->cam.distance = game->cam.sidedx - game->cam.dx;
		else
			game->cam.distance = game->cam.sidedy - game->cam.dy;
		ft_draw_wall(game);
		x++;
	}
}

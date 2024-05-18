/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:31:34 by vcodrean          #+#    #+#             */
/*   Updated: 2024/03/29 19:53:44 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

//revisado

static	void	draw_texture_color(t_game *game, int x, int start)
{
	int	texcolor;

	if (game->cam.texty < 0)
		game->cam.texty *= -1;
	if (game->cam.textx < 0)
		game->cam.textx *= -1;
	if (game->cam.offset == 0 && game->cam.raydirx < 0)
		texcolor = game->textu_n.text_value
		[(int)(WALL_SIZE * game->cam.texty + game->cam.textx)];
	else if (game->cam.offset == 0 && game->cam.raydirx > 0)
		texcolor = game->textu_s.text_value
		[(int)(WALL_SIZE * game->cam.texty + game->cam.textx)];
	else if (game->cam.offset == 1 && game->cam.raydiry < 0)
		texcolor = game->textu_w.text_value
		[(int)(WALL_SIZE * game->cam.texty + game->cam.textx)];
	else
		texcolor = game->textu_e.text_value
		[(int)(WALL_SIZE * game->cam.texty + game->cam.textx)];
	ft_put_pixel(game->img, x, start, texcolor);
}

static void	calculate_hit_pos(t_game *game, int start)
{
	if (game->cam.offset == 0)
		game->cam.wallx = (game->player.y / WALL_SIZE) + game->cam.distance
			* game->cam.raydiry;
	else
		game->cam.wallx = (game->player.x / WALL_SIZE) + game->cam.distance
			* game->cam.raydirx;
	game->cam.wallx -= floor(game->cam.wallx);
	game->cam.textx = (int)(game->cam.wallx * (double)(WALL_SIZE));
	if (game->cam.offset == 0 && game->cam.raydirx > 0)
		game->cam.textx = WALL_SIZE - game->cam.textx - 1;
	if (game->cam.offset == 1 && game->cam.raydiry < 0)
		game->cam.textx = WALL_SIZE - game->cam.textx - 1;
	game->cam.increase = 1.0 * WALL_SIZE / game->cam.lineheight;
	game->cam.textpos = (start - SCREEN_HEIGHT / 2 + game->cam.lineheight
			/ 2) * game->cam.increase;
}

void	ft_draw_wall(t_game *game)
{
	static int	x = 0;
	int			start;
	int			end;

	game->cam.lineheight = (int)(SCREEN_HEIGHT / game->cam.distance);
	start = -game->cam.lineheight / 2 + SCREEN_HEIGHT / 2;
	if (x == SCREEN_WIDTH)
		x = 0;
	if (start < 0)
		start = 0;
	end = SCREEN_HEIGHT / 2 + game->cam.lineheight / 2;
	if (end >= SCREEN_HEIGHT)
		end = SCREEN_HEIGHT - 1;
	calculate_hit_pos(game, start);
	while (start < end)
	{
		game->cam.texty = (int)(game->cam.textpos);
		if (game->cam.texty >= WALL_SIZE)
			game->cam.texty = WALL_SIZE - 1;
		draw_texture_color(game, x, start);
		start++;
		game->cam.textpos += game->cam.increase;
	}
	x++;
}

static void	draw_ceiling_floor(t_game *game, t_color ceiling, t_color floor)
{
	int	y;
	int	x;

	y = -1;
	while (y++ < SCREEN_HEIGHT)
	{
		x = -1;
		while (x++ < SCREEN_WIDTH)
		{
			if (y < SCREEN_HEIGHT / 2)
				ft_put_pixel(game->img, x, y, ft_rgba(ceiling.red,
						ceiling.green, ceiling.blue, 0));
			else
				ft_put_pixel(game->img, x, y, ft_rgba(floor.red, floor.green,
						floor.blue, 0));
		}
	}
}

/**
 * At the start of the game and when any movement key is pressed the screen is
 * re-drawn.
 *
 * First the floor and ceiling is drawn. Half of the screen will be drawn the
 * ceiling colour and the other half will be the floor color, since the walls
 * will be drawn from the middle it'll give the illusion of floor and ceiling.
 *
 * Next Raycasting will do all the necessary calculations to mesure the distance
 * to each wall. That distance will determine the height of each segment of wall
 * and we'll draw them accordingly.
 *
 * Finally the with every pixel placed in the image, it is put on the screen.
*/
void	re_draw_screen(t_game *game)
{
	draw_ceiling_floor(game, game->map_data.ceiling, game->map_data.floor);
	raycasting(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}

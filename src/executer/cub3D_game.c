/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:14:28 by vcodrean          #+#    #+#             */
/*   Updated: 2024/03/29 20:03:40 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

//revisado

static void set_player_direction(t_game *game, double planeX, double planeY, int dirX, int dirY)
{
    game->cam.plane.x = planeX;
    game->cam.plane.y = planeY;
    game->player.dir.x = dirX;
    game->player.dir.y = dirY;
}

static void get_player_direction(t_game *game)
{
    char playerPos = game->map[(int)game->player.x / WALL_SIZE][(int)game->player.y / WALL_SIZE];

    if (playerPos == 'N')
        set_player_direction(game, 0, 0.66, -1, 0);
    else if (playerPos == 'E')
        set_player_direction(game, 0.66, 0, 0, 1);
    else if (playerPos == 'W')
        set_player_direction(game, -0.66, 0, 0, -1);
    else if (playerPos == 'S')
        set_player_direction(game, 0, -0.66, 1, 0);
}

static void	allocate_buffer(t_game *game)
{
	int	i;

	i = 0;
	game->cam.buffer = malloc(WALL_SIZE * sizeof(int *));
	if (!game->cam.buffer)
		exit(1);
	while (i < WALL_SIZE)
	{
		game->cam.buffer[i] = malloc(WALL_SIZE * sizeof(int));
		if (!game->cam.buffer[i])
			exit(1);
		i++;
	}
}

static void	start_img(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bpp,
			&game->img.line_len, &game->img.endian);
}

void	start_game(t_game *game, char *map_name)
{
	char	*aux;

	aux = ft_strjoin(PROGRAM_NAME, map_name);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, aux);
	free(aux);
	start_img(game);
	create_textures(game);
	allocate_buffer(game);
	get_player_direction(game);
	re_draw_screen(game);
	mlx_hook(game->win, 17, 0, exit_game, game);
	mlx_hook(game->win, 2, 1L << 0, event_handler, game);
	mlx_loop(game->mlx);
}

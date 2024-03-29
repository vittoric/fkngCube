/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:51:00 by arr02             #+#    #+#             */
/*   Updated: 2024/03/29 19:02:18 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/inc/ft_printf.h"
# include "../libft/inc/libft.h"
# include "../libft/inc/get_next_line.h"
# include "./structs.h"
# include <mlx.h>
# include <math.h>
# include <time.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

# define PROGRAM_NAME "cub3D - "
# define PI 3.14159265
# define SCREEN_WIDTH 940
# define SCREEN_HEIGHT 780
# define WALL_SIZE 64
# define SPEED 32
# define WALLS 4
# define COLORS 2

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))


/* Enums */

enum e_keys
{
	W = 13,
	A = 0,
	S = 1,
	D = 2,
	UP = 126,
	LEFT = 123,
	DOWN = 125,
	RIGHT = 124,
	ESC = 53
};

/**
 * Representing the type of value found in the file line.
 * If no type is found value will be ERROR
*/
enum e_values
{
	NO,
	SO,
	WE,
	EA,
	F,
	C,
	ERROR
};

void	print_error(char *text);
void	load_cub3D(char **argv, t_game *game);
char	**read_content(char **argv);
void	get_textures(t_game *game, char **file_con);
void	check_closed_walls(char **map);
void	free_value(char **value);
void	start_game(t_game *game, char *map_name);
void	create_textures(t_game *game);
void	re_draw_screen(t_game *game);
void	ft_put_pixel(t_img img, int x, int y, int color);
int		ft_rgba(int r, int g, int b, int alpha);
void	raycasting(t_game *game);
void	ft_draw_wall(t_game *game);
int		exit_game(t_game *game);
int		event_handler(enum e_keys key, t_game *game);
#endif
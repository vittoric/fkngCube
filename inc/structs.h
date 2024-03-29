/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:24:39 by alvarrod          #+#    #+#             */
/*   Updated: 2024/03/28 16:18:26 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
	int	alpha;
}	t_color;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		height;
	int		width;
}	t_img;

typedef struct s_map_data
{
	char	*texture_no;
	char	*texture_so;
	char	*texture_we;
	char	*texture_ea;
	int		max_x;
	int		max_y;
	t_color	floor;
	t_color	ceiling;
}	t_map_data;

/**
 * Player position and direction
*/
typedef struct s_player
{
	float		x;
	float		y;
	float		old_x;
	float		old_y;
	float		camera;
	t_vector	dir;
}	t_player;

typedef struct s_camera
{
	int			hit;
	int			offset;
	int			grid_x;
	int			grid_y;
	int			**buffer;
	float		x;
	float		y;
	float		stepx;
	float		stepy;
	float		camerax;
	float		directionx;
	float		directiony;
	t_vector	plane;
	float		raydirx;
	float		raydiry;
	float		dx;
	float		dy;
	float		sidedx;
	float		sidedy;
	float		distance;
	double		wallx;
	double		wally;
	double		textx;
	double		texty;
	float		lineheight;
	double		increase;
	double		textpos;
}	t_camera;

typedef struct s_texture
{
	t_img	img;
	int		*text_value;
}	t_texture;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	t_map_data	map_data;
	t_img		img;
	t_player	player;
	t_camera	cam;
	t_texture	textu_n;
	t_texture	textu_s;
	t_texture	textu_e;
	t_texture	textu_w;
}	t_game;
#endif
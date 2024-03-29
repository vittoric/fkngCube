/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:02:40 by vcodrean          #+#    #+#             */
/*   Updated: 2024/03/29 19:54:09 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

//revisado

static void	add_info_to_texture(t_texture *texture)
{
	texture->text_value = (int *)mlx_get_data_addr(texture->img.img,
			&texture->img.bpp, &texture->img.line_len,
			&texture->img.endian);
}

static void	create_texture(t_game *game, t_texture *texture, char *path)
{
	texture->img.img = mlx_xpm_file_to_image(game->mlx, path,
			&texture->img.width, &texture->img.height);
	if (!texture->img.img)
		print_error("Path to texture does not exist or cannot be accessed");
	add_info_to_texture(texture);
}

void	create_textures(t_game *game)
{
	create_texture(game, &game->textu_n, game->map_data.texture_no);
	create_texture(game, &game->textu_s, game->map_data.texture_so);
	create_texture(game, &game->textu_w, game->map_data.texture_we);
	create_texture(game, &game->textu_e, game->map_data.texture_ea);
}

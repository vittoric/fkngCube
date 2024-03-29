/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:20:03 by vcodrean          #+#    #+#             */
/*   Updated: 2024/03/29 20:03:03 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

///revisado

void print_error(char *text)
{
    printf("\033[0;31mError\033[0m\n\033[0;33m%s\033[0m\n", text);
    exit(1);
}

void ft_put_pixel(t_img img, int x, int y, int color)
{
    if (x < 0 || y < 0 || x >= SCREEN_WIDTH || y >= SCREEN_HEIGHT)
		return;
	*(int *)&img.addr[((x * img.bpp) >> 3) + (y * img.line_len)] = color;
}

int clamp_color_component(int component)
{
    if (component > 255)
        return 255;
    if (component < 0)
        return 0;
    return component;
}

int ft_rgba(int r, int g, int b, int alpha)
{
    alpha = clamp_color_component(alpha);
    r = clamp_color_component(r);
    g = clamp_color_component(g);
    b = clamp_color_component(b);

    return (alpha << 24 | r << 16 | g << 8 | b);
}

int exit_game(t_game *game)
{
    mlx_clear_window(game->mlx, game->win);
    mlx_destroy_window(game->mlx, game->win);
    exit(0);
}


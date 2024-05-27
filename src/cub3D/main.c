/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvarrod <a.rr02_cuentas@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:44:10 by arr02             #+#    #+#             */
/*   Updated: 2024/05/27 18:57:36 by alvarrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		print_error("Usage: ./program_name maps/map_file.cub");
		return (1);
	}
	game = ft_calloc(1, sizeof(t_game));
	if (!game)
	{
		print_error("Memory allocation failed");
		return (1);
	}
	load_cub3d(argv, game);
	start_game(game, argv[1]);
	return (0);
}

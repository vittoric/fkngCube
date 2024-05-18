/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:44:10 by arr02             #+#    #+#             */
/*   Updated: 2024/03/29 19:53:51 by vcodrean         ###   ########.fr       */
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

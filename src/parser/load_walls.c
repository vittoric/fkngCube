/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:09:30 by alvarrod          #+#    #+#             */
/*   Updated: 2024/03/29 14:41:32 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

static int	ft_get_longest_line(char **matrix)
{
	int	j;
	int	longest;

	longest = INT_MIN;
	while (*matrix)
	{
		j = 0;
		while ((*matrix)[j])
			j++;
		if (j > longest)
			longest = j;
		matrix++;
	}
	return (longest);
}

static void	add_og_map(char **map, char ***map_cpy)
{
	int	i;
	int	j;
	int	map_heigh;

	map_heigh = ft_get_matrix_size(map);
	i = 0;
	while (++i < map_heigh + 1)
	{
		j = 0;
		while (++j < (int)ft_strlen(map[i - 1]) + 1)
			(*map_cpy)[i][j] = map[i - 1][j - 1];
	}
}

static char	**get_map_cpy(char **map)
{
	int		i;
	int		j;
	int		map_heigh;
	int		map_width;
	char	**map_cpy;

	map_heigh = ft_get_matrix_size(map);
	map_width = ft_get_longest_line(map);
	map_cpy = ft_calloc(map_heigh + 3, sizeof(char *));
	if (!map_cpy)
		exit(1);
	i = -1;
	while (++i < map_heigh + 2)
	{
		map_cpy[i] = ft_calloc(map_width + 3, sizeof(char));
		if (!map_cpy[i])
			exit(1);
		j = -1;
		while (++j < map_width + 2)
			map_cpy[i][j] = ' ';
		map_cpy[i][j] = '\0';
	}
	map_cpy[i] = NULL;
	add_og_map(map, &map_cpy);
	return (map_cpy);
}

static void	check_walls(char **map_cpy)
{
	int	i;
	int	j;

	i = -1;
	while (++i < ft_get_matrix_size(map_cpy))
	{
		j = -1;
		while (++j < (int)ft_strlen(map_cpy[i]))
		{
			if (map_cpy[i][j] == '0' || map_cpy[i][j] == 'N' || map_cpy[i][j]
				== 'S' || map_cpy[i][j] == 'E' || map_cpy[i][j] == 'W')
			{
				if (map_cpy[i + 1][j] == ' ' || map_cpy[i - 1][j] == ' ' ||
					map_cpy[i][j + 1] == ' ' || map_cpy[i][j - 1] == ' ')
					print_error("Something is wrong with the walls");
			}
		}
	}
}

void	check_closed_walls(char **map)
{
	char	**map_cpy;

	map_cpy = get_map_cpy(map);
	check_walls(map_cpy);
	free_value(map_cpy);
}

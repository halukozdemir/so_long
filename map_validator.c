/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:14:45 by halozdem          #+#    #+#             */
/*   Updated: 2024/06/27 17:47:29 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_walls(t_game *game)
{
	int	i;

	i = 1;
	while (++i < game->game_map->map_x)
	{
		if (game->game_map->map[0][i] != '1'
			|| game->game_map->map[game->game_map->map_y - 1][i] != '1')
		{
			write(2, "Error:\nMap borders must be walls.\n", 35);
			free_map(game->game_map->map, game->game_map->map_y);
			exit(1);
		}
	}
	i = -1;
	while (++i < game->game_map->map_y)
	{
		if (game->game_map->map[i][0] != '1'
			|| game->game_map->map[i][game->game_map->map_x - 1] != '1')
		{
			write(2, "Error:\nMap borders must be walls.\n", 35);
			free_map(game->game_map->map, game->game_map->map_y);
			exit(1);
		}
	}
}

void	validate_map(t_game *game)
{
	int	exit_count;
	int	collectible_count;
	int	start_count;
	int	x;
	int	y;

	exit_count = 0;
	collectible_count = 0;
	start_count = 0;
	validate_map_dimensions(game);
	y = 0;
	while (y < game->game_map->map_y)
	{
		x = 0;
		while (x < game->game_map->map_x)
		{
			validate_tile(game->game_map->map[y][x], &exit_count, &start_count,
				game);
			x++;
		}
		y++;
	}
	validate_map_counts(exit_count, start_count, game);
}

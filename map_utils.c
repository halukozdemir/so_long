/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:14:51 by halozdem          #+#    #+#             */
/*   Updated: 2024/07/01 16:01:16 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_tile(char tile, int *exit_count, int *start_count,
		t_game *game)
{
	if (tile != '0' && tile != '1' && tile != 'C' && tile != 'E' && tile != 'P')
		exit_with_error("Error: Map contains invalid characters.\n", game);
	if (tile == 'E')
		(*exit_count)++;
	else if (tile == 'C')
		game->collectibles++;
	else if (tile == 'P')
		(*start_count)++;
}

void	validate_map_dimensions(t_game *game)
{
	if (game->game_map->map_x > 41 || game->game_map->map_y > 21)
	{
		ft_putstr_fd("Error: Map so big.\n", 2);
		free_map(game->game_map->map, game->game_map->map_y);
		exit(1);
	}
}

void	validate_map_counts(int exit_count, int start_count, t_game *game)
{
	if (exit_count != 1)
	{
		exit_with_error("Error: There should be only one exit on the map.\n",
			game);
	}
	if (game->collectibles < 1)
		exit_with_error("Error: At least one collectible is required\n",
			game);
	if (start_count != 1)
		exit_with_error("Error: The map must contain exactly one player.\n",
			game);
}

void	player_pos(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->game_map->map[i])
	{
		j = 0;
		while (game->game_map->map[i][j])
		{
			if (game->game_map->map[i][j] == 'P')
			{
				game->player_pos.x = j;
				game->player_pos.y = i;
			}
			else if (game->game_map->map[i][j] == 'E')
			{
				game->exit_pos.x = j;
				game->exit_pos.y = i;
			}
			j++;
		}
		i++;
	}
}

int	coll_counter(t_game *game)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	counter = 0;
	while (game->game_map->map[i])
	{
		j = 0;
		while (game->game_map->map[i][j])
		{
			if (game->game_map->map[i][j] == 'C')
				counter++;
			j++;
		}
		i++;
	}
	return (counter);
}

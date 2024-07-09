/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:15:22 by halozdem          #+#    #+#             */
/*   Updated: 2024/07/01 16:37:26 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map, int map_y)
{
	int	y;

	if (map)
	{
		y = 0;
		while (y < map_y)
		{
			if (map[y])
				free(map[y]);
			y++;
		}
		free(map);
	}
}

void	free_textures_and_window(t_game *game)
{
	if (game->textures->bg_xpm)
		mlx_destroy_image(game->mlx, game->textures->bg_xpm);
	if (game->textures->coll_xpm)
		mlx_destroy_image(game->mlx, game->textures->coll_xpm);
	if (game->textures->door_xpm)
		mlx_destroy_image(game->mlx, game->textures->door_xpm);
	if (game->textures->player_xpm)
		mlx_destroy_image(game->mlx, game->textures->player_xpm);
	if (game->textures->wall_xpm)
		mlx_destroy_image(game->mlx, game->textures->wall_xpm);
	if (game->textures)
		free(game->textures);
}

void	cleanup(t_game *game)
{
	if (!game)
		return ;
	free_map(game->game_map->map, game->game_map->map_y);
	free_textures_and_window(game);
	free(game->game_map);
	free(game);
}

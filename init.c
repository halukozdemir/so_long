/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:15:11 by halozdem          #+#    #+#             */
/*   Updated: 2024/07/01 13:31:23 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start(t_game *game, char *map_path)
{
	init_game(game, map_path);
	read_map(game);
	validate_walls(game);
	validate_map(game);
	flood_fill(game);
	init_textures(game);
	create_window(game);
	game_loop(game);
}

void	allocate_game_map(t_game *game)
{
	game->game_map = malloc(sizeof(t_map));
	if (!game->game_map)
		exit_with_error("Error: Memory allocation failed.\n", game);
	game->game_map->map = NULL;
	game->game_map->map_x = 0;
	game->game_map->map_y = 0;
}

void	allocate_textures(t_game *game)
{
	game->textures = malloc(sizeof(t_texture));
	if (!game->textures)
	{
		free(game->game_map);
		exit_with_error("Error: Memory allocation failed.\n", game);
	}
	game->textures->bg_xpm = NULL;
	game->textures->coll_xpm = NULL;
	game->textures->door_xpm = NULL;
	game->textures->player_xpm = NULL;
	game->textures->wall_xpm = NULL;
}

void	init_game(t_game *game, char *map_path)
{
	game->map_path = map_path;
	game->moves = 0;
	game->collectibles = 0;
	allocate_game_map(game);
	allocate_textures(game);
	initialize_mlx(game);
}

void	init_textures(t_game *game)
{
	int	x;
	int	y;

	game->textures->bg_xpm = mlx_xpm_file_to_image(game->mlx,
			"textures/background.xpm", &x, &y);
	game->textures->coll_xpm = mlx_xpm_file_to_image(game->mlx,
			"textures/collectable.xpm", &x, &y);
	game->textures->door_xpm = mlx_xpm_file_to_image(game->mlx,
			"textures/door.xpm", &x, &y);
	game->textures->player_xpm = mlx_xpm_file_to_image(game->mlx,
			"textures/rigby.xpm", &x, &y);
	game->textures->wall_xpm = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &x, &y);
	if (!game->textures->bg_xpm || !game->textures->coll_xpm
		|| !game->textures->door_xpm || !game->textures->player_xpm
		|| !game->textures->wall_xpm)
	{
		cleanup(game);
		exit_with_error("Error: Failed to load texture files.\n", game);
	}
}

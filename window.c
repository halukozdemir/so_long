/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:15:28 by halozdem          #+#    #+#             */
/*   Updated: 2024/06/26 19:41:44 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_window(t_game *game)
{
	game->window = mlx_new_window(game->mlx, game->game_map->map_x * 64,
			game->game_map->map_y * 64, "SO_LONG");
	if (!game->window)
		exit_with_error("Error: Failed to create window.\n", game);
}

void	render_tile(t_game *game, int x, int y, char tile)
{
	mlx_put_image_to_window(game->mlx, game->window, game->textures->bg_xpm, x
		* 64, y * 64);
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->window,
			game->textures->wall_xpm, x * 64, y * 64);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->window,
			game->textures->coll_xpm, x * 64, y * 64);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->window,
			game->textures->door_xpm, x * 64, y * 64);
	else if (tile == 'P')
	{
		if (game->exit_pos.x == game->player_pos.x
			&& game->exit_pos.y == game->player_pos.y)
			mlx_put_image_to_window(game->mlx, game->window,
				game->textures->door_xpm, x * 64, y * 64);
		mlx_put_image_to_window(game->mlx, game->window,
			game->textures->player_xpm, x * 64, y * 64);
	}
}

void	render_game(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->game_map->map_y)
	{
		x = 0;
		while (x < game->game_map->map_x)
		{
			render_tile(game, x, y, game->game_map->map[y][x]);
			x++;
		}
		y++;
	}
}

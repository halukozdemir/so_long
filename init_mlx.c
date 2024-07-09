/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:45:44 by halozdem          #+#    #+#             */
/*   Updated: 2024/06/26 19:45:47 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		free(game->textures);
		free(game->game_map);
		exit_with_error("Error: Failed to initialize MLX.\n", game);
	}
	game->window = NULL;
}

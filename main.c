/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:15:00 by halozdem          #+#    #+#             */
/*   Updated: 2024/07/01 15:56:13 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ber_check(char *map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	i--;
	if (!(map[i] == 'r' && map[i - 1] == 'e' && map[i - 2] == 'b' && map[i
				- 3] == '.'))
	{
		ft_putstr_fd("Error: Invalid map extension.\n", 2);
		exit(1);
	}
	if (!(map[i - 4]))
	{
		ft_putstr_fd("Error: Invalid map extension.\n", 2);
		exit(1);
	}
}

int	close_window(t_game *game)
{
	cleanup(game);
	exit(0);
	return (0);
}

void	game_loop(t_game *game)
{
	render_game(game);
	mlx_key_hook(game->window, key_event, game);
	mlx_hook(game->window, 17, 0, close_window, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (ft_putstr_fd("Error: Correct format: ./so_long <map.ber>\n", 2),
			1);
	ber_check(argv[1]);
	game = malloc(sizeof(t_game));
	if (!game)
		exit_with_error("Error: Memory allocation failed.\n", game);
	start(game, argv[1]);
	game_loop(game);
	return (0);
}

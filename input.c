/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:15:05 by halozdem          #+#    #+#             */
/*   Updated: 2024/06/27 17:16:08 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_player(t_game *map, int x, int y);

int	key_event(int keycode, t_game *map)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		move_player(map, 0, -1);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(map, 0, 1);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_player(map, -1, 0);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_player(map, 1, 0);
	else if (keycode == KEY_ESC)
		close_window(map);
	render_game(map);
	return (0);
}

static void	move_player(t_game *map, int x, int y)
{
	if (map->game_map->map[map->player_pos.y + y][map->player_pos.x + x] == '1')
		return ;
	if (map->exit_pos.y == map->player_pos.y + y
		&& map->exit_pos.x == map->player_pos.x + x && map->collectibles == 0)
	{
		map->moves++;
		ft_printf("Moves: %d\nYou won!\n", map->moves);
		close_window(map);
	}
	if (map->game_map->map[map->player_pos.y + y][map->player_pos.x + x] == 'C')
	{
		map->game_map->map[map->player_pos.y][map->player_pos.x] = '0';
		map->collectibles--;
	}
	if (map->game_map->map[map->player_pos.y][map->player_pos.x] != 'E')
		map->game_map->map[map->player_pos.y][map->player_pos.x] = '0';
	if (map->game_map->map[map->exit_pos.y][map->exit_pos.x] == '0')
		map->game_map->map[map->exit_pos.y][map->exit_pos.x] = 'E';
	map->player_pos.x += x;
	map->player_pos.y += y;
	map->game_map->map[map->player_pos.y][map->player_pos.x] = 'P';
	map->moves++;
	ft_printf("Moves: %d\n", map->moves);
}

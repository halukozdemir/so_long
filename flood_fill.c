/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:15:14 by halozdem          #+#    #+#             */
/*   Updated: 2024/06/27 17:45:57 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	f_fill(t_map *map, int y, int x);
static void	flf_check(t_map *map);
static char	**ft_map_dup(char **src);

void	flood_fill(t_game *game)
{
	game->game_map->copy_map = ft_map_dup(game->game_map->map);
	player_pos(game);
	f_fill(game->game_map, game->player_pos.y, game->player_pos.x);
	flf_check(game->game_map);
	free_map(game->game_map->copy_map, game->game_map->map_y);
}

static void	f_fill(t_map *map, int y, int x)
{
	if (y < 0 || x < 0)
		return ;
	if (y >= map->map_y || x >= map->map_x)
		return ;
	if (map->copy_map[y][x] == 'F' || map->copy_map[y][x] == '1')
		return ;
	map->copy_map[y][x] = 'F';
	f_fill(map, y - 1, x);
	f_fill(map, y + 1, x);
	f_fill(map, y, x - 1);
	f_fill(map, y, x + 1);
}

static void	flf_check(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->copy_map[i])
	{
		j = 0;
		while (map->copy_map[i][j])
		{
			if (ft_strchr("PEC", map->copy_map[i][j]))
			{
				write(2, "Error: Invalid map.\n", 21);
				free_map(map->map, map->map_y);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

static char	**ft_map_dup(char **src)
{
	char	**dest;
	int		i;
	int		j;

	i = 0;
	while (src[i])
		i++;
	dest = (char **)malloc(sizeof(char *) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = (char *)malloc(sizeof(char) * (ft_strlen(src[i]) + 1));
		if (!dest[i])
			return (NULL);
		j = -1;
		while (src[i][++j])
			dest[i][j] = src[i][j];
		dest[i][j] = '\0';
		i++;
	}
	dest[i] = NULL;
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:14:55 by halozdem          #+#    #+#             */
/*   Updated: 2024/07/01 16:07:30 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_null_check(char *line);

static void	map_null_check(char *line)
{
	if (line == NULL)
	{
		ft_putstr_fd("Error: Empty map.\n", 2);
		free(line);
		exit(1);
	}
}

void	read_map(t_game *game)
{
	int	line_count;
	int	line_length;

	line_count = 0;
	line_length = -1;
	read_map_dimensions(game, &line_count, &line_length);
	allocate_map_memory(game);
	read_map_content(game, line_count);
}

void	read_map_dimensions(t_game *game, int *line_count, int *line_length)
{
	int		fd;
	char	*line;

	fd = open(game->map_path, O_RDONLY);
	if (fd < 0 && close(fd))
		exit_with_error("Error: Failed to open or close the map file.\n", game);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (*line_length == -1)
			*line_length = ft_strlen(line);
		if ((ft_strlen(line) != *line_length) && (close(fd), 1))
		{
			free(line);
			ft_putstr_fd("Error: Map row length are not consistent.\n", 2);
			exit(1);
		}
		(*line_count)++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	game->game_map->map_x = *line_length;
	game->game_map->map_y = *line_count;
}

void	allocate_map_memory(t_game *game)
{
	game->game_map->map = malloc((game->game_map->map_y + 1) * sizeof(char *));
	if (!game->game_map->map)
		exit_with_error("Error: Memory allocation failed.\n", game);
}

void	read_map_content(t_game *game, int line_count)
{
	int		fd;
	char	*line;

	fd = open(game->map_path, O_RDONLY);
	if (fd < 0)
		exit_with_error("Error: Failed to open map file.\n", game);
	line_count = 0;
	line = get_next_line(fd);
	map_null_check(line);
	while (line != NULL)
	{
		game->game_map->map[line_count] = ft_strdup(line);
		if (!game->game_map->map[line_count])
		{
			free(line);
			close(fd);
			exit_with_error("Error: Memory allocation failed.\n", game);
		}
		line_count++;
		free(line);
		line = get_next_line(fd);
	}
	game->game_map->map[line_count] = NULL;
	close(fd);
}

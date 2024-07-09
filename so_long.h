/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:15:43 by halozdem          #+#    #+#             */
/*   Updated: 2024/06/28 21:38:17 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "lib/get_next_line/get_next_line.h"
# include "lib/libft/libft.h"
# include "lib/mlx/mlx.h"
# include "lib/libft/ft_printf/ft_printf.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_texture
{
	void		*bg_xpm;
	void		*coll_xpm;
	void		*door_xpm;
	void		*player_xpm;
	void		*wall_xpm;
}				t_texture;

typedef struct s_map
{
	char		**map;
	char		**copy_map;
	int			map_x;
	int			map_y;
}				t_map;

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_game
{
	char		*map_path;
	t_map		*game_map;
	t_texture	*textures;
	void		*mlx;
	void		*window;
	int			collectibles;
	t_point		player_pos;
	t_point		exit_pos;
	int			moves;
}				t_game;

# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESC 53

void			start(t_game *game, char *map_path);
void			init_game(t_game *game, char *map_path);
void			allocate_game_map(t_game *game);
void			allocate_textures(t_game *game);
void			initialize_mlx(t_game *game);
void			validate_walls(t_game *game);
void			init_textures(t_game *game);
void			create_window(t_game *game);
void			game_loop(t_game *game);
int				close_window(t_game *game);
void			render_game(t_game *game);
void			cleanup(t_game *game);
void			flood_fill(t_game *game);

void			player_pos(t_game *game);
int				coll_counter(t_game *game);
void			exit_with_error(const char *message, t_game *game);
int				key_event(int keycode, t_game *game);

void			validate_tile(char tile, int *exit_count, int *start_count,
					t_game *game);
void			validate_map_dimensions(t_game *game);
void			validate_map_counts(int exit_count, int start_count,
					t_game *game);
void			validate_map(t_game *game);
void			read_map_dimensions(t_game *game, int *line_count,
					int *line_length);
void			allocate_map_memory(t_game *game);
void			read_map_content(t_game *game, int line_count);
void			read_map(t_game *game);
void			free_map(char **map, int map_y);

#endif

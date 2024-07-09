NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
LIBFT_DIR = lib/libft
GNL_DIR = lib/get_next_line
MLX_DIR = lib/mlx
PRNT_DIR = lib/libft/ft_printf

SRCS = main.c init.c map_reader.c map_utils.c map_validator.c cleanup.c window.c flood_fill.c input.c error.c init_mlx.c
OBJS = $(SRCS:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.dylib
PRNT = $(PRNT_DIR)/libftprintf.a
GNL_SRCS = $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c
GNL_OBJS = $(GNL_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRNT) $(GNL_OBJS) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(GNL_OBJS) $(LIBFT) $(PRNT) $(MLX_FLAGS) -o $(NAME)
	install_name_tool -change libmlx.dylib @executable_path/$(MLX_DIR)/libmlx.dylib $(NAME)

$(MLX):
	make -C $(MLX_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRNT):
	make -C $(PRNT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -I $(MLX_DIR) -I $(LIBFT_DIR) -I $(PRNT_DIR) -I $(GNL_DIR) -c $< -o $@

clean:
	rm -f $(OBJS) $(GNL_OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	make -C $(PRNT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRNT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

NAME = cub3D

CC = cc

LIBFT         = libft/libft.a

CFLAGS = -Wall -Wextra -Werror -O3 #-fsanitize=address -g

SRCS = main.c error.c error2.c wall_check.c updates.c hor_ver.c bras.c setup.c utiles.c get_map.c utiles2.c part_of_horver.c part2_vrhr.c utls.c

OBJS = $(SRCS:.c=.o)

GLFW = $(shell brew --prefix glfw)

MLX_DIR = /Users/namorgha/MLX42

MLX_FLAG = /Users/namorgha/MLX42/build/libmlx42.a -Iinclude -lglfw -L $(GLFW)/lib/ -framework Cocoa -framework OpenGL -framework IOKit


all: $(NAME)

$(LIBFT):
	@make -C libft

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(LIBFT) $(OBJS) $(MLX_FLAG) -o $@

clean:
	@rm -f $(OBJS)
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean
	@rm -f libft.a

re: fclean all

.PHONY: clean fclean all re

NAME		=	cub3d
CC			=	cc
FLAGS		=	-g -Wall -Wextra -Werror
MLX			=	minilibx-linux/libmlx.a
LFT			=	libft/libft.a
INC			=	-I ./includes -I ./libft -I ./minilibx-linux
LIB			=   -L ./libft -lft -L ./minilibx-linux -lmlx -lXext -lX11 -lm
OBJ			=	$(SRC:.c=.o)
OBJBONUS	=	$(SRCBONUS:.c=.o)
SRC			=	src/cub3d.c src/cleaner.c src/map/mapCheck.c src/map/mapElements.c \
				src/map/elementsTextures.c src/map/textureUtils.c src/map/checkMap.c \
				src/map/checkMapUtils.c src/map/checkMapUtils2.c src/window/init.c\
				src/window/game.c src/mlx_draw/draw.c src/mlx_draw/draw_background.c \
				src/dda/calc_cam_dir.c src/dda/calc_step.c src/dda/dda_checkers.c \
				src/dda/dda.c src/dda/ray_len.c src/dda/ray_pos.c src/events/mlx_hooks.c \
				src/mlx_draw/mlx_utils.c
SRCBONUS	=

all:		$(MLX) $(LFT) $(NAME)

$(NAME):	$(OBJ)
			@$(CC) $(FLAGS) -o $@ $^ $(LIB)

$(MLX):
			@make -s -C minilibx-linux

$(LFT):
			@make -s -C libft

src/%.o:	src/%.c
			@$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
			@make -s $@ -C libft
			@make -s $@ -C minilibx-linux
			@rm -rf $(OBJ) src/*.o
			@make -s -C minilibx-linux

fclean:		clean
			@make -s $@ -C libft
			@rm -rf $(NAME)

re:			fclean all

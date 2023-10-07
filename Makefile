NAME		=	cub3d
NAMEB		=	cub3d_bonus
CC			=	cc
FLAGS		=	-g -Wall -Wextra -Werror
MLX			=	minilibx-linux/libmlx.a
LFT			=	libft/libft.a
INC			=	-I ./includes -I ./libft -I ./minilibx-linux
INCB		=	-I ./includes_bonus -I ./libft -I ./minilibx-linux
LIB			=   -L ./libft -lft -L ./minilibx-linux -lmlx -lXext -lX11 -lm
OBJ			=	$(SRC:.c=.o)
OBJBONUS	=	$(SRCBONUS:.c=.o)
SRC			=	src/cub3d.c src/cleaner.c src/map/mapCheck.c src/map/mapElements.c \
				src/map/elementsTextures.c src/map/textureUtils.c src/map/checkMap.c \
				src/map/checkMapUtils.c src/map/checkMapUtils2.c src/window/init.c\
				src/window/game.c src/mlx_draw/draw.c src/mlx_draw/draw_background.c \
				src/dda/calc_cam_dir.c src/dda/calc_step.c src/dda/dda_checkers.c \
				src/dda/dda.c src/dda/ray_len.c src/dda/ray_pos.c src/events/mlx_hooks.c \
				src/mlx_draw/mlx_utils.c src/events/player_mov.c src/events/camera_mov.c

SRCBONUS	=	src_bonus/cub3d_bonus.c src_bonus/cleaner_bonus.c src_bonus/map/mapCheck_bonus.c src_bonus/map/mapElements_bonus.c \
				src_bonus/map/elementsTextures_bonus.c src_bonus/map/textureUtils_bonus.c src_bonus/map/checkMap_bonus.c \
				src_bonus/map/checkMapUtils_bonus.c src_bonus/map/checkMapUtils2_bonus.c src_bonus/window/init_bonus.c\
				src_bonus/window/game_bonus.c src_bonus/mlx_draw/draw_bonus.c src_bonus/mlx_draw/draw_background_bonus.c \
				src_bonus/dda/calc_cam_dir_bonus.c src_bonus/dda/calc_step_bonus.c src_bonus/dda/dda_checkers_bonus.c \
				src_bonus/dda/dda_bonus.c src_bonus/dda/ray_len_bonus.c src_bonus/dda/ray_pos_bonus.c src_bonus/events/mlx_hooks_bonus.c \
				src_bonus/mlx_draw/mlx_utils_bonus.c src_bonus/events/player_mov_bonus.c src_bonus/events/camera_mov_bonus.c \
				src_bonus/mlx_draw/sprite_bonus.c

all:		$(MLX) $(LFT) $(NAME)
bonus:		$(MLX) $(LFT) $(NAMEB)

$(NAME):	$(OBJ)
			@$(CC) $(FLAGS) -o $@ $^ $(LIB)

$(NAMEB):	$(OBJBONUS)
			@$(CC) $(FLAGS) -o $@ $^ $(LIB)

$(MLX):
			@make -s -C minilibx-linux

$(LFT):
			@make -s -C libft

src/%.o:	src/%.c
			@$(CC) $(FLAGS) $(INC) -o $@ -c $<

src_bonus/%.o:	src_bonus/%.c
				@$(CC) $(FLAGS) $(INCB) -o $@ -c $<

clean:
			@make -s $@ -C libft
			@make -s $@ -C minilibx-linux
			@rm -rf $(OBJ) src/*.o
			@rm -rf $(OBJBONUS) src_bonus/*.o

fclean:		clean
			@make -s $@ -C libft
			@rm -rf $(NAME)
			@rm -rf $(NAMEB)

re:			fclean all

reb:		fclean bonus

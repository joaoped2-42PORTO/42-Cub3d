NAME		=	cub3d
CC			=	cc
FLAGS		=	-g -Wall -Wextra -Werror
MLX			=	minilibx-linux/Makefile.gen
LFT			=	libft/libft.a
INC			=	-I ./includes -I ./libft -I ./minilibx-linux
LIB			=	-L ./libft -lft -L ./minilibx-linux -lX11 -lXext -lm -lmlx -lbsd
OBJ			=	$(SRC:.c=.o)
SRC			=	src/cub3d.c src/cleaner.c src/mapCheck.c

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
			@rm -rf $(OBJ) src/*.o

fclean:		clean
			@make -s $@ -C libft
			@rm -rf $(NAME)

re:			fclean all

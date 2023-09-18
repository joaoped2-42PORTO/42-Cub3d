NAME		=	cub3d
NAMEB		=	cub3d_bonus
CC			=	cc -g
FLAGS		=	-Wall -Wextra -Werror
MLX			=	minilibx-linux/Makefile.gen
LFT			=	libft/libft.a
INC			=	-I ./includes -I ./libft -I ./minilibx-linux
INCB		=	-I ./bonus -I ./libft -I ./minilibx-linux
LIB			=	-L ./libft -lft -L ./minilibx-linux -lX11 -lXext -lm -lmlx -lbsd
OBJ			=	$(SRC:.c=.o)
OBJBONUS	=	$(SRCBONUS:.c=.o)
SRC			=	src/cub3d.c src/cleaner.c src/mapCheck.c
SRCBONUS	=

all:		$(MLX) $(LFT) $(NAME)

$(NAME):	$(OBJ)
			@$(CC) $(FLAGS) -o $@ $^ $(LIB)

$(MLX):
			@make -s -C minilibx-linux

$(LFT):
			@make -s -C libft

bonus:		$(MLX) $(LFT) $(NAMEB)

$(NAMEB):	$(OBJBONUS)
			@$(CC) $(FLAGS) -o $@ $^ $(LIB)

src/%.o:	src/%.c
			@$(CC) $(FLAGS) $(INC) -o $@ -c $<

bonus/%.o:	bonus/%.c
			@$(CC) $(FLAGS) $(INCB) -o $@ -c $<

clean:
			@make -s $@ -C libft
			@rm -rf $(OBJ) src/*.o
			@rm -rf $(OBJBONUS) bonus/*.o

fclean:		clean
			@make -s $@ -C libft
			@rm -rf $(NAME)
			@rm -rf $(NAMEB)

re:			fclean all
re_b:			fclean bonus

.PHONY:		all clean fclean re

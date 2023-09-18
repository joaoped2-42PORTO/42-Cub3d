NAME		=	cub3d
NAMEB		=	cub3d_bonus
CC			=	cc
FLAGS		=	-Wall -Wextra -Werror
MLX			=	minilibx-linux/Makefile.gen
INC			=	-I ./mandatory -I ./minilibx-linux
INCB		=	-I ./bonus -I ./minilibx-linux
LIB			=	-L ./minilibx-linux -lX11 -lXext -lm -lmlx -lbsd
OBJ			=	$(SRC:.c=.o)
OBJBONUS	=	$(SRCBONUS:.c=.o)
SRC			=	

SRCBONUS	=	

all:		$(MLX) $(NAME)

$(NAME):	$(OBJ)
			@$(CC) $(FLAGS) -o $@ $^ $(LIB)

$(MLX):
			@make -s -C mlx

bonus:		$(MLX) $(NAMEB)

$(NAMEB):	$(OBJBONUS)
			@$(CC) $(FLAGS) -o $@ $^ $(LIB)

src/%.o:	src/%.c
			@$(CC) $(FLAGS) $(INC) -o $@ -c $<

bonus/%.o:	bonus/%.c
			@$(CC) $(FLAGS) $(INCB) -o $@ -c $<

clean:
			@rm -rf $(OBJ) src/*.o
			@rm -rf $(OBJBONUS) bonus/*.o

fclean:		clean
			@rm -rf $(NAME)
			@rm -rf $(NAMEB)

re:			fclean all
re_b:			fclean bonus

.PHONY:		all clean fclean re

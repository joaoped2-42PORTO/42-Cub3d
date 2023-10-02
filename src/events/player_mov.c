#include "../../includes/cub3d.h"

void	move_right(t_game *game)
{
	char test;
	int	x;
	int	y;

	x = (int)(game->player.posX);
	y = (int)(game->player.posY + game->player.dirY);
	if (y < 0)
		y = 0;
	else if (y > see_matrix_size(game->map) - 1)
		y = see_matrix_size(game->map) - 1;
	if (x < 0)
		x = 0;
	else if (x > (int)ft_strlen(game->map[y]) - 2)
		x = (int)ft_strlen(game->map[y]) - 2;
	test = game->map[y][x];
	if (test != '1')
		game->player.posY += game->player.dirX * game->player.m_speed;
	x = (int)(game->player.posX - game->player.dirX);
	y = (int)(game->player.posY);
	if (y < 0)
		y = 0;
	else if (y > see_matrix_size(game->map) - 1)
		y = see_matrix_size(game->map) - 1;
	if (x < 0)
		x = 0;
	else if (x > (int)ft_strlen(game->map[y]) - 2)
		x = (int)ft_strlen(game->map[y]) - 2;
	test = game->map[y][x];
	if (test != '1')
		game->player.posX -= game->player.dirY * game->player.m_speed;
}

void	move_left(t_game *game)
{
	char test;
	int	x;
	int	y;

	x = (int)(game->player.posX);
	y = (int)(game->player.posY + game->player.dirY);
	if (y < 0)
		y = 0;
	else if (y > see_matrix_size(game->map) - 1)
		y = see_matrix_size(game->map) - 1;
	if (x < 0)
		x = 0;
	else if (x > (int)ft_strlen(game->map[y]) - 2)
		x = (int)ft_strlen(game->map[y]) - 2;
	test = game->map[y][x];
	if (test != '1')
		game->player.posY -= game->player.dirX * game->player.m_speed;
	x = (int)(game->player.posX - game->player.dirX);
	y = (int)(game->player.posY);
	if (y < 0)
		y = 0;
	else if (y > see_matrix_size(game->map) - 1)
		y = see_matrix_size(game->map) - 1;
	if (x < 0)
		x = 0;
	else if (x > (int)ft_strlen(game->map[y]) - 2)
		x = (int)ft_strlen(game->map[y]) - 2;
	test = game->map[y][x];
	if (test != '1')
		game->player.posX += game->player.dirY * game->player.m_speed;
}

void	move_down(t_game *game)
{
	char test;
	int	x;
	int	y;

	x = (int)(game->player.posX);
	y = (int)(game->player.posY + game->player.planeY);
	if (y < 0)
		y = 0;
	else if (y > see_matrix_size(game->map) - 1)
		y = see_matrix_size(game->map) - 1;
	if (x < 0)
		x = 0;
	else if (x > (int)ft_strlen(game->map[y]) - 2)
		x = (int)ft_strlen(game->map[y]) - 2;
	test = game->map[y][x];
	if (test != '1')
		game->player.posY += game->player.planeX * game->player.m_speed;
	x = (int)(game->player.posX - game->player.planeX);
	y = (int)(game->player.posY);
	if (y < 0)
		y = 0;
	else if (y > see_matrix_size(game->map) - 1)
		y = see_matrix_size(game->map) - 1;
	if (x < 0)
		x = 0;
	else if (x > (int)ft_strlen(game->map[y]) - 2)
		x = (int)ft_strlen(game->map[y]) - 2;
	test = game->map[y][x];
	if (test != '1')
		game->player.posX -= game->player.planeY * game->player.m_speed;
}

void	move_up(t_game *game)
{
	char test;
	int	x;
	int	y;

	x = (int)floor(game->player.posX);
	y = (int)floor(game->player.posY + game->player.dirX);
	if (y < 0)
		y = 0;
	else if (y > see_matrix_size(game->map) - 1)
		y = see_matrix_size(game->map) - 1;
	if (x < 0)
		x = 0;
	else if (x > (int)ft_strlen(game->map[y]) - 2)
		x = (int)ft_strlen(game->map[y]) - 2;
	test = game->map[y][x];
	printf("char1: %c\n", test);
	if (test != '1')
		game->player.posY -= game->player.planeX * game->player.m_speed;
	x = (int)(game->player.posX + game->player.dirY);
	y = (int)(game->player.posY);
	if (y < 0)
		y = 0;
	else if (y > see_matrix_size(game->map) - 1)
		y = see_matrix_size(game->map) - 1;
	if (x < 0)
		x = 0;
	else if (x > (int)ft_strlen(game->map[y]) - 2)
		x = (int)ft_strlen(game->map[y]) - 2;
	test = game->map[(int)(game->player.posY)][(int)(game->player.posX + game->player.dirY)];
	printf("char2: %c\n", test);
	if (test != '1')
		game->player.posX += game->player.planeY * game->player.m_speed;
}

void	move_player(t_game *game)
{
	if (game->up_move)
		move_up(game);
	if (game->down_move)
		move_down(game);
	if (game->left_move)
		move_left(game);
	if (game->right_move)
		move_right(game);
	if (game->camera_left)
		camera_left(game);
	if (game->camera_right)
		camera_right(game);
}

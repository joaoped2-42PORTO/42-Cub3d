#include "../../includes/cub3d.h"

void	move_right(t_game *game)
{
	char test;

	test = game->map[(int)(game->player.posY + game->player.dirY)][(int)(game->player.posX)];
	if (test != '1')
		game->player.posY += game->player.dirX * game->player.m_speed;
	// if (game->player.posY < 1)
	// 	game->player.posY = 0;
	test = game->map[(int)(game->player.posY)][(int)(game->player.posX - game->player.dirX)];
	if (test != '1')
		game->player.posX -= game->player.dirY * game->player.m_speed;
	// if (game->player.posX < 1)
	// 	game->player.posX = 0;
}

void	move_left(t_game *game)
{
	char test;

	test = game->map[(int)(game->player.posY + game->player.dirY)][(int)(game->player.posX)];
	if (test != '1')
		game->player.posY -= game->player.dirX * game->player.m_speed;
	// if (game->player.posY < 1)
	// 	game->player.posY = 0;
	test = game->map[(int)(game->player.posY)][(int)(game->player.posX - game->player.dirX)];
	if (test != '1')
		game->player.posX += game->player.dirY * game->player.m_speed;
	// if (game->player.posX < 1)
	// 	game->player.posX = 0;
}

void	move_down(t_game *game)
{
	char test;


	test = game->map[(int)(game->player.posY + game->player.planeY)][(int)(game->player.posX)];
	if (test != '1')
		game->player.posY += game->player.planeX * game->player.m_speed;
	// if (game->player.posY < 1)
	// 	game->player.posY = 0;
	test = game->map[(int)(game->player.posY)][(int)(game->player.posX - game->player.planeX)];
	if (test != '1')
		game->player.posX -= game->player.planeY * game->player.m_speed;
	// if (game->player.posX < 1)
	// 	game->player.posX = 0;
}

void	move_up(t_game *game)
{
	char test;
	int	x;
	int	y;

	x = (int)floor(game->player.posX);
	y = (int)floor(game->player.posY + game->player.dirX);
	test = game->map[y][x];
	if (test != '1')
		game->player.posY -= game->player.planeX * game->player.m_speed;
	test = game->map[(int)(game->player.posY)][(int)(game->player.posX + game->player.dirY)];
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

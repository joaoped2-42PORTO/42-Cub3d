#include "../../includes/cub3d.h"

void	move_right(t_game *game)
{
			char test;

		test = game->map[(int)(game->player.posY + game->player.dirY)][(int)(game->player.posX)];
				printf("posY: %d\nposX: %d\n", (int)(game->player.posY + game->player.planeX), (int)(game->player.posX));
	printf("Teste right: %c\n", test);
		if (test != '1')
			game->player.posY += game->player.dirX * game->player.m_speed;
		if (game->player.posY < 1)
			game->player.posY = 0;
		test = game->map[(int)(game->player.posY)][(int)(game->player.posX - game->player.dirX)];
			printf("posY: %d\nposX: %d\n", (int)(game->player.posY + game->player.planeX), (int)(game->player.posX));
	printf("Teste 2 right: %c\n", test);
		if (test != '1')
			game->player.posX -= game->player.dirY * game->player.m_speed;
				if (game->player.posX < 1)
			game->player.posX = 0;
}

void	move_left(t_game *game)
{
		char test;

		test = game->map[(int)(game->player.posY + game->player.dirY)][(int)(game->player.posX)];
		printf("Teste: %c\n", test);
		if (test != '1')
			game->player.posY -= game->player.dirX * game->player.m_speed;
		if (game->player.posY < 1)
			game->player.posY = 0;
		test = game->map[(int)(game->player.posY)][(int)(game->player.posX - game->player.dirX)];
		if (test != '1')
			game->player.posX += game->player.dirY * game->player.m_speed;
				if (game->player.posX < 1)
			game->player.posX = 0;
}

void	move_down(t_game *game)
{
		char test;


		test = game->map[(int)(game->player.posY + game->player.planeY)][(int)(game->player.posX)];
		printf("Teste: %c\n", test);
		if (test != '1')
			game->player.posY += game->player.planeX * game->player.m_speed;
		if (game->player.posY < 1)
			game->player.posY = 0;
		test = game->map[(int)(game->player.posY)][(int)((game->player.posX - game->player.planeX) * 0.9)];
		if (test != '1')
			game->player.posX -= game->player.planeY * game->player.m_speed;
		if (game->player.posX < 1)
			game->player.posX = 0;
}

void	move_up(t_game *game)
{
/* 	char test;

	test = game->map[(int)(game->player.posY + game->player.planeX)][(int)(game->player.posX)];
	printf("posY: %d\nposX: %d\n", (int)(game->player.posY + game->player.planeX), (int)(game->player.posX));
	printf("Teste: %c\n", test);
	if (test != '1')
		game->player.posY -= game->player.planeX * game->player.m_speed;
	test = game->map[(int)(game->player.posY)][(int)(game->player.posX - game->player.planeY)];
	printf("posY: %d\nposX: %d\n", (int)(game->player.posY + game->player.planeX), (int)(game->player.posX));
	printf("Teste 2: %c\n", test);
	if (test != '1')
		game->player.posX += game->player.planeY * game->player.m_speed; */
		char test;

		test = game->map[(int)((game->player.posY + game->player.dirX) * 0.9)][(int)(game->player.posX)];
		if (test != '1')
			game->player.posY -= game->player.planeX * game->player.m_speed;
		test = game->map[(int)(game->player.posY)][(int)((game->player.posX + game->player.dirY) * 0.9)];
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

#include "../../includes/cub3d.h"

void move_right(t_game *game)
{
	char test;

	test = game->map[(int)(game->player.posY + game->player.dirX * 0.5f)][(int)(game->player.posX)];
	if (test == '0' || test == 'O' || test == ' ' || test == 'N' || test == 'S' || test == 'E' || test == 'W')
		game->player.posY += game->player.dirX * game->player.m_speed;
	test = game->map[(int)(game->player.posY)][(int)(game->player.posX - game->player.dirY * 0.5f)];
	if (test == '0' || test == 'O' || test == ' ' || test == 'N' || test == 'S' || test == 'E' || test == 'W')
		game->player.posX -= game->player.dirY * game->player.m_speed;


}

void move_left(t_game *game)
{
	char test;

	test = game->map[(int)(game->player.posY + game->player.dirX * 0.5f)][(int)(game->player.posX)];
	if (test == '0' || test == 'O' || test == ' ' || test == 'N' || test == 'S' || test == 'E' || test == 'W')
		game->player.posY -= game->player.dirX * game->player.m_speed;
	test = game->map[(int)(game->player.posY)][(int)(game->player.posX - game->player.dirY * 0.5f)];
	if (test == '0' || test == 'O' || test == ' ' || test == 'N' || test == 'S' || test == 'E' || test == 'W')
		game->player.posX += game->player.dirY * game->player.m_speed;
}

void move_down(t_game *game)
{
	char test;

	printf("1st: %f\n", game->player.posY);
	test = game->map[(int)(game->player.posY + game->player.planeX * 0.1f)][(int)(game->player.posX)];
	if (test == '0' || test == 'O' || test == ' ' || test == 'N' || test == 'S' || test == 'E' || test == 'W')
		game->player.posY += game->player.planeX * game->player.m_speed;
	test = game->map[(int)(game->player.posY)][(int)(game->player.posX - game->player.planeY * 0.1f)];
	if (test == '0' || test == 'O' || test == ' ' || test == 'N' || test == 'S' || test == 'E' || test == 'W')
		game->player.posX -= game->player.planeY * game->player.m_speed;


}

void move_up(t_game *game)
{
	char test;

	test = game->map[(int)(game->player.posY + game->player.planeX * 0.1f)][(int)(game->player.posX)];
	if (test == '0' || test == 'O' || test == ' ' || test == 'N' || test == 'S' || test == 'E' || test == 'W')
	{
		if (game->player.posY > 1.1 && (see_matrix_size(game->map) - 1) > game->player.posY + 0.2 && game->player.posX > 1.2)
		{
			game->player.posY -= game->player.planeX * game->player.m_speed;
		}
		else if(game->player.planeX < 0 && game->player.posY > 1 && (see_matrix_size(game->map) - 2) > game->player.posY && game->player.posX > 1.2)
		{
			game->player.posY -= game->player.planeX * game->player.m_speed;
		}
		else if (game->player.planeX > 0 && game->player.posY > 1.1 && game->player.posX > 1.2)
		{
			game->player.posY -= game->player.planeX * game->player.m_speed;
		}
	}
	test = game->map[(int)(game->player.posY)][(int)(game->player.posX - game->player.planeY * 0.1f)];
	if (test == '0' || test == 'O' || test == ' ' || test == 'N' || test == 'S' || test == 'E' || test == 'W')
	{
		printf("posY: %f\n", game->player.posY);
		printf("posX: %f\n", game->player.posX);
		printf("PlaneY: %f\n", game->player.planeY);
		printf("----------------------------\n");
		printf("\n");
		if (game->player.posX > 1.2 && game->player.posY > 1.1 && ft_strlen(game->map[(int)game->player.posY]) - 2 > game->player.posX)
			game->player.posX += game->player.planeY * game->player.m_speed;
		else if (game->player.posX > 1.05 && game->player.posY > 1.1 && game->player.planeY > 0)
			game->player.posX += game->player.planeY * game->player.m_speed;
	}
}

void move_player(t_game *game)
{
	if (game->up_move )
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

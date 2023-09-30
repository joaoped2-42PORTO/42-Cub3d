#include "../../includes/cub3d.h"

void camera_left(t_game *game)
{
	double oldDirX;
	double oldplaneX;

	oldDirX = game->player.dirX;
	game->player.dirX = game->player.dirX * cos(game->player.r_speed) - game->player.dirY * sin(game->player.r_speed);
	game->player.dirY = oldDirX * sin(game->player.r_speed) + game->player.dirY * cos(game->player.r_speed);
	oldplaneX = game->player.planeX;
	game->player.planeX = game->player.planeX * cos(game->player.r_speed) - game->player.planeY * sin(game->player.r_speed);
	game->player.planeY = oldplaneX * sin(game->player.r_speed) + game->player.planeY * cos(game->player.r_speed);
}

void camera_right(t_game *game)
{
	double oldDirX;
	double oldplaneX;

	oldDirX = game->player.dirX;
	game->player.dirX = game->player.dirX * cos(-game->player.r_speed) - game->player.dirY * sin(-game->player.r_speed);
	game->player.dirY = oldDirX * sin(-game->player.r_speed) + game->player.dirY * cos(-game->player.r_speed);
	oldplaneX = game->player.planeX;
	game->player.planeX = game->player.planeX * cos(-game->player.r_speed) - game->player.planeY * sin(-game->player.r_speed);
	game->player.planeY = oldplaneX * sin(-game->player.r_speed) + game->player.planeY * cos(-game->player.r_speed);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped2 <joaoped2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:33:43 by joaoped2          #+#    #+#             */
/*   Updated: 2023/09/29 15:48:30 by joaoped2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// Mal
int	key_press(int keycode, t_game *game)
{
	if (keycode == 65307) // ESC
		ft_clean_exit(game);
	if (keycode == 119) // W
	{
		char test;

		test = game->map[(int)(game->player.posY + game->player.planeX)][(int)(game->player.posX)];
		if (test == '0' || test == 'O' || test == ' ' || test == 'N' || test == 'S' || test == 'E' || test == 'W')
			game->player.posY -= game->player.planeX * game->player.m_speed;
		test = game->map[(int)(game->player.posY)][(int)(game->player.posX - game->player.planeY)];
		if (test == '0' || test == 'O' || test == ' ' || test == 'N' || test == 'S' || test == 'E' || test == 'W')
			game->player.posX += game->player.planeY * game->player.m_speed;
	}
	if (keycode == 115) // S
	{
		char test;

		test = game->map[(int)(game->player.posY + game->player.planeX)][(int)(game->player.posX)];
		if (test == '0' || test == 'O' || test == ' ' || test == 'N' || test == 'S' || test == 'E' || test == 'W')
			game->player.posY += game->player.planeX * game->player.m_speed;
		test = game->map[(int)(game->player.posY)][(int)(game->player.posX - game->player.planeY)];
		if (test == '0' || test == 'O' || test == ' ' || test == 'N' || test == 'S' || test == 'E' || test == 'W')
			game->player.posX -= game->player.planeY * game->player.m_speed;
	}
	if (keycode == 97) // A
	{
		char test;

		test = game->map[(int)(game->player.posY + game->player.dirX)][(int)(game->player.posX)];
		if (test == '0' || test == 'O' || test == ' ' || test == 'N' || test == 'S' || test == 'E' || test == 'W')
			game->player.posY -= game->player.dirX * game->player.m_speed;
		test = game->map[(int)(game->player.posY)][(int)(game->player.posX - game->player.dirY)];
		if (test == '0' || test == 'O' || test == ' ' || test == 'N' || test == 'S' || test == 'E' || test == 'W')
			game->player.posX += game->player.dirY * game->player.m_speed;
	}
	if (keycode == 100) // D
	{
		char test;

		test = game->map[(int)(game->player.posY + game->player.dirX)][(int)(game->player.posX)];
		if (test == '0' || test == 'O' || test == ' ' || test == 'N' || test == 'S' || test == 'E' || test == 'W')
			game->player.posY += game->player.dirX * game->player.m_speed;
		test = game->map[(int)(game->player.posY)][(int)(game->player.posX - game->player.dirY)];
		if (test == '0' || test == 'O' || test == ' ' || test == 'N' || test == 'S' || test == 'E' || test == 'W')
			game->player.posX -= game->player.dirY * game->player.m_speed;
	}
	if (keycode == 65363) // <-
	{
		double	oldDirX;
		double	oldplaneX;

		oldDirX = game->player.dirX;
		game->player.dirX = game->player.dirX * cos(game->player.r_speed) - game->player.dirY * sin(game->player.r_speed);
		game->player.dirY = oldDirX * sin(game->player.r_speed) + game->player.dirY * cos(game->player.r_speed);
		oldplaneX = game->player.planeX;
		game->player.planeX = game->player.planeX * cos(game->player.r_speed) - game->player.planeY * sin(game->player.r_speed);
		game->player.planeY = oldplaneX * sin(game->player.r_speed) + game->player.planeY * cos(game->player.r_speed);
	}
	if (keycode == 65361) // ->
	{
		double	oldDirX;
		double	oldplaneX;

		oldDirX = game->player.dirX;
		game->player.dirX = game->player.dirX * cos(-game->player.r_speed) - game->player.dirY * sin(-game->player.r_speed);
		game->player.dirY = oldDirX * sin(-game->player.r_speed) + game->player.dirY * cos(-game->player.r_speed);
		oldplaneX = game->player.planeX;
		game->player.planeX = game->player.planeX * cos(-game->player.r_speed) - game->player.planeY * sin(-game->player.r_speed);
		game->player.planeY = oldplaneX * sin(-game->player.r_speed) + game->player.planeY * cos(-game->player.r_speed);
	}
	return (0);
}

int	key_release(int keycode)
{
	(void)keycode;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped2 <joaoped2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:33:43 by joaoped2          #+#    #+#             */
/*   Updated: 2023/09/28 15:32:27 by joaoped2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == 65307)
		ft_clean_exit(game);
	if (keycode == 119)
	{
		char test;

		printf("%c\n", game->map[(int)(game->player.posX + game->player.dirX * game->player.m_speed)][(int)(game->player.posY)]);
		test = game->map[(int)(game->player.posX + game->player.dirX * game->player.m_speed)][(int)(game->player.posY)];
		if (test == '0' || test == 'O' || test == ' ')
			game->player.posY += game->player.dirY * game->player.m_speed;
		test = game->map[(int)(game->player.posX)][(int)(game->player.posY - game->player.dirY * game->player.m_speed)];
		if (test == '0' || test == 'O' || test == ' ')
			game->player.posY += game->player.dirY * game->player.m_speed;
	}
	if (keycode == 115)
	{
		char test;

		printf("%c\n", game->map[(int)(game->player.posX + game->player.dirX * game->player.m_speed)][(int)(game->player.posY)]);
		test = game->map[(int)(game->player.posX + game->player.dirX * game->player.m_speed)][(int)(game->player.posY)];
		if (test == '0' || test == 'O' || test == ' ')
			game->player.posY -= game->player.dirY * game->player.m_speed;
		test = game->map[(int)(game->player.posX)][(int)(game->player.posY - game->player.dirY * game->player.m_speed)];
		if (test == '0' || test == 'O' || test == ' ')
			game->player.posY -= game->player.dirY * game->player.m_speed;
	}
	if (keycode == 97)
	{
		char test;

		printf("%c\n", game->map[(int)(game->player.posX + game->player.dirX * game->player.m_speed)][(int)(game->player.posY)]);
		test = game->map[(int)(game->player.posX + game->player.dirX * game->player.m_speed)][(int)(game->player.posY)];
		if (test == '0' || test == 'O' || test == ' ')
			game->player.posX -= game->player.dirX * game->player.m_speed;
		test = game->map[(int)(game->player.posX)][(int)(game->player.posY - game->player.dirY * game->player.m_speed)];
		if (test == '0' || test == 'O' || test == ' ')
			game->player.posX -= game->player.dirX * game->player.m_speed;
	}
	if (keycode == 100)
	{
		char test;

		printf("%c\n", game->map[(int)(game->player.posX + game->player.dirX * game->player.m_speed)][(int)(game->player.posY)]);
		test = game->map[(int)(game->player.posX + game->player.dirX * game->player.m_speed)][(int)(game->player.posY)];
		if (test == '0' || test == 'O' || test == ' ')
			game->player.posX += game->player.dirX * game->player.m_speed;
		test = game->map[(int)(game->player.posX)][(int)(game->player.posY - game->player.dirY * game->player.m_speed)];
		if (test == '0' || test == 'O' || test == ' ')
			game->player.posX += game->player.dirX * game->player.m_speed;
	}
	if (keycode == 65363)
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
	if (keycode == 65361)
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
	return (0);
}

int	key_release(int keycode)
{
	if (keycode == 119)
		printf("");
	if (keycode == 115)
		printf("");
	if (keycode == 97)
		printf("");
	if (keycode == 100)
		printf("");
	if (keycode == 65363)
		printf("");
	if (keycode == 65361)
		printf("");
	return (0);
}

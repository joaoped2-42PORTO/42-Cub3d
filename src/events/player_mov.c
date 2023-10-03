/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped2 <joaoped2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:33:43 by joaoped2          #+#    #+#             */
/*   Updated: 2023/10/02 09:19:40 by joaoped2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/cub3d.h"

/*Test changed to != -1 other that equal to everything*/

void	move_right(t_game *game)
{
	char	test;

	test = game->map[(int)(game->player.posY + game->player.dirX * 0.15f)]
	[(int)(game->player.posX)];
	if (test != '1')
		game->player.posY += game->player.dirX * game->player.m_speed;
	test = game->map[(int)(game->player.posY)]
	[(int)(game->player.posX - game->player.dirY * 0.15f)];
	if (test != '1')
		game->player.posX -= game->player.dirY * game->player.m_speed;
}

void	move_left(t_game *game)
{
	char	test;

	test = game->map[(int)(game->player.posY + game->player.dirX * -0.1f)]
	[(int)(game->player.posX)];
	if (test != '1')
		game->player.posY -= game->player.dirX * game->player.m_speed;
	test = game->map[(int)(game->player.posY)]
	[(int)(game->player.posX - game->player.dirY * -0.1)];
	if (test != '1')
		game->player.posX += game->player.dirY * game->player.m_speed;
}

void	move_down(t_game *game)
{
	char	test;

	test = game->map[(int)(game->player.posY + game->player.planeX * 0.8f)]
	[(int)(game->player.posX)];
	if (test != '1')
		game->player.posY += game->player.planeX * game->player.m_speed;
	test = game->map[(int)(game->player.posY)]
	[(int)(game->player.posX - game->player.planeY * 0.8f)];
	if (test != '1')
		game->player.posX -= game->player.planeY * game->player.m_speed;
}

void	move_up(t_game *game)
{
	char	test;

	test = game->map[(int)(game->player.posY + game->player.planeX * -0.22f)]
	[(int)(game->player.posX)];
	if (test != '1')
		game->player.posY -= game->player.planeX * game->player.m_speed;
	test = game->map[(int)(game->player.posY)]
	[(int)(game->player.posX - game->player.planeY * -0.22f)];
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

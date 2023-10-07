/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:33:43 by joaoped2          #+#    #+#             */
/*   Updated: 2023/10/07 15:28:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_right(t_game *game)
{
	char	test;

	test = game->map[(int)(game->player.posy + game->player.dirx * 0.15f)]
	[(int)(game->player.posx)];
	if (test != '1')
		game->player.posy += game->player.dirx * game->player.m_speed;
	test = game->map[(int)(game->player.posy)]
	[(int)(game->player.posx - game->player.diry * 0.15f)];
	if (test != '1')
		game->player.posx -= game->player.diry * game->player.m_speed;
}

void	move_left(t_game *game)
{
	char	test;

	test = game->map[(int)(game->player.posy + game->player.dirx * -0.1f)]
	[(int)(game->player.posx)];
	if (test != '1')
		game->player.posy -= game->player.dirx * game->player.m_speed;
	test = game->map[(int)(game->player.posy)]
	[(int)(game->player.posx - game->player.diry * -0.1)];
	if (test != '1')
		game->player.posx += game->player.diry * game->player.m_speed;
}

void	move_down(t_game *game)
{
	char	test;

	test = game->map[(int)(game->player.posy + game->player.planex * 0.8f)]
	[(int)(game->player.posx)];
	if (test != '1')
		game->player.posy += game->player.planex * game->player.m_speed;
	test = game->map[(int)(game->player.posy)]
	[(int)(game->player.posx - game->player.planey * 0.8f)];
	if (test != '1')
		game->player.posx -= game->player.planey * game->player.m_speed;
}

void	move_up(t_game *game)
{
	char	test;

	test = game->map[(int)(game->player.posy + game->player.planex * -0.22f)]
	[(int)(game->player.posx)];
	if (test != '1')
		game->player.posy -= game->player.planex * game->player.m_speed;
	test = game->map[(int)(game->player.posy)]
	[(int)(game->player.posx - game->player.planey * -0.22f)];
	if (test != '1')
		game->player.posx += game->player.planey * game->player.m_speed;
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

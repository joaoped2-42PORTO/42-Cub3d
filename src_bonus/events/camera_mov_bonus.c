/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_mov_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neddy <neddy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:33:43 by joaoped2          #+#    #+#             */
/*   Updated: 2023/10/07 16:29:48 by neddy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	camera_left(t_game *game)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = game->player.dirx;
	game->player.dirx = game->player.dirx * cos(game->player.r_speed)
		- game->player.diry * sin(game->player.r_speed);
	game->player.diry = olddir_x * sin(game->player.r_speed) + game->player.diry
		* cos(game->player.r_speed);
	oldplane_x = game->player.planex;
	game->player.planex = game->player.planex * cos(game->player.r_speed)
		- game->player.planey * sin(game->player.r_speed);
	game->player.planey = oldplane_x * sin(game->player.r_speed)
		+ game->player.planey * cos(game->player.r_speed);
}

void	camera_right(t_game *game)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = game->player.dirx;
	game->player.dirx = game->player.dirx * cos(-game->player.r_speed)
		- game->player.diry * sin(-game->player.r_speed);
	game->player.diry = olddir_x * sin(-game->player.r_speed)
		+ game->player.diry * cos(-game->player.r_speed);
	oldplane_x = game->player.planex;
	game->player.planex = game->player.planex * cos(-game->player.r_speed)
		- game->player.planey * sin(-game->player.r_speed);
	game->player.planey = oldplane_x * sin(-game->player.r_speed)
		+ game->player.planey * cos(-game->player.r_speed);
}

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

void	camera_left(t_game *game)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = game->player.dirX;
	game->player.dirX = game->player.dirX * cos(game->player.r_speed)
		- game->player.dirY * sin(game->player.r_speed);
	game->player.dirY = olddir_x * sin(game->player.r_speed) + game->player.dirY
		* cos(game->player.r_speed);
	oldplane_x = game->player.planeX;
	game->player.planeX = game->player.planeX * cos(game->player.r_speed)
		- game->player.planeY * sin(game->player.r_speed);
	game->player.planeY = oldplane_x * sin(game->player.r_speed)
		+ game->player.planeY * cos(game->player.r_speed);
}

void	camera_right(t_game *game)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = game->player.dirX;
	game->player.dirX = game->player.dirX * cos(-game->player.r_speed)
		- game->player.dirY * sin(-game->player.r_speed);
	game->player.dirY = olddir_x * sin(-game->player.r_speed)
		+ game->player.dirY * cos(-game->player.r_speed);
	oldplane_x = game->player.planeX;
	game->player.planeX = game->player.planeX * cos(-game->player.r_speed)
		- game->player.planeY * sin(-game->player.r_speed);
	game->player.planeY = oldplane_x * sin(-game->player.r_speed)
		+ game->player.planeY * cos(-game->player.r_speed);
}

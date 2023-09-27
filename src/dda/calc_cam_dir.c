/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cam_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neddy <neddy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:22:18 by joaoped2          #+#    #+#             */
/*   Updated: 2023/09/27 16:29:11 by neddy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	calculate_camera_direction(t_game *game)
{
	if (game->player.side == 0)
		game->player.perpWallDist = (game->player.sideDistX
				- game->player.deltaDistX);
	else
		game->player.perpWallDist = (game->player.sideDistY
				- game->player.deltaDistY);
	game->wall.lineHeight = (int)(screenHeight / game->player.perpWallDist);
	game->wall.drawStart = -game->wall.lineHeight / 2 + screenHeight / 2;
	if (game->wall.drawStart < 0)
		game->wall.drawStart = 0;
	game->wall.drawEnd = game->wall.lineHeight / 2 + screenHeight / 2;
	if (game->wall.drawEnd >= screenHeight)
		game->wall.drawEnd = screenHeight - 1;
}

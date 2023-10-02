/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cam_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped2 <joaoped2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:22:18 by joaoped2          #+#    #+#             */
/*   Updated: 2023/10/02 10:29:14 by joaoped2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	calculate_camera_direction(t_game *game)
{
	if (game->player.side == 0)
		game->player.perpWallDist = (game->player.sideDistX
				- game->player.deltaDistX + 0.5);
	else
		game->player.perpWallDist = (game->player.sideDistY
				- game->player.deltaDistY + 0.5);
	game->wall.lineHeight = (int)(1080 / game->player.perpWallDist);
	game->wall.drawStart = -game->wall.lineHeight / 2 + 1080 / 2;
	if (game->wall.drawStart < 0)
		game->wall.drawStart = 0;
	game->wall.drawEnd = game->wall.lineHeight / 2 + 1080 / 2;
	if (game->wall.drawEnd >= 1080)
		game->wall.drawEnd = 1080 - 1;
}

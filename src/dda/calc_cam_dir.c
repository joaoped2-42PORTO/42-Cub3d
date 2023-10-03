/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cam_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:22:18 by joaoped2          #+#    #+#             */
/*   Updated: 2023/10/03 17:16:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	calculate_camera_direction(t_game *game)
{
	if (game->player.side == 0)
		game->player.perpwalldist = (game->player.sidedistx
				- game->player.deltadistx);
	else
		game->player.perpwalldist = (game->player.sidedisty
				- game->player.deltadisty);
	game->wall.lineheight = (int)(1080 / game->player.perpwalldist);
	game->wall.drawstart = -game->wall.lineheight / 2 + 1080 / 2;
	if (game->wall.drawstart < 0)
		game->wall.drawstart = 0;
	game->wall.drawend = game->wall.lineheight / 2 + 1080 / 2;
	if (game->wall.drawend >= 1080)
		game->wall.drawend = 1080 - 1;
}

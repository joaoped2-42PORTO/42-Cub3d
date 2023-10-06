/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cam_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neddy <neddy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:22:18 by joaoped2          #+#    #+#             */
/*   Updated: 2023/10/06 15:48:52 by neddy            ###   ########.fr       */
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
	game->wall.lineheight = (int)(SCREENWIDTH / game->player.perpwalldist);
	game->wall.drawstart = -game->wall.lineheight / 2 + SCREENWIDTH / 2;
	if (game->wall.drawstart < 0)
		game->wall.drawstart = 0;
	game->wall.drawend = game->wall.lineheight / 2 + SCREENWIDTH / 2;
	if (game->wall.drawend >= SCREENWIDTH)
		game->wall.drawend = SCREENWIDTH - 1;
}

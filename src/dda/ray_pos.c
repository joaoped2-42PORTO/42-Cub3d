/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped2 <joaoped2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:20:28 by joaoped2          #+#    #+#             */
/*   Updated: 2023/09/27 10:21:18 by joaoped2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	calculate_ray_pos(t_game *game)
{
	game->player.cameraX = 2 * game->player.x / (double)screenWidth - 1;
	game->player.rayDirX = game->player.dirX + game->player.planeX
		* game->player.cameraX;
	game->player.rayDirY = game->player.dirX + game->player.planeY
		* game->player.cameraX;
	game->player.mapX = (int)game->player.posX;
	game->player.mapY = (int)game->player.posY;
	game->player.hit = 0;
}

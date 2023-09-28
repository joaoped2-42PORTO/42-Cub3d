/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:20:28 by joaoped2          #+#    #+#             */
/*   Updated: 2023/09/28 18:43:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	calculate_ray_pos(t_game *game)
{
	game->player.cameraX = 2 * game->player.x / (double)(1920) - 1;
	game->player.rayDirX = game->player.dirX + game->player.planeX
		* game->player.cameraX;
	game->player.rayDirY = game->player.dirY + game->player.planeY
		* game->player.cameraX;
 	game->player.mapX = (int)game->player.posX; //Isto esta a alterar a posicao do jogador!!
	game->player.mapY = (int)game->player.posY; //Isto esta a alterar a posicao do jogador!!
}

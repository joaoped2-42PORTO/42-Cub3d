/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neddy <neddy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:20:28 by joaoped2          #+#    #+#             */
/*   Updated: 2023/10/06 15:49:27 by neddy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	calculate_ray_pos(t_game *game)
{
	game->player.camerax = 2 * game->player.x / (double)(SCREENHEIGHT) - 1;
	game->player.raydirx = game->player.dirx + game->player.planex
		* game->player.camerax;
	game->player.raydiry = game->player.diry + game->player.planey
		* game->player.camerax;
	game->player.mapx = floor(game->player.posx);
	game->player.mapy = floor(game->player.posy);
}

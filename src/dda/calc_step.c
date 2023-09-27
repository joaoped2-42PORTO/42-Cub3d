/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_step.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neddy <neddy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:21:34 by joaoped2          #+#    #+#             */
/*   Updated: 2023/09/27 16:19:33 by neddy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	calculate_step_forX(t_game *game)
{
	if (game->player.rayDirX < 0)
	{
		game->player.stepX = -1;
		game->player.sideDistX = (game->player.posY - game->player.mapX)
			* game->player.deltaDistX;
	}
	else
	{
		game->player.stepX = 1;
		game->player.sideDistX = (game->player.mapX + 1.0 - game->player.posY)
			* game->player.deltaDistX;
	}
}

void	calculate_step_forY(t_game *game)
{
	if (game->player.rayDirY < 0)
	{
		game->player.stepY = -1;
		game->player.sideDistY = (game->player.posX - game->player.mapY)
			* game->player.deltaDistY;
	}
	else
	{
		game->player.stepY = 1;
		game->player.sideDistY = (game->player.mapY + 1.0 - game->player.posX)
			* game->player.deltaDistY;
	}
}

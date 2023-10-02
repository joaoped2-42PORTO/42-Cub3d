/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_step.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped2 <joaoped2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:21:34 by joaoped2          #+#    #+#             */
/*   Updated: 2023/09/28 09:56:03 by joaoped2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	calculate_step_forX(t_game *game)
{
	if (game->player.rayDirX < 0)
	{
		game->player.stepX = -1;
		game->player.sideDistX = (game->player.posX - game->player.mapX)
			* game->player.deltaDistX;
	}
	else
	{
		game->player.stepX = 1;
		game->player.sideDistX = (game->player.mapX - game->player.posX)
			* game->player.deltaDistX;
	}
}

void	calculate_step_forY(t_game *game)
{
	if (game->player.rayDirY < 0)
	{
		game->player.stepY = -1;
		game->player.sideDistY = (game->player.posY - game->player.mapY)
			* game->player.deltaDistY;
	}
	else
	{
		game->player.stepY = 1;
		game->player.sideDistY = (game->player.mapY - game->player.posY)
			* game->player.deltaDistY;
	}
}

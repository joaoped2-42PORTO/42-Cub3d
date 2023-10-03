/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_step.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:21:34 by joaoped2          #+#    #+#             */
/*   Updated: 2023/10/03 17:16:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	calculate_step_forx(t_game *game)
{
	if (game->player.raydirx < 0)
	{
		game->player.stepx = -1;
		game->player.sidedistx = (game->player.posx - game->player.mapx)
			* game->player.deltadistx;
	}
	else
	{
		game->player.stepx = 1;
		game->player.sidedistx = (game->player.mapx + 1.0f - game->player.posx)
			* game->player.deltadistx;
	}
}

void	calculate_step_fory(t_game *game)
{
	if (game->player.raydiry < 0)
	{
		game->player.stepy = -1;
		game->player.sidedisty = (game->player.posy - game->player.mapy)
			* game->player.deltadisty;
	}
	else
	{
		game->player.stepy = 1;
		game->player.sidedisty = (game->player.mapy + 1.0f - game->player.posy)
			* game->player.deltadisty;
	}
}

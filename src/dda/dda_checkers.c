/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neddy <neddy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:22:55 by joaoped2          #+#    #+#             */
/*   Updated: 2023/09/27 16:19:38 by neddy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_next_sqr(t_game *game)
{
	if (game->player.sideDistX < game->player.sideDistY)
	{
		game->player.sideDistX += game->player.deltaDistX;
		game->player.mapX += game->player.stepX;
		game->player.side = 0;
	}
	else
	{
		game->player.sideDistY += game->player.deltaDistY;
		game->player.mapY += game->player.stepY;
		game->player.side = 1;
	}
}

void	check_hit(t_game *game)
{
	char	curr;

	curr = 0;
	while (game->player.hit == 0)
	{
		check_next_sqr(game);
		curr = game->map[game->player.mapY][game->player.mapX];
		if (curr == '1')
			game->player.hit = 1;
	}
}

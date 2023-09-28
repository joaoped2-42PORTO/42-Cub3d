/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped2 <joaoped2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:22:55 by joaoped2          #+#    #+#             */
/*   Updated: 2023/09/28 16:04:56 by joaoped2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_hit(t_game *game)
{
	// if (game->player.sideDistX != game->db.tmpfl)
	// {
	// 	game->db.tmpfl = game->player.sideDistX;
	// 	printf("%f\n", game->player.sideDistX);
	// }
	if (game->player.mapX != game->db.tmpint)
	{
		game->db.tmpint = game->player.mapX;
		printf("Player Map X Pos:%d\n", game->player.mapX);
	}
	printf("Player Delta Dist X: %f\n", game->player.deltaDistX);
	printf("Player side: %d\n", game->player.side);
	while (game->player.hit == 0)
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
		if (game->map[game->player.mapY][game->player.mapX] != 48)
			game->player.hit = 1;
	}
}

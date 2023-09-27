/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped2 <joaoped2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:13:30 by neddy             #+#    #+#             */
/*   Updated: 2023/09/27 10:23:10 by joaoped2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


void	performdda(t_game *game)
{
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
		if (game->map[game->player.mapY][game->player.mapX] == '1')
			game->player.hit = 1;
	}
}


void	doalldda(t_game *game)
{
	game->player.x = 0;
	while (game->player.x < screenWidth)
	{
		calculate_ray_pos(game);
		calculate_ray_lenght_forX(game);
		calculate_ray_lenght_forY(game);
		calculate_step_forX(game);
		calculate_step_forY(game);
		check_hit(game);
		performdda(game);
		calculate_camera_direction(game);
		draw_images_to_game(game, game->player.x);
		game->player.x++;
	}
}

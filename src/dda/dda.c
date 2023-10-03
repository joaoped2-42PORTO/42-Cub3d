/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped2 <joaoped2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:13:30 by neddy             #+#    #+#             */
/*   Updated: 2023/09/28 14:02:32 by joaoped2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	doalldda(t_game *game)
{

	game->player.x = 0;
	while (game->player.x < 1920)
	{
		calculate_ray_pos(game);
		calculate_ray_lenght_forX(game); //not lenght but direction
		calculate_ray_lenght_forY(game); // same ^^
		calculate_step_forX(game);
		calculate_step_forY(game);
		check_hit(game);
		calculate_camera_direction(game);
		draw_images_to_game(game, game->player.x);
		game->player.hit = 0;
		game->player.x++;
	}
}

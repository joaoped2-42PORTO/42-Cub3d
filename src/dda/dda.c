/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:13:30 by neddy             #+#    #+#             */
/*   Updated: 2023/10/03 17:11:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	doalldda(t_game *game)
{
	game->player.x = 0;
	while (game->player.x < 1920)
	{
		calculate_ray_pos(game);
		calculate_ray_lenght_forx(game);
		calculate_ray_lenght_fory(game);
		calculate_step_forx(game);
		calculate_step_fory(game);
		check_hit(game);
		calculate_camera_direction(game);
		draw_images_to_game(game, game->player.x);
		game->player.hit = 0;
		game->player.x++;
	}
}

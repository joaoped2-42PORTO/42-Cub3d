/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped2 <joaoped2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:31:21 by joaoped2          #+#    #+#             */
/*   Updated: 2023/09/27 10:31:39 by joaoped2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	print_background(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < 1080)
	{
		x = 0;
		while (x < 1920)
		{
			if (1080 / 2 > y)
				paint_on_screen_by_pixel(&game->background, x, y, game->f_color);
			else
				paint_on_screen_by_pixel(&game->background, x, y, game->c_color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->background.img, 0, 0);
}

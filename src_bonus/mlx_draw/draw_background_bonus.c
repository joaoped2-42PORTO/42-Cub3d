/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neddy <neddy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:31:21 by joaoped2          #+#    #+#             */
/*   Updated: 2023/10/07 16:29:48 by neddy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	print_background(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < SCREENWIDTH)
	{
		x = 0;
		while (x < SCREENHEIGHT)
		{
			if (SCREENWIDTH / 2 > y)
				paint_on_screen_by_pixel
					(&game->background, x, y, game->f_color);
			else
				paint_on_screen_by_pixel
					(&game->background, x, y, game->c_color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->background.img, 0, 0);
}

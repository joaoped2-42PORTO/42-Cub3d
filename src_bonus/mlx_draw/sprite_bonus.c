/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:30:02 by marvin            #+#    #+#             */
/*   Updated: 2023/10/05 15:30:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	gun_images(t_game *game)
{
	game->gun_img.gun1.img = mlx_xpm_file_to_image(game->mlx, "./images/1.xpm",
			&game->gun_img.gun1.width, &game->gun_img.gun1.height);
	game->gun_img.gun1.addr = mlx_get_data_addr(game->gun_img.gun1.img,
			&game->gun_img.gun1.bits_per_pixel,
			&game->gun_img.gun1.line_length,
			&game->gun_img.gun1.endian);
	game->gun_img.gun2.img = mlx_xpm_file_to_image(game->mlx, "./images/2.xpm",
			&game->gun_img.gun1.width, &game->gun_img.gun1.height);
	game->gun_img.gun2.addr = mlx_get_data_addr(game->gun_img.gun2.img,
			&game->gun_img.gun2.bits_per_pixel,
			&game->gun_img.gun2.line_length,
			&game->gun_img.gun2.endian);
}

void	print_sprite(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < 500)
	{
		x = 0;
		while (x < SCREENWIDTH)
		{
			paint_on_screen_by_pixel
				(&game->background, x, y, img_px(game->gun_img.gun1, x, y));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->gun_img.gun1.img, 0, 0);
}

void	gun_helper(t_game *game)
{
	int	x;
	int	y;
	int	color;

	x = 0;
	y = 0;
	color = 0;
	if (game->gun)
	{
		while (y < game->gun_img.gun1.height)
		{
			x = 0;
			while (x < game->gun_img.gun1.width)
			{
				color = img_px(game->gun_img.gun2, x, y);
				if (color != 16711905)
					paint_on_screen_by_pixel
						(&game->background, x + SCREENWIDTH, y + 800, color);
				x++;
			}
			y++;
		}
	}
	game->gun = false;
}

void	gun(t_game *game)
{
	int	x;
	int	y;
	int	color;

	x = 0;
	y = 0;
	color = 0;
	while (y < game->gun_img.gun1.height)
	{
		x = 0;
		while (x < game->gun_img.gun1.width)
		{
			color = img_px(game->gun_img.gun1, x, y);
			if (color != 16711905)
				paint_on_screen_by_pixel
					(&game->background, x + SCREENWIDTH, y + 800, color);
			x++;
		}
		y++;
	}
	gun_helper(game);
}

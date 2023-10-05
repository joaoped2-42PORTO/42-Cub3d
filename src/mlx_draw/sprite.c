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

#include "../../includes/cub3d.h"

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

void	gun(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->gun_img.gun1.img, 1080, 700);
	if (game->gun)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->gun_img.gun2.img, 1080, 700);
		game->gun = false;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neddy <neddy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:02:24 by neddy             #+#    #+#             */
/*   Updated: 2023/09/27 16:29:44 by neddy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	img_px(t_image img, int x, int y)
{
	return (*(unsigned int *)((img.addr + (y * img.line_length) + (x
					* img.bits_per_pixel / 8))));
}

int	check_for_x(t_game *game, int texX)
{
	if (game->player.side == 0 && game->player.rayDirX > 0)
		return (IMGPX - texX - 1);
	if (game->player.side == 1 && game->player.rayDirY < 0)
		return (IMGPX - texX - 1);
	return (texX);
}

double	init_wall_x(t_game *game)
{
	double	wallx_tmp;

	if (game->player.side == 0)
		wallx_tmp = game->player.posX + game->player.perpWallDist
			* game->player.rayDirY;
	else
		wallx_tmp = game->player.posY + game->player.perpWallDist
			* game->player.rayDirX;
	wallx_tmp -= floor(wallx_tmp);
	return (wallx_tmp);
}

void	init_walls(t_game *game)
{
	game->wall.wallX = init_wall_x(game);
	game->wall.texX = (int)(game->wall.wallX * (double)(IMGPX));
	game->wall.textposit = (game->wall.drawStart - screenHeight / 2
			+ game->wall.lineHeight / 2) * (1.0 * IMGPX
			/ game->wall.lineHeight);
	game->wall.wallY = game->wall.drawStart;
	game->wall.texX = check_for_x(game, game->wall.texX);
}

void	insert_wall_texture(t_game *game, char wall_texture, int x)
{
	if (game->player.side == 0 && game->player.rayDirX > 0
		&& wall_texture == '1')
		paint_on_screen_by_pixel(&game->background, x, game->wall.wallY,
				img_px(game->wall.s_wall, game->wall.texX, game->wall.texY));
	else if (game->player.side == 0 && game->player.rayDirX < 0
			&& wall_texture == '1')
		paint_on_screen_by_pixel(&game->background, x, game->wall.wallY,
				img_px(game->wall.n_wall, game->wall.texX, game->wall.texY));
	else if (game->player.side == 1 && game->player.rayDirY < 0
			&& wall_texture == '1')
		paint_on_screen_by_pixel(&game->background, x, game->wall.wallY,
				img_px(game->wall.w_wall, game->wall.texX, game->wall.texY));
	else if (game->player.side == 1 && game->player.rayDirX > 0
			&& wall_texture == '1')
		paint_on_screen_by_pixel(&game->background, x, game->wall.wallY,
				img_px(game->wall.e_wall, game->wall.texX, game->wall.texY));
}

void	draw_images_to_game(t_game *game, int x)
{
	char	wall_texture;

	init_walls(game);
	wall_texture = game->map[game->player.mapY][game->player.mapX]; //SegFault
	while (game->wall.wallY < game->wall.drawEnd)
	{
		game->wall.texY = (int)game->wall.textposit & (IMGPX - 1);
		game->wall.textposit += 1.0 * IMGPX / game->wall.lineHeight;
		insert_wall_texture(game, wall_texture, x);
		game->wall.wallY++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped2 <joaoped2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:02:24 by neddy             #+#    #+#             */
/*   Updated: 2023/09/28 13:41:28 by joaoped2         ###   ########.fr       */
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
				16777215);
	else if (game->player.side == 0 && game->player.rayDirX < 0
			&& wall_texture == '1')
		paint_on_screen_by_pixel(&game->background, x, game->wall.wallY,
				16777215);
	else if (game->player.side == 1 && game->player.rayDirY < 0
			&& wall_texture == '1')
		paint_on_screen_by_pixel(&game->background, x, game->wall.wallY,
				16777215);
	else if (game->player.side == 1 && game->player.rayDirX > 0
			&& wall_texture == '1')
		paint_on_screen_by_pixel(&game->background, x, game->wall.wallY,
				16777215);
}

void	draw_images_to_game(t_game *game, int x)
{
	char	wall_texture;
	//double	step;
	int	y;

	y = game->wall.drawStart;
	//init_walls(game);
	wall_texture = game->map[game->player.mapY][game->player.mapX] - 1; //SegFault
	//printf("%c\n", wall_texture);
	// if (game->player.side == 0)
	// 	game->wall.wallX = game->player.posY + game->player.perpWallDist * game->player.rayDirY;
	// else
	// 	game->wall.wallX = game->player.posX + game->player.perpWallDist * game->player.rayDirX;
	// game->wall.wallX -= floor((game->wall.wallX));

	// game->wall.texX = (int)game->wall.wallX * (double)IMGPX;
	// if (game->player.side == 0 && game->player.rayDirX > 0)
	// 	game->wall.texX = IMGPX - game->wall.texX - 1;
	// if (game->player.side == 1 && game->player.rayDirY < 0)
	// 	game->wall.texX = IMGPX - game->wall.texX - 1;
	//step = 1.0 * IMGPX / game->wall.lineHeight;
	// game->wall.textposit = (game->wall.drawStart - 1080 / 2 + game->wall.lineHeight / 2) * step;
	while (y < game->wall.drawEnd)
	{
		//img_px(game->wall.n_wall, x, y)
		paint_on_screen_by_pixel(&game->background, x, y, 16777215);
		// game->wall.texY = (int)game->wall.textposit & (IMGPX - 1);
		// game->wall.textposit += step;
		//insert_wall_texture(game, wall_texture, x);
		y++;
	}

	// while (game->wall.wallY > game->wall.drawEnd)
	// {
	// 	printf("wallY%f\ndrawEnd%d\n", game->wall.wallY, game->wall.drawEnd);
	// 	game->wall.texY = (int)game->wall.textposit & (IMGPX - 1);
	// 	game->wall.textposit += 1.0 * IMGPX / game->wall.lineHeight;
	// 	insert_wall_texture(game, wall_texture, x);
	// 	game->wall.wallY--;
	// }
}

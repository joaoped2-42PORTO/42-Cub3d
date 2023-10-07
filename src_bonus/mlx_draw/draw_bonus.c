/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neddy <neddy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:02:24 by neddy             #+#    #+#             */
/*   Updated: 2023/10/07 16:29:48 by neddy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	img_px(t_image img, int x, int y)
{
	return (*(unsigned int *)((img.addr + (y * img.line_length) + (x
				* img.bits_per_pixel / 8))));
}

void	helpdraw(t_game *game)
{
	if (game->player.side == 0)
		game->wall.wallx = game->player.posy + game->player.perpwalldist
			* game->player.raydiry;
	else
		game->wall.wallx = game->player.posx + game->player.perpwalldist
			* game->player.raydirx;
	game->wall.wallx -= floor((game->wall.wallx));
	game->wall.texx = (int)(game->wall.wallx * (double)IMGPX);
	if (game->player.side == 1 && game->player.raydiry > 0)
		game->wall.texx = IMGPX - game->wall.texx - 1;
	if (game->player.side == 0 && game->player.raydirx < 0)
		game->wall.texx = IMGPX - game->wall.texx - 1;
}

void	helpdraw2(t_game *game, int x, int y)
{
	if (game->player.side == 0 && game->player.raydirx > 0)
		paint_on_screen_by_pixel(&game->background, x, y,
			img_px(game->wall.e_wall, game->wall.texx, game->wall.texy));
	else if (game->player.side == 0 && game->player.raydirx < 0)
		paint_on_screen_by_pixel(&game->background, x, y,
			img_px(game->wall.w_wall, game->wall.texx, game->wall.texy));
	else if (game->player.side == 1 && game->player.raydiry < 0)
		paint_on_screen_by_pixel(&game->background, x, y,
			img_px(game->wall.n_wall, game->wall.texx, game->wall.texy));
	else if (game->player.side == 1 && game->player.raydiry > 0)
		paint_on_screen_by_pixel(&game->background, x, y,
			img_px(game->wall.s_wall, game->wall.texx, game->wall.texy));
}

void	draw_images_to_game(t_game *game, int x)
{
	double	step;
	int		y;

	y = game->wall.drawstart;
	helpdraw(game);
	step = 1.0 * IMGPX / game->wall.lineheight;
	game->wall.texy = (game->wall.drawstart - SCREENWIDTH / 2
			+ game->wall.lineheight / 2) * step;
	while (y < game->wall.drawend)
	{
		game->wall.texy += step;
		helpdraw2(game, x, y);
		y++;
	}
}

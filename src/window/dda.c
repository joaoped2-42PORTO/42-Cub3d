/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neddy <neddy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:13:30 by neddy             #+#    #+#             */
/*   Updated: 2023/09/26 15:47:58 by neddy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	calculate_ray_lenght_forX(t_game *game)
{
	if (game->player.rayDirX == 0)
		game->player.deltaDistX = MAXDOUBLE;
	else
		game->player.deltaDistX = fabs(1 / game->player.rayDirX);
}

void	calculate_ray_lenght_forY(t_game *game)
{
	if (game->player.rayDirY == 0)
		game->player.deltaDistY = MAXDOUBLE;
	else
		game->player.deltaDistY = fabs(1 / game->player.rayDirY);
}

void	calculate_ray_pos(t_game *game)
{
	game->player.cameraX = 2 * game->player.x / (double)screenWidth - 1;
	game->player.rayDirX = game->player.dirX + game->player.planeX
		* game->player.cameraX;
	game->player.rayDirY = game->player.dirX + game->player.planeY
		* game->player.cameraX;
	game->player.mapX = (int)game->player.posX;
	game->player.mapY = (int)game->player.posY;
	game->player.hit = 0;
}

void	calculate_step_forX(t_game *game)
{
	if (game->player.rayDirX < 0)
	{
		game->player.stepX = -1;
		game->player.sideDistX = (game->player.posY - game->player.mapX)
			* game->player.deltaDistX;
	}
	else
	{
		game->player.stepX = 1;
		game->player.sideDistX = (game->player.mapX + 1.0 - game->player.posY)
			* game->player.deltaDistX;
	}
}

void	calculate_step_forY(t_game *game)
{
	if (game->player.rayDirY < 0)
	{
		game->player.stepY = -1;
		game->player.sideDistY = (game->player.posX - game->player.mapY)
			* game->player.deltaDistY;
	}
	else
	{
		game->player.stepY = 1;
		game->player.sideDistY = (game->player.mapY + 1.0 - game->player.posX)
			* game->player.deltaDistY;
	}
}

void	check_next_sqr(t_game *game)
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
}

void	check_hit(t_game *game)
{
	char	curr;

	curr = 0;
	while (game->player.hit == 0)
	{
		check_next_sqr(game);
		curr = game->map[game->player.mapY][game->player.mapX];
		if (curr == '1')
			game->player.hit = 1;
	}
}

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

void	calculate_camera_direction(t_game *game)
{
	if (game->player.side == 0)
		game->player.perpWallDist = (game->player.sideDistX
				- game->player.deltaDistX);
	else
		game->player.perpWallDist = (game->player.sideDistY
				- game->player.deltaDistY);
	game->wall.lineHeight = (int)(screenHeight / game->player.perpWallDist);
	game->wall.drawStart = -game->wall.lineHeight / 2 + screenHeight / 2;
	if (game->wall.drawStart < 0)
		game->wall.drawStart = 0;
	game->wall.drawEnd = game->wall.lineHeight / 2 + screenHeight / 2;
	if (game->wall.drawEnd >= screenHeight)
		game->wall.drawEnd = screenHeight - 1;
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

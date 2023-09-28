/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped2 <joaoped2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:30:02 by joaoped2          #+#    #+#             */
/*   Updated: 2023/09/28 16:11:54 by joaoped2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_player_starting_pos(t_game *game)
{
	if (game->map[game->player.mapY][game->player.mapX] == 'N')
	{
		game->player.dirX= 0.0f;
		game->player.dirY = -1.0f;
		game->player.planeX = -0.66;
		game->player.planeY = 0;
	}
	else if (game->map[game->player.mapY][game->player.mapX] == 'S')
	{
		game->player.dirX= 0.0f;
		game->player.dirY = 1.0f;
		game->player.planeX = 0.66;
		game->player.planeY = 0;
	}
	else if (game->map[game->player.mapY][game->player.mapX] == 'E')
	{
		game->player.dirX= -1.0f;
		game->player.dirY = 0.0f;
		game->player.planeX = 0;
		game->player.planeY = 0.66;
	}
	else if (game->map[game->player.mapY][game->player.mapX] == 'W')
	{
		game->player.dirX= 1.0f;
		game->player.dirY = 0.0f;
		game->player.planeX = 0;
		game->player.planeY = -0.66;
	}
}

void	init_values(t_game *game)
{
	game->player.posX = game->player.mapX;
	game->player.posY = game->player.mapY;
	// game->player.dirX = -1;
	// game->player.dirY = 0;
	// game->player.planeX = 0;
	// game->player.planeY = 0.66;
	game->db.tmpfl = 0.0;
	game->db.tmpint = 0;
	game->ceeling.blue = -1;
	game->ceeling.green = -1;
	game->ceeling.red = -1;
	game->floor.blue = -1;
	game->floor.green = -1;
	game->floor.red = -1;
	game->player.hit = 0;
	game->player.m_speed = 0.08f;
	game->player.r_speed = 0.03f;
	init_player_starting_pos(game);
}

void	init_images(t_game *game)
{
	game->background.img = mlx_new_image(game->mlx, 1920, 1080);
	game->background.addr = mlx_get_data_addr(game->background.img,
												&game->background.bits_per_pixel,
												&game->background.line_length,
												&game->background.endian);
	game->wall.n_wall.img = mlx_xpm_file_to_image(game->mlx, "./images/NO.xpm", &game->wall.n_wall.width, &game->wall.n_wall.height);
	game->wall.n_wall.addr = mlx_get_data_addr(game->wall.n_wall.img,
												&game->wall.n_wall.bits_per_pixel,
												&game->wall.n_wall.line_length,
												&game->wall.n_wall.endian);
	game->wall.s_wall.img = mlx_xpm_file_to_image(game->mlx, "./images/SO.xpm", &game->wall.s_wall.width, &game->wall.s_wall.height);
	game->wall.s_wall.addr = mlx_get_data_addr(game->wall.s_wall.img,
												&game->wall.s_wall.bits_per_pixel,
												&game->wall.s_wall.line_length,
												&game->wall.s_wall.endian);
	game->wall.e_wall.img = mlx_xpm_file_to_image(game->mlx, "./images/EA.xpm", &game->wall.e_wall.width, &game->wall.e_wall.height);
	game->wall.e_wall.addr = mlx_get_data_addr(game->wall.e_wall.img,
												&game->wall.e_wall.bits_per_pixel,
												&game->wall.e_wall.line_length,
												&game->wall.e_wall.endian);
	game->wall.w_wall.img = mlx_xpm_file_to_image(game->mlx, "./images/WE.xpm", &game->wall.w_wall.width, &game->wall.w_wall.height);
	game->wall.w_wall.addr = mlx_get_data_addr(game->wall.w_wall.img,
												&game->wall.w_wall.bits_per_pixel,
												&game->wall.w_wall.line_length,
												&game->wall.w_wall.endian);
}

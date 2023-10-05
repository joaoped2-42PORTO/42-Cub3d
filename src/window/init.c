/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:30:02 by joaoped2          #+#    #+#             */
/*   Updated: 2023/10/05 15:26:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_player_starting_pos2(t_game *game)
{
	if (game->map[game->player.mapy][game->player.mapx] == 'E')
	{
		game->player.dirx = 1.0f;
		game->player.diry = 0.0f;
		game->player.planex = 0;
		game->player.planey = 0.66;
	}
	else if (game->map[game->player.mapy][game->player.mapx] == 'W')
	{
		game->player.dirx = -1.0f;
		game->player.diry = 0.0f;
		game->player.planex = 0;
		game->player.planey = -0.66;
	}
}

void	init_player_starting_pos(t_game *game)
{
	if (game->map[game->player.mapy][game->player.mapx] == 'N')
	{
		game->player.dirx = 0.0f;
		game->player.diry = -1.0f;
		game->player.planex = 0.66;
		game->player.planey = 0;
	}
	else if (game->map[game->player.mapy][game->player.mapx] == 'S')
	{
		game->player.dirx = 0.0f;
		game->player.diry = 1.0f;
		game->player.planex = -0.66;
		game->player.planey = 0;
	}
	init_player_starting_pos2(game);
}

void	init_values(t_game *game)
{
	game->player.posx = game->player.mapx + 0.5;
	game->player.posy = game->player.mapy + 0.5;
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
	game->player.sidedistx = 2;
	game->player.sidedisty = 2;
	init_player_starting_pos(game);
}

void	gun_images(t_game *game)
{
	game->gun_img.gun1.img = mlx_xpm_file_to_image(game->mlx,  "./images/1.xpm",
			&game->gun_img.gun1.width, &game->gun_img.gun1.height);
	game->gun_img.gun1.addr = mlx_get_data_addr(game->gun_img.gun1.img,
			&game->gun_img.gun1.bits_per_pixel,
			&game->gun_img.gun1.line_length,
			&game->gun_img.gun1.endian);
	game->gun_img.gun2.img = mlx_xpm_file_to_image(game->mlx,  "./images/2.xpm",
			&game->gun_img.gun1.width, &game->gun_img.gun1.height);
	game->gun_img.gun2.addr = mlx_get_data_addr(game->gun_img.gun2.img,
			&game->gun_img.gun2.bits_per_pixel,
			&game->gun_img.gun2.line_length,
			&game->gun_img.gun2.endian);
}

void	init_images2(t_game *game)
{
	game->wall.e_wall.img = mlx_xpm_file_to_image(game->mlx, game->e_texture,
			&game->wall.e_wall.width, &game->wall.e_wall.height);
	game->wall.e_wall.addr = mlx_get_data_addr(game->wall.e_wall.img,
			&game->wall.e_wall.bits_per_pixel,
			&game->wall.e_wall.line_length,
			&game->wall.e_wall.endian);
	game->wall.w_wall.img = mlx_xpm_file_to_image(game->mlx, game->w_texture,
			&game->wall.w_wall.width, &game->wall.w_wall.height);
	game->wall.w_wall.addr = mlx_get_data_addr(game->wall.w_wall.img,
			&game->wall.w_wall.bits_per_pixel,
			&game->wall.w_wall.line_length,
			&game->wall.w_wall.endian);
	gun_images(game);
}

void	init_images(t_game *game)
{
	game->background.img = mlx_new_image(game->mlx, 1920, 1080);
	game->background.addr = mlx_get_data_addr(game->background.img,
			&game->background.bits_per_pixel,
			&game->background.line_length,
			&game->background.endian);
	game->wall.n_wall.img = mlx_xpm_file_to_image(game->mlx, game->n_texture,
			&game->wall.n_wall.width, &game->wall.n_wall.height);
	game->wall.n_wall.addr = mlx_get_data_addr(game->wall.n_wall.img,
			&game->wall.n_wall.bits_per_pixel,
			&game->wall.n_wall.line_length,
			&game->wall.n_wall.endian);
	game->wall.s_wall.img = mlx_xpm_file_to_image(game->mlx, game->s_texture,
			&game->wall.s_wall.width, &game->wall.s_wall.height);
	game->wall.s_wall.addr = mlx_get_data_addr(game->wall.s_wall.img,
			&game->wall.s_wall.bits_per_pixel,
			&game->wall.s_wall.line_length,
			&game->wall.s_wall.endian);
	init_images2(game);
}

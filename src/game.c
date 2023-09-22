/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped2 <joaoped2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:59:46 by joaoped2          #+#    #+#             */
/*   Updated: 2023/09/22 15:00:15 by joaoped2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_clean_exit(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_game(game);
	exit(0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == 65307)
		ft_clean_exit(game);
	if (keycode == 119)
		printf("W\n");
	if (keycode == 115)
		printf("S\n");
	if (keycode == 97)
		printf("A\n");
	if (keycode == 100)
		printf("D\n");
	return (0);
}

int	key_release(int keycode)
{
	if (keycode == 119)
		printf("W\n");
	if (keycode == 115)
		printf("S\n");
	if (keycode == 97)
		printf("A\n");
	if (keycode == 100)
		printf("D\n");
	return (0);
}

/* unsigned int	mlx_rgb_to_int(int o, int r, int g, int b)
{
	char	*dst;

	return (o << 24 | r << 16 | g << 8 | b);
} */
void	paint_on_screen_by_pixel(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	print_background(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < screenHeight)
	{
		x = 0;
		while (x < screenWidth)
		{
			if (screenHeight / 2 > y)
				paint_on_screen_by_pixel(&game->background, x, y, 0x00FF00);
			else
				paint_on_screen_by_pixel(&game->background, x, y, 0x0000FF);
			x++;
		}
		y++;
	}
}

void	init_values(t_game *game)
{
	game->player.posX = 22;
	game->player.posY = 12;
	game->player.dirX = -1;
	game->player.dirY = 0;
	game->player.planeX = 0;
	game->player.planeY = 0.66;
	game->ceeling.blue = -1;
	game->ceeling.green = -1;
	game->ceeling.red = -1;
	game->floor.blue = -1;
	game->floor.green = -1;
	game->floor.red = -1;
	game->player.hit = 0;
}

void	init_images(t_game *game)
{
	game->background.img = mlx_new_image(game->mlx, screenWidth, screenHeight);
	game->background.addr = mlx_get_data_addr(game->background.img,
		&game->background.bits_per_pixel, &game->background.line_length,
		&game->background.endian);
}

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
	game->player.rayDirX += game->player.planeX * game->player.cameraX;
	game->player.rayDirY += game->player.planeY * game->player.cameraX;
	game->player.mapX = (int)game->player.posX;
	game->player.mapY = (int)game->player.posY;
}

void	calculate_step_forX(t_game *game)
{
	if (game->player.rayDirX < 0)
	{
		game->player.stepX = -1;
		game->player.sideDistX = (game->player.posX - game->player.mapX)
			* game->player.deltaDistX;
	}
	else
	{
		game->player.stepX = 1;
		game->player.sideDistX = (game->player.mapX + 1.0 - game->player.posX)
			* game->player.deltaDistX;
	}
}

void	calculate_step_forY(t_game *game)
{
	if (game->player.rayDirY < 0)
	{
		game->player.stepY = -1;
		game->player.sideDistY = (game->player.posY - game->player.mapY)
			* game->player.deltaDistY;
	}
	else
	{
		game->player.stepY = 1;
		game->player.sideDistY = (game->player.mapY + 1.0 - game->player.posY)
			* game->player.deltaDistY;
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
		if (game->map[game->player.mapX][game->player.mapY] == '1')
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
	game->player.lineHeight = (int)(screenHeight / game->player.perpWallDist);
	game->player.drawStart = -game->player.lineHeight / 2 + screenHeight / 2;
	if (game->player.drawStart < 0)
		game->player.drawStart = 0;
	game->player.drawEnd = game->player.lineHeight / 2 + screenHeight / 2;
	if (game->player.drawEnd >= screenHeight)
		game->player.drawEnd = screenHeight - 1;
}

void	doalldda(t_game *game)
{
	int	x;

	x = 0;
	while (x < screenWidth)
	{
		game->player.cameraX = 2 * x / (double)screenWidth - 1;
		calculate_ray_pos(game);
		calculate_ray_lenght_forX(game);
		calculate_ray_lenght_forY(game);
		calculate_step_forX(game);
		calculate_step_forY(game);
		performdda(game);
		calculate_camera_direction(game);
		x++;
	}
}

int	render_next_frame(t_game *game)
{
	print_background(game);
	doalldda(game);
	mlx_put_image_to_window(game->mlx, game->win, game->background.img, 0, 0);
	return (0);
}

int	openwindow(t_game *game)
{
	init_values(game);
	game->mlx = mlx_init();
	init_images(game);
	game->win = mlx_new_window(game->mlx, screenHeight, screenWidth, "cub3d");
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_hook(game->win, 17, 1L << 17, ft_clean_exit, game);
	mlx_loop_hook(game->mlx, render_next_frame, game);
	mlx_loop(game->mlx);
	return (0);
}

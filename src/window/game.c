/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neddy <neddy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:59:46 by joaoped2          #+#    #+#             */
/*   Updated: 2023/09/25 10:08:31 by neddy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*void	minimap(t_game *game, int i, int j)
{
	int	x;
	int	y;

	x = j * 10;
	y = i * 10;
	while (y < (i * 10) + 10)								//MINIMAPA!!!!
	{
		x = j * 10;
		while (x < (j * 10) + 10)
		{
			paint_on_screen_by_pixel(&game->background, x, y, 0x00FF00);
			x++;
		}
		y++;
	}
}*/

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

unsigned int	mlx_rgb_to_int(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
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
	while (y < 1080)
	{
		x = 0;
		while (x < 1920)
		{
			if (1080 / 2 > y)
				paint_on_screen_by_pixel(&game->background, x, y, game->f_color);
			else
				paint_on_screen_by_pixel(&game->background, x, y, game->c_color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->background.img, 0, 0);
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
	game->background.img = mlx_new_image(game->mlx, 1920, 1080);
	game->background.addr = mlx_get_data_addr(game->background.img,
												&game->background.bits_per_pixel,
												&game->background.line_length,
												&game->background.endian);
}



void	put_wall(t_game *game, int i, int x)
{
	int j;

	j = 50;
	printf("player y: %d\n", game->player.mapY);
	if (i < game->player.mapY)
		game->img.img = mlx_xpm_file_to_image(game->mlx, "./images/NO.xpm", &j, &j);
	else if(i >= game->player.mapY)
		game->img.img = mlx_xpm_file_to_image(game->mlx, "./images/SO.xpm", &j, &j);
	game->img.addr = mlx_get_data_addr(game->img.img,
												&game->img.bits_per_pixel,
												&game->img.line_length,
												&game->img.endian);
	j = game->img.line_length / 4;
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, x * j , i * j);
	//paint_on_screen_by_pixel(&game->img, game->img.line_length, game->img.endian, game->c_color);
	mlx_destroy_image(game->mlx, game->img.img);
	//experiencia para comecar a criar a imagem
}

void	print_window(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
			{
				put_wall(game, i, j);
			}
			j++;
		}
		i++;
	}

}


int	render_next_frame(t_game *game)
{
	doalldda(game);
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
	print_background(game);							//Isto nao pode estar no loop para ja senao da erro!
	print_window(game);								//Isto nao pode estar no loop para ja senao da erro!
	mlx_loop_hook(game->mlx, render_next_frame, game);
	mlx_loop(game->mlx);
	return (0);
}

// Website link: https://harm-smits.github.io/42docs/projects/cub3d

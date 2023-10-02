/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped2 <joaoped2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:59:46 by joaoped2          #+#    #+#             */
/*   Updated: 2023/10/02 15:53:18 by joaoped2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	put_wall(t_game *game, int i, int x)
{
	int j;

	j = 50;
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

	//printf("Cheguei aqui1:\nposX:%d\nposY:%d\nlength:%zu\nmatrix size:%d\noriginal posX:%d\noriginal posY:%d\n", (int)game->player.posX, (int)game->player.posY, ft_strlen(game->map[(int)game->player.posY]), see_matrix_size(game->map), game->player.mapX, game->player.mapY);

	//printf("X: %d\nY: %d\n", (int)game->player.sideDistX, (int)game->player.sideDistY);
/*	if ((game->player.posX < 1 || (int)game->player.posX > (int)(ft_strlen(game->map[(int)game->player.posY]) - 2) || game->player.posY < 1 || game->player.posY > (see_matrix_size(game->map) - 1)) || ((int)game->player.sideDistY < 1 || (int)game->player.sideDistX < 1))
	{
		//printf("Cheguei aqui:\nposX:%d\nposY:%d\nlength:%zu\nmatrix size:%d\n", (int)game->player.posX, (int)game->player.posY, ft_strlen(game->map[(int)game->player.posY]), see_matrix_size(game->map));
		game->player.posY = game->player.prev_y;
		game->player.posX = game->player.prev_x;
		game->player.sideDistY = game->player.prev_sidy;
		game->player.sideDistX = game->player.prev_sidx;
		game->player.mapY = (int)game->player.posY;
		game->player.mapX = (int)game->player.posX;
		//printf("%i\n", game->map_start_i);
		//printf("X: %f\nY: %f\n", game->player.sideDistX, game->player.sideDistY);
		//exit (0);
	}*/
	//printf("Cheguei aqui2:\nposX:%d\nposY:%d\nlength:%zu\nmatrix size:%d\noriginal posX:%d\noriginal posY:%d\n", (int)game->player.posX, (int)game->player.posY, ft_strlen(game->map[(int)game->player.posY]), see_matrix_size(game->map), game->player.mapX, game->player.mapY);
	print_background(game);
	doalldda(game);
	move_player(game);
	if (game->player.posX > 0 && game->player.posY > 0)
	{
		game->player.prev_x = game->player.posX;
		game->player.prev_y = game->player.posY;
	}
	if (game->player.sideDistX > 0 && game->player.sideDistY > 0)
	{
		game->player.prev_sidx = game->player.sideDistX;
		game->player.prev_sidy = game->player.sideDistY;
	}
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:59:46 by joaoped2          #+#    #+#             */
/*   Updated: 2023/10/05 15:02:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	print_minimap(t_game *game, int i, int j, int color)
{
	int	k;

	k = 0;
	while (k < 10)
	{
		mlx_pixel_put(game->mlx, game->win, j * 10 + k, i * 10, color);
		mlx_pixel_put(game->mlx, game->win, j * 10, i * 10 + k, color);
		mlx_pixel_put(game->mlx, game->win, j * 10 + k, i * 10 + 10, color);
		mlx_pixel_put(game->mlx, game->win, j * 10 + 10, i * 10 + k, color);
		k++;
	}
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
				print_minimap(game, i, j, 0x0000000);
			if (i == (int)game->player.posy && j == (int)game->player.posx)
				print_minimap(game, i, j, 0x00FF0000);
			j++;
		}
		i++;
	}
}

void	gun(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->gun_img.gun1.img, 1080, 700);
	if (game->gun)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->gun_img.gun2.img, 1080, 700);
		game->gun = false;
	}
}


int	render_next_frame(t_game *game)
{
	print_background(game);
	doalldda(game);
	move_player(game);
	print_window(game);
	gun(game);
	return (0);
}

int	openwindow(t_game *game)
{
	init_values(game);
	game->mlx = mlx_init();
	init_images(game);
	game->win = mlx_new_window(game->mlx, SCREENHEIGHT, SCREENWIDTH, "cub3d");
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_hook(game->win, 17, 1L << 17, ft_clean_exit, game);
	mlx_loop_hook(game->mlx, render_next_frame, game);
	mlx_loop(game->mlx);
	return (0);
}

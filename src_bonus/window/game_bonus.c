/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped2 <joaoped2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:59:46 by joaoped2          #+#    #+#             */
/*   Updated: 2023/10/09 10:34:23 by joaoped2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	print_minimap(t_game *game, int i, int j, int color)
{
	int	k;
	int	l;

	k = 0;
	while (k < 10)
	{
		l = 0;
		while (l <= k)
		{
			mlx_pixel_put(game->mlx, game->win, j * 10 + l, i * 10 + k, color);
			mlx_pixel_put(game->mlx, game->win, j * 10 + k, i * 10 + l, color);
			l++;
		}
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
				print_minimap(game, i, j, 0x00336699);
			if (i == (int)game->player.posy && j == (int)game->player.posx)
				print_minimap(game, i, j, 0x00FF0000);
			j++;
		}
		i++;
	}
}

int	render_next_frame(t_game *game)
{
	print_background(game);
	doalldda(game);
	gun(game);
	move_player(game);
	print_window(game);
	return (0);
}

int	openwindow(t_game *game)
{
	init_values(game);
	game->mlx = mlx_init();
	init_images(game);
	game->win = mlx_new_window
		(game->mlx, SCREENHEIGHT, SCREENWIDTH, "cub3d_bonus");
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_hook(game->win, 17, 1L << 17, ft_clean_exit, game);
	mlx_loop_hook(game->mlx, render_next_frame, game);
	mlx_loop(game->mlx);
	return (0);
}

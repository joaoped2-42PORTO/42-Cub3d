/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:59:46 by joaoped2          #+#    #+#             */
/*   Updated: 2023/10/03 17:16:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	put_wall(t_game *game, int i, int x)
{
	int	j;

	j = 50;
	if (i < game->player.mapy)
		game->img.img = mlx_xpm_file_to_image(game->mlx,
				"./images/NO.xpm", &j, &j);
	else if (i >= game->player.mapy)
		game->img.img = mlx_xpm_file_to_image(game->mlx,
				"./images/SO.xpm", &j, &j);
	game->img.addr = mlx_get_data_addr(game->img.img,
			&game->img.bits_per_pixel,
			&game->img.line_length,
			&game->img.endian);
	j = game->img.line_length / 4;
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, x * j, i * j);
	mlx_destroy_image(game->mlx, game->img.img);
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
	print_background(game);
	doalldda(game);
	move_player(game);
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

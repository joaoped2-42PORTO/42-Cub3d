/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped2 <joaoped2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:59:46 by joaoped2          #+#    #+#             */
/*   Updated: 2023/09/21 16:44:50 by joaoped2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	**map(void)
{
	int		**map = {
		{1,1,1,1,1},
		{1,0,0,0,1},
		{1,0,0,0,1},
		{1,0,0,0,1},
		{1,1,1,1,1}
	};
	return (map);
}

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

int	key_press(int keycode,	t_game *game)
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

void	init_values(t_game *game)
{
	game->player.posX = 22;
	game->player.posY = 12;
	game->player.dirX = -1;
	game->player.dirY = 0;
	game->player.planeX = 0;
	game->player.planeY = 0.66;
	game->player.time = 0;
	game->player.oldTime = 0;
}

int	render_next_frame(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}

int	openwindow(t_game *game)
{
	init_values(game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, screenHeight, screenWidth, "cub3d");
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_hook(game->win, 17, 1L << 17, ft_clean_exit, game);
	mlx_loop_hook(game->mlx, render_next_frame, game);
	mlx_loop(game->mlx);
	return (0);
}

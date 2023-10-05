/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:22:47 by huolivei          #+#    #+#             */
/*   Updated: 2023/10/05 15:32:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_game(t_game *game)
{
	int	i;

	i = -1;
	while (game->map[++i])
		free (game->map[i]);
	free (game->map);
	if (game->n_texture)
		free (game->n_texture);
	if (game->s_texture)
		free (game->s_texture);
	if (game->w_texture)
		free (game->w_texture);
	if (game->e_texture)
		free (game->e_texture);
	if (game->floor_texture)
		free (game->floor_texture);
	if (game->ceeling_texture)
		free (game->ceeling_texture);
	free (game);
	exit (1);
}

void	free_matrix(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

int	ft_clean_exit(t_game *game)
{
	if (game->win)
	{
		mlx_clear_window(game->mlx, game->win);
		mlx_destroy_window(game->mlx, game->win);
	}
	mlx_destroy_image(game->mlx, game->gun_img.gun1.img);
	mlx_destroy_image(game->mlx, game->gun_img.gun2.img);
	mlx_destroy_image(game->mlx, game->wall.n_wall.img);
	mlx_destroy_image(game->mlx, game->wall.s_wall.img);
	mlx_destroy_image(game->mlx, game->wall.e_wall.img);
	mlx_destroy_image(game->mlx, game->wall.w_wall.img);
	mlx_destroy_image(game->mlx, game->background.img);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_game(game);
	exit(0);
}

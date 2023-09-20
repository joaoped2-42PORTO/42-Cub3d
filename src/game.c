/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped2 <joaoped2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:59:46 by joaoped2          #+#    #+#             */
/*   Updated: 2023/09/20 14:39:44 by joaoped2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_press(int keycode, t_mlx *mlx)
{
	if (keycode == 65307)
		mlx_destroy_window(mlx->mlx, mlx->win);
	return (0);
}

void	openwindow(void)
{
	t_mlx	*mlx = NULL;

	mlx->mlx = mlx_init();
	if (mlx->mlx == 0)
		printf("Error\n");
	mlx->win = mlx_new_window(mlx->mlx, screenHeight, screenWidth, "cub3d");
	mlx_hook(mlx->win, 2, 1L << 0, key_press, mlx);
	mlx_loop(mlx->mlx);
}

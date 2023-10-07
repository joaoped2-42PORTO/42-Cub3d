/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neddy <neddy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:33:43 by joaoped2          #+#    #+#             */
/*   Updated: 2023/10/07 16:29:48 by neddy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == 65307)
		ft_clean_exit(game);
	if (keycode == 119)
		game->up_move = true;
	if (keycode == 115)
		game->down_move = true;
	if (keycode == 97)
		game->left_move = true;
	if (keycode == 100)
		game->right_move = true;
	if (keycode == 65363)
		game->camera_left = true;
	if (keycode == 65361)
		game->camera_right = true;
	if (keycode == 65507)
		game->gun = true;
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == 119)
		game->up_move = false;
	if (keycode == 115)
		game->down_move = false;
	if (keycode == 97)
		game->left_move = false;
	if (keycode == 100)
		game->right_move = false;
	if (keycode == 65363)
		game->camera_left = false;
	if (keycode == 65361)
		game->camera_right = false;
	if (keycode == 65507)
		game->gun = false;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped2 <joaoped2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:33:43 by joaoped2          #+#    #+#             */
/*   Updated: 2023/10/02 09:19:40 by joaoped2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// Mal
int	key_press(int keycode, t_game *game)
{

	if (keycode == 65307) // ESC
		ft_clean_exit(game);
	if (keycode == 119) // W
		game->up_move = true;
	if (keycode == 115) // S
		game->down_move = true;
	if (keycode == 97) // A
		game->left_move = true;
	if (keycode == 100) // D
		game->right_move = true;
	if (keycode == 65363) // <-
		game->camera_left = true;
	if (keycode == 65361) // ->
		game->camera_right = true;
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == 119) // W
		game->up_move = false;
	if (keycode == 115) // S
		game->down_move = false;
	if (keycode == 97) // A
		game->left_move = false;
	if (keycode == 100) // D
		game->right_move = false;
	if (keycode == 65363) // <-
		game->camera_left = false;
	if (keycode == 65361) // ->
		game->camera_right = false;
	return (0);
}

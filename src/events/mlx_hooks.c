/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped2 <joaoped2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:33:43 by joaoped2          #+#    #+#             */
/*   Updated: 2023/09/27 10:33:58 by joaoped2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

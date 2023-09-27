/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neddy <neddy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:18:58 by joaoped2          #+#    #+#             */
/*   Updated: 2023/09/27 16:19:50 by neddy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	calculate_ray_lenght_forX(t_game *game)
{
	if (game->player.rayDirX == 0)
		game->player.deltaDistX = MAXDOUBLE;
	else
		game->player.deltaDistX = fabs(1 / game->player.rayDirX);
}

void	calculate_ray_lenght_forY(t_game *game)
{
	if (game->player.rayDirY == 0)
		game->player.deltaDistY = MAXDOUBLE;
	else
		game->player.deltaDistY = fabs(1 / game->player.rayDirY);
}

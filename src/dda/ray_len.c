/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:18:58 by joaoped2          #+#    #+#             */
/*   Updated: 2023/10/03 17:16:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	calculate_ray_lenght_forx(t_game *game)
{
	if (game->player.raydirx == 0)
		game->player.deltadistx = MAXDOUBLE;
	else
		game->player.deltadistx = fabs(1 / game->player.raydirx);
}

void	calculate_ray_lenght_fory(t_game *game)
{
	if (game->player.raydiry == 0)
		game->player.deltadisty = MAXDOUBLE;
	else
		game->player.deltadisty = fabs(1 / game->player.raydiry);
}

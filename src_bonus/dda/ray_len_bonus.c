/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_len_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neddy <neddy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:18:58 by joaoped2          #+#    #+#             */
/*   Updated: 2023/10/07 16:29:48 by neddy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

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

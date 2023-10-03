/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:22:55 by joaoped2          #+#    #+#             */
/*   Updated: 2023/10/03 17:16:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_hit(t_game *game)
{
	while (game->player.hit == 0)
	{
		if (game->player.sidedistx < game->player.sidedisty)
		{
			game->player.sidedistx += game->player.deltadistx;
			game->player.mapx += game->player.stepx;
			game->player.side = 0;
		}
		else
		{
			game->player.sidedisty += game->player.deltadisty;
			game->player.mapy += game->player.stepy;
			game->player.side = 1;
		}
		if (game->player.mapx < 0 || game->player.mapy < 0
			|| game->player.mapy >= (see_matrix_size(game->map) - 1)
			|| game->player.mapx
			>= ((int)ft_strlen(game->map[game->player.mapy]) - 2))
			game->player.hit = 2;
		else if (game->map[game->player.mapy][game->player.mapx] == '1')
			game->player.hit = 1;
	}
}

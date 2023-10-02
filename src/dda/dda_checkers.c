/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped2 <joaoped2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:22:55 by joaoped2          #+#    #+#             */
/*   Updated: 2023/10/02 10:37:33 by joaoped2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_hit(t_game *game)
{
	while (game->player.hit == 0)
	{
		if (game->player.sideDistX < game->player.sideDistY)
		{
			game->player.sideDistX += game->player.deltaDistX;
			game->player.mapX += game->player.stepX;
			game->player.side = 0;
		}
		else
		{
			game->player.sideDistY += game->player.deltaDistY;
			game->player.mapY += game->player.stepY;
			game->player.side = 1;
		}
		if (game->player.mapY < 1 )
		{
			game->player.hit = 1;
			game->player.mapY = 0;
			return ;
		}
		if (game->player.mapY > (see_matrix_size(game->map) - 1))
		{
			game->player.hit = 1;
			game->player.mapY = see_matrix_size(game->map) - 1;
			return ;
		}
		if (game->player.mapX < 0)
		{
			game->player.hit = 1;
			game->player.mapX = 0;
			return ;
		}
		if (game->player.mapX > (int)ft_strlen(game->map[game->player.mapY]) - 2)
		{
			game->player.hit = 1;
			game->player.mapX = (int)ft_strlen(game->map[game->player.mapY] - 2);
			return ;
		}
		if (game->map[game->player.mapY][game->player.mapX] == '1')
			game->player.hit = 1;
	}
}

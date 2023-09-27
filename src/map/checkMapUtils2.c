/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMapUtils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neddy <neddy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:31:06 by huolivei          #+#    #+#             */
/*   Updated: 2023/09/27 16:18:11 by neddy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	loop_map_closed(t_game *game, int i)
{
	if (game->map[i][0] != '1' && game->map[i][0] != ' '
			&& game->map[i][0] != '\t' && game->map[i][0] != '\n')
		return (true);
	return (false);
}

bool	loop_inside_map(t_game *game, int i, int j)
{
	if (game->map[i - 1][j] == '\0' || game->map[i + 1][j] == '\0'
		|| game->map[i][j - 1] == '\0' || game->map[i][j + 1] == '\0')
		return (true);
	if (game->map[i - 1][j] == ' ' || game->map[i + 1][j] == ' '
		|| game->map[i][j - 1] == ' ' || game->map[i][j + 1] == ' ')
		return (true);
	return (false);
}

void	count_player(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'N' || game->map[i][j] == 'S'
		|| game->map[i][j] == 'E' || game->map[i][j] == 'W')
	{
		game->player.mapX = j;
		game->player.mapY = i;
		game->player_direction = game->map[i][j];
		game->player_count++;
	}
}

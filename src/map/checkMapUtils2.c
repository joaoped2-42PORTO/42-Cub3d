/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMapUtils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:31:06 by huolivei          #+#    #+#             */
/*   Updated: 2023/10/03 17:16:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	loop_map_closed(t_game *game, int i)
{
	if (game->map[i][0] == '\n' && game->map[i][1] == '\0')
		return (true);
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
		game->player.mapx = j;
		game->player.mapy = i;
		game->player_direction = game->map[i][j];
		game->player_count++;
	}
}

void	change_max_x(t_game *game, char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '\t')
				game->max_x += 3;
			j++;
		}
		i++;
	}
}

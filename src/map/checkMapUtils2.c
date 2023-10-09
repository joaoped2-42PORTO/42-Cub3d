/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMapUtils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped2 <joaoped2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:31:06 by huolivei          #+#    #+#             */
/*   Updated: 2023/10/09 10:27:39 by joaoped2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	put_tabs(t_game *game, int i, int *tab)
{
	game->map[i][(*tab)++] = ' ';
	game->map[i][(*tab)++] = ' ';
	game->map[i][(*tab)++] = ' ';
	game->map[i][(*tab)++] = ' ';
}

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
	if (game->map[i - 1][j] == '\n' || game->map[i + 1][j] == '\n'
		|| game->map[i][j - 1] == '\n' || game->map[i][j + 1] == '\n')
		return (true);
	return (false);
}

bool	count_player(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'N' || game->map[i][j] == 'S'
		|| game->map[i][j] == 'E' || game->map[i][j] == 'W')
	{
		if (game->map[i - 1][j] == '\0' || game->map[i + 1][j] == '\0'
			|| game->map[i][j - 1] == '\0' || game->map[i][j + 1] == '\0')
			return (true);
		if (game->map[i - 1][j] == ' ' || game->map[i + 1][j] == ' '
			|| game->map[i][j - 1] == ' ' || game->map[i][j + 1] == ' ')
			return (true);
		if (game->map[i - 1][j] == '\n' || game->map[i + 1][j] == '\n'
			|| game->map[i][j - 1] == '\n' || game->map[i][j + 1] == '\n')
			return (true);
		game->player.mapx = j;
		game->player.mapy = i;
		game->player_direction = game->map[i][j];
		game->player_count++;
	}
	return (false);
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

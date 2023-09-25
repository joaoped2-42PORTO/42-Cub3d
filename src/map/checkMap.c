/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:26:27 by huolivei          #+#    #+#             */
/*   Updated: 2023/09/22 17:42:15 by huolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

void	loop_change_map(t_game *game, int i, char **new_map)
{
	int	j;
	int	tab;

	j = 0;
	tab = 0;
	while (new_map[i][j])
	{
		if (new_map[i][j] == '\t')
		{
			game->map[i][tab++] = ' ';
			game->map[i][tab++] = ' ';
			game->map[i][tab++] = ' ';
			game->map[i][tab++] = ' ';
		}
		else
			game->map[i][tab++] = new_map[i][j];
		j++;
	}
}

bool	inside_map(t_game *game)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = (int)ft_strlen(game->map[i]) - 1;
	while (i < (game->max_y))
	{
		j = 0;
		size = (int)ft_strlen(game->map[i]) - 1;
		while (j < size)
		{
			count_player(game, i, j);
			if (game->map[i][j] == '0')
			{
				if (loop_inside_map(game, i, j))
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_char(char **str, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
	{
		j = -1;
		while (str[i][++j] != '\0')
		{
			if (str[i][j] == '1' || str[i][j] == '0'
				|| str[i][j] == '\n' || str[i][j] == 'N'
				|| str[i][j] == 'S' || str[i][j] == 'E'
				|| str[i][j] == 'W' || str[i][j] == ' '
				|| str[i][j] == '\t')
				continue ;
			else
				return (false);
		}
	}
	game->max_y = see_matrix_size(game->map);
	return (true);
}

bool	check_map(t_game *game)
{
	if (game->map[game->map_start_i] == 0)
		return (false);
	while (game->map[game->map_start_i][0] == '\n')
		game->map_start_i++;
	change_map(game);
	if (!check_char(game->map, game))
		return (false);
	if (!map_closed(game))
		return (false);
	if (!inside_map(game) || game->player_count != 1)
		return (false);
	return (true);
}
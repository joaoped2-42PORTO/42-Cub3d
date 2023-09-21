/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:26:27 by huolivei          #+#    #+#             */
/*   Updated: 2023/09/21 18:03:19 by huolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"






bool	check_char(char **str, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
	{
		if (game->max_x < (int)ft_strlen(game->map[i]))
			game->max_x = (int)ft_strlen(game->map[i]);
		j = -1;
		while (str[i][++j])
		{
			if (str[i][j] == '1' || str[i][j] == '0' || str[i][j] == '\n'
				|| str[i][j] == 'N' || str[i][j] == 'S' || str[i][j] == 'E'
				|| str[i][j] == 'W' || str[i][j] == ' ')
				continue ;
			else
				return (false);
		}
	}
	game->max_y = see_matrix_size(game->map);
	printf("%d\n %d\n", game->max_x, game->max_y);
	return (true);
}

bool	check_map(t_game *game)
{
	while (game->map[game->map_start_i][0] == '\n')
	{
		game->map_start_i++;
		if (game->map[game->map_start_i] == 0)
			return (false);
	}
	if (game->map[game->map_start_i] == 0)
		return (false);
	change_map(game);
	if (!check_char(game->map, game))
		return (false);
	if (!map_closed(game))
		return (false);
	return (true);
}

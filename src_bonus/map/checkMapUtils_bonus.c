/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMapUtils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neddy <neddy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:02:26 by huolivei          #+#    #+#             */
/*   Updated: 2023/10/07 16:29:48 by neddy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

bool	map_max_y(t_game *game, int i)
{
	if (game->map[game->max_y - 1][i] != '1'
			&& game->map[game->max_y - 1][i] != ' '
			&& game->map[game->max_y - 1][i] != '\n'
			&& game->map[game->max_y - 1][i] != '\t')
		return (true);
	return (false);
}

bool	map_first_line(t_game *game, int i)
{
	if (game->map[0][i] != '1' && game->map[0][i] != ' '
			&& game->map[0][i] != '\n' && game->map[0][i] != '\t')
		return (true);
	return (false);
}

bool	loop_map(t_game *game, int size, int *i)
{
	size = (int)ft_strlen(game->map[*i]);
	if (game->map[*i][size - 2] != '1' && game->map[*i][size - 2] != ' '
		&& game->map[*i][size - 2] != '\n' && game->map[*i][size - 2] != '\t')
		return (false);
	(*i)++;
	return (true);
}

bool	map_closed(t_game *game)
{
	int	i;
	int	size;

	size = (int)ft_strlen(game->map[0]);
	i = -1;
	while (game->map[0][++i])
		if (map_first_line(game, i))
			return (false);
	i = -1;
	while (game->map[game->max_y - 1][++i])
		if (map_max_y(game, i))
			return (false);
	i = -1;
	while (game->map[++i])
		if (loop_map_closed(game, i))
			return (false);
	i = 0;
	while (game->map[i][size - 2])
	{
		if (!loop_map(game, size, &i))
			return (false);
		if (game->map[i] == 0)
			break ;
	}
	return (true);
}

void	change_map(t_game *game)
{
	char	**new_map;
	int		i;

	i = see_matrix_size(game->map) - game->map_start_i + 1;
	new_map = ft_calloc(i, sizeof(char *));
	i = 0;
	while (game->map[game->map_start_i])
	{
		new_map[i] = ft_strdup(game->map[game->map_start_i++]);
		i++;
	}
	new_map[i] = 0;
	i = -1;
	while (game->map[++i])
		free (game->map[i]);
	free (game->map);
	change_max_x(game, new_map);
	game->map = ft_calloc(see_matrix_size(new_map) + 1, sizeof(char *));
	i = -1;
	while (new_map[++i])
	{
		game->map[i] = ft_calloc(game->max_x + 1, sizeof(char));
		loop_change_map(game, i, new_map);
	}
	free_matrix(new_map);
}

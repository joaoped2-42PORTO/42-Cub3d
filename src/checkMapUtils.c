/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMapUtils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:02:26 by huolivei          #+#    #+#             */
/*   Updated: 2023/09/21 18:10:16 by huolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	loop_map(t_game *game, int size, int *i)
{
	size = (int)ft_strlen(game->map[*i]);
	if (game->map[*i][size - 2] != '1' && game->map[*i][size - 2] != ' ' && game->map[*i][size - 2] != '\n')
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
		if (game->map[0][i] != '1' && game->map[0][i] != ' ' && game->map[0][i] != '\n')
			return (false);
	i = -1;
	while (game->map[game->max_y - 1][++i])
		if (game->map[game->max_y - 1][i] != '1' && game->map[game->max_y - 1][i] != ' ' && game->map[game->max_y - 1][i] != '\n')
			return (false);
	i = -1;
	while (game->map[++i])
		if (game->map[i][0] != '1' && game->map[i][0] != ' ')
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
	game->map = ft_calloc(see_matrix_size(new_map) + 1, sizeof(char *));
	i = -1;
	while (new_map[++i])
		game->map[i] = ft_strdup(new_map[i]);
	free_matrix(new_map);
	i = -1;
	while (game->map[++i])
		printf("%s", game->map[i]);
}

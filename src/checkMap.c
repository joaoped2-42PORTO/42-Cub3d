/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:26:27 by huolivei          #+#    #+#             */
/*   Updated: 2023/09/21 16:00:03 by huolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	map_closed(t_game *game)
{
	int	i;

	i = -1;
	while (game->map[0][++i])
		if (game->map[0][i] != '1' && game->map[0][i] != ' ' && game->map[0][i] != '\n')
			return (false);
	i = -1;
	while (game->map[game->max_y][++i])
		if (game->map[game->max_y][i] != '1' && game->map[game->max_y][i] != ' ' && game->map[game->max_y][i] != '\n')
			return (false);
	i = -1;
	while (game->map[++i])
		if (game->map[i][0] != '1' && game->map[i][0] != ' ')
			return (false);
	i = 0;
	while (game->map[i][ft_strlen(game->map[i] - 1)])
	{
		if (game->map[i][ft_strlen(game->map[i] - 1)] != '1' && game->map[i][ft_strlen(game->map[i]) - 1] != ' ' && game->map[i][ft_strlen(game->map[i]) - 1] != '\n')
			return (false);
		i++;
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

bool	check_char(char **str, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
	{
		if (game->max_x < (int)ft_strlen(game->map[i]))
			game->max_x = (int)ft_strlen(game->map[i]) - 1;
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
	if (!check_char(game->map, game) || !map_closed(game))
		return (false);
	return (true);
}

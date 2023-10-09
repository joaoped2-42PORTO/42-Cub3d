/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped2 <joaoped2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:26:27 by huolivei          #+#    #+#             */
/*   Updated: 2023/10/09 10:28:07 by joaoped2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	loop_change_map(t_game *game, int i, char **new_map)
{
	int	j;
	int	tab;

	j = -1;
	tab = 0;
	while (new_map[i][++j])
	{
		if (new_map[i][j] == '\t')
		{
			if (j != 0 && (new_map[i][j - 1] == '1'
				|| new_map[i][j - 1] == ' '))
			{
				game->map[i][tab++] = ' ';
				game->map[i][tab++] = ' ';
			}
			else
				put_tabs(game, i, &tab);
		}
		else
			game->map[i][tab++] = new_map[i][j];
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
		while (j <= size)
		{
			if (count_player(game, i, j))
				return (false);
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

void	change_string_textures(t_game *game)
{
	char	*aux;

	aux = ft_strtrim(game->n_texture, "\n");
	free(game->n_texture);
	game->n_texture = ft_strdup(aux);
	free(aux);
	aux = ft_strtrim(game->s_texture, "\n");
	free(game->s_texture);
	game->s_texture = ft_strdup(aux);
	free(aux);
	aux = ft_strtrim(game->e_texture, "\n");
	free(game->e_texture);
	game->e_texture = ft_strdup(aux);
	free(aux);
	aux = ft_strtrim(game->w_texture, "\n");
	free(game->w_texture);
	game->w_texture = ft_strdup(aux);
	free(aux);
}

bool	check_map(t_game *game)
{
	if (game->map[game->map_start_i] == 0)
		return (false);
	change_map(game);
	change_string_textures(game);
	if (!check_char(game->map, game))
		return (false);
	if (!map_closed(game))
		return (false);
	if (!inside_map(game) || game->player_count != 1)
		return (false);
	return (true);
}

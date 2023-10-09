/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapElements.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:42:36 by huolivei          #+#    #+#             */
/*   Updated: 2023/09/22 17:31:59 by huolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	check_elements_w(t_game *game)
{
	char	**split;

	split = ft_split(game->w_texture, ' ');
	if (see_matrix_size(split) > 2 || see_matrix_size(split) < 2)
	{
		free_matrix(split);
		return (false);
	}
	free(game->w_texture);
	split[1] += 2;
	game->w_texture = ft_strdup(split[1]);
	split[1] -= 2;
	free_matrix(split);
	if (!check_textures_ext(game->w_texture))
		return (false);
	return (true);
}

int	west_east(t_game *game, char *str)
{
	if (ft_strlen(str) > 3 && str[0] == 'W' && str[1] == 'E')
	{
		if (!game->w_texture)
		{
			game->w_texture = ft_strdup(str);
			if (!check_elements_w(game))
				return (-1);
			return (1);
		}
		else
			return (-1);
	}
	else if (ft_strlen(str) > 3 && str[0] == 'E' && str[1] == 'A')
	{
		if (!game->e_texture)
		{
			game->e_texture = ft_strdup(str);
			if (!check_elements_e(game))
				return (-1);
			return (1);
		}
		else
			return (-1);
	}
	return (0);
}

int	north_south(t_game *game, char *str)
{
	if (ft_strlen(str) > 3 && str[0] == 'N' && str[1] == 'O')
	{
		if (!game->n_texture)
		{
			game->n_texture = ft_strdup(str);
			if (!check_elements_n(game))
				return (-1);
			return (1);
		}
		else
			return (-1);
	}
	else if (ft_strlen(str) > 3 && str[0] == 'S' && str[1] == 'O')
	{
		if (!game->s_texture)
		{
			game->s_texture = ft_strdup(str);
			if (!check_elements_s(game))
				return (-1);
			return (1);
		}
		else
			return (-1);
	}
	return (0);
}

int	ceeling_floor(t_game *game, char *str)
{
	if (ft_strlen(str) > 2 && str[0] == 'F')
	{
		if (!game->floor_texture)
		{
			game->floor_texture = ft_strdup(str);
			if (!check_elements_f(game))
				return (-1);
			return (1);
		}
		else
			return (-1);
	}
	else if (ft_strlen(str) > 2 && str[0] == 'C')
	{
		if (!game->ceeling_texture)
		{
			game->ceeling_texture = ft_strdup(str);
			if (!check_elements_c(game))
				return (-1);
			return (1);
		}
		else
			return (-1);
	}
	return (0);
}

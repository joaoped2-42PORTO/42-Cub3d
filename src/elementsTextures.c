/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elementsTextures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:12:27 by huolivei          #+#    #+#             */
/*   Updated: 2023/09/21 11:41:05 by huolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	check_elements_s(t_game *game)
{
	char	**split;

	split = ft_split(game->s_texture, ' ');
	if (see_matrix_size(split) > 2)
	{
		free_matrix(split);
		return (false);
	}
	free (game->s_texture);
	split[1] += 2;
	game->s_texture = ft_strdup(split[1]);
	split[1] -= 2;
	free_matrix(split);
	if (!check_textures_ext(game->s_texture))
		return (false);
	return (true);
}

bool	check_elements_e(t_game *game)
{
	char	**split;

	split = ft_split(game->e_texture, ' ');
	if (see_matrix_size(split) > 2)
	{
		free_matrix(split);
		return (false);
	}
	free (game->e_texture);
	split[1] += 2;
	game->e_texture = ft_strdup(split[1]);
	split[1] -= 2;
	free_matrix(split);
	if (!check_textures_ext(game->e_texture))
		return (false);
	return (true);
}

bool	check_elements_n(t_game *game)
{
	char	**split;

	split = ft_split(game->n_texture, ' ');
	if (see_matrix_size(split) > 2)
	{
		free_matrix(split);
		return (false);
	}
	free (game->n_texture);
	split[1] += 2;
	game->n_texture = ft_strdup(split[1]);
	split[1] -= 2;
	free_matrix(split);
	if (!check_textures_ext(game->n_texture))
		return (false);
	return (true);
}

bool	check_elements_f(t_game *game)
{
	char	**split;

	split = ft_split(game->floor_texture, ' ');
	if (see_matrix_size(split) > 2)
	{
		free_matrix(split);
		return (false);
	}
	free (game->floor_texture);
	game->floor_texture = ft_strdup(split[1]);
	free_matrix(split);
	if (!check_colors(game->floor_texture))
		return (false);
	return (true);
}

bool	check_elements_c(t_game *game)
{
	char	**split;

	split = ft_split(game->ceeling_texture, ' ');
	if (see_matrix_size(split) > 2)
	{
		free_matrix(split);
		return (false);
	}
	free (game->ceeling_texture);
	game->ceeling_texture = ft_strdup(split[1]);
	free_matrix(split);
	if (!check_colors(game->ceeling_texture))
		return (false);
	return (true);
}

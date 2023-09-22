/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:22:47 by huolivei          #+#    #+#             */
/*   Updated: 2023/09/22 16:25:52 by huolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_game(t_game *game)
{
	int	i;

	i = -1;
	while (game->map[++i])
		free (game->map[i]);
	free (game->map);
	if (game->n_texture)
		free (game->n_texture);
	if (game->s_texture)
		free (game->s_texture);
	if (game->w_texture)
		free (game->w_texture);
	if (game->e_texture)
		free (game->e_texture);
	if (game->floor_texture)
		free (game->floor_texture);
	if (game->ceeling_texture)
		free (game->ceeling_texture);
	free (game);
	exit (1);
}

void	free_matrix(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

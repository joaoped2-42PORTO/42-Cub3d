/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapCheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:22:50 by huolivei          #+#    #+#             */
/*   Updated: 2023/10/04 19:35:49 by huolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	read_string(char *str, t_game *game)
{
	if (str[0] == '\n')
		return (0);
	else if ((ft_strlen(str) > 3 && str[0] == 'N' && str[1] == 'O')
		|| (ft_strlen(str) > 3 && str[0] == 'S' && str[1] == 'O'))
		return (north_south(game, str));
	else if ((ft_strlen(str) > 3 && str[0] == 'W' && str[1] == 'E')
		|| (ft_strlen(str) > 3 && str[0] == 'E' && str[1] == 'A'))
		return (west_east(game, str));
	else if ((ft_strlen(str) > 2 && str[0] == 'F')
		|| (ft_strlen(str) > 2 && str[0] == 'C'))
		return (ceeling_floor(game, str));
	else
		return (-1);
}

bool	valid_map(t_game *game)
{
	int	i;

	game->element_qty = 0;
	i = 0;
	while (!game->n_texture || !game->ceeling_texture || !game->floor_texture
		|| !game->e_texture || !game->w_texture || !game->s_texture)
	{
		game->element_qty += read_string(game->map[i], game);
		i++;
		if (!game->map[i] || game->element_qty < 0)
			return (false);
	}
	while (game->map[i][0] == '\n')
	{
		i++;
		if (!game->map[i])
			return (false);
	}
	if (game->element_qty == 6)
		game->map_start_i = i;
	else
		return (false);
	if (check_map(game))
		return (true);
	return (false);
}

int	size_map(t_game *game)
{
	int		i;
	char	*buffer;

	buffer = NULL;
	i = 0;
	while (1)
	{
		buffer = get_next_line(game->fd);
		if (buffer == NULL)
			break ;
		if (game->max_x < (int) ft_strlen(buffer))
			game->max_x = (int) ft_strlen(buffer);
		free(buffer);
		i++;
	}
	free(buffer);
	close(game->fd);
	return (i);
}

void	read_map(t_game *game, char **av)
{
	int		i;
	char	*buffer;

	free(game->map);
	game->max_y = size_map(game) + 1;
	buffer = NULL;
	i = 0;
	game->fd = open(av[1], O_RDONLY);
	game->map = malloc(game->max_y * sizeof(char *));
	while (1)
	{
		buffer = get_next_line(game->fd);
		if (buffer == NULL)
			break ;
		game->map[i] = ft_strdup(buffer);
		free(buffer);
		i++;
	}
	game->map[i] = 0;
	free(buffer);
	close(game->fd);
}

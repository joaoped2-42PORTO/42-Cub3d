/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapCheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped2 <joaoped2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:22:50 by huolivei          #+#    #+#             */
/*   Updated: 2023/09/20 14:13:07 by joaoped2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	read_string(char *str, t_game *game)
{
	if (str[0] == '\n')
		return (0);
	else if (ft_strlen(str) > 3 && str[0] == 'N' && str[1] == 'O')
	{
		game->n_texture = ft_strdup(str);
		return (1);
	}
	else if (ft_strlen(str) > 3 && str[0] == 'S' && str[1] == 'O')
	{
		game->s_texture = ft_strdup(str);
		return (1);
	}
	else if (ft_strlen(str) > 3 && str[0] == 'W' && str[1] == 'E')
	{
		game->w_texture = ft_strdup(str);
		return (1);
	}
	else if (ft_strlen(str) > 3 && str[0] == 'E' && str[1] == 'A')
	{
		game->e_texture = ft_strdup(str);
		return (1);
	}
	else if (ft_strlen(str) > 2 && str[0] == 'F')
	{
		game->floor_texture = ft_strdup(str);
		return (1);
	}
	else if (ft_strlen(str) > 2 && str[0] == 'C')
	{
		game->ceeling_texture = ft_strdup(str);
		return (1);
	}
	else
		return (-1);
}

bool	valid_map(t_game *game)
{
	int	i;
	int	qty;

	qty = 0;
	i = 0;
	while (1)
	{
		if (game->max_x < (int)ft_strlen(game->map[i]))
			game->max_x = (int)ft_strlen(game->map[i]);
		qty += read_string(game->map[i], game);
		i++;
		if (!game->map[i] || qty < 0)
			break ;
	}
	if (qty == 6)
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
		// printf("%s", game->map[i]);
		i++;
	}
	game->map[i] = 0;
	free(buffer);
	close(game->fd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:51:31 by huolivei          #+#    #+#             */
/*   Updated: 2023/09/20 15:00:01 by huolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	see_matrix_size(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);

}

bool	check_input(char **av, t_game *game)
{
	char	**split;
	int		size;

	game->fd = open(av[1], O_RDONLY);
	split = ft_split(av[1], '.');
	size = see_matrix_size(split) - 1;
	if (ft_strlen("cub") != ft_strlen(split[size]) || ft_strncmp("cub",
			split[size], 3) || game->fd == -1)
	{
		printf("Error\n Map extension is wrong!'n");
		free_matrix(split);
		close(game->fd);
		return (false);
	}
	read_map(game, av);
	if (!valid_map(game))
	{
		free_matrix(split);
		return (false);
	}
	free_matrix(split);
	return (true);
}

void	init(t_game *game)
{
	game->max_x = 0;
	game->max_y = 0;
	game->n_texture = NULL;
	game->s_texture = NULL;
	game->w_texture = NULL;
	game->e_texture = NULL;
	game->floor_texture = NULL;
	game->ceeling_texture = NULL;
}

int	main(int ac, char **av)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	init(game);
	if (ac != 2)
	{
		printf("Wrong number of arguments!\n");
		free(game);
		return (1);
	}
	if (!check_input(av, game))
	{
		free(game);
		return (1);
	}
	openwindow();
	free_game(game);
	//return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neddy <neddy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:51:31 by huolivei          #+#    #+#             */
/*   Updated: 2023/09/26 16:27:11 by neddy            ###   ########.fr       */
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
		printf("Error\nSomethis is wrong with the permissions or extension\n");
		free_matrix(split);
		if (game->fd != -1)
			close(game->fd);
		return (false);
	}
	free_matrix(split);
	read_map(game, av);
	if (game->map[0] == 0 || !valid_map(game))
	{
		printf("Error\nSomething is wrong with the %s!\n", av[1]);
		return (false);
	}
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
	game->player_count = 0;
	game->map = ft_calloc(1, sizeof(char *));
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
		free_game(game);
		return (1);
	}
	openwindow(game);
	free_game(game);
	return (0);
}

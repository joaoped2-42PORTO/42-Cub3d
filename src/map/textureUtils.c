/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textureUtils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:15:28 by huolivei          #+#    #+#             */
/*   Updated: 2023/09/22 17:32:03 by huolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	string_is_digit(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!ft_isdigit(str[i]) && str[i] != '\n')
			return (false);
	return (true);
}

bool	check_textures_ext(char *str)
{
	int		i;
	int		fd;
	char	*aux;

	aux = ft_strtrim(str, "\n");
	i = -1;
	fd = open(aux, O_RDONLY);
	free (aux);
	if (fd < 0)
		return (false);
	close(fd);
	while (str[++i])
		if (str[i] == '.')
			break ;
	if (str[i] != '.' || str[i + 1] != 'x' || str[i + 2] != 'p'
		|| str[i + 3] != 'm' || str[i + 4] != '\n')
		return (false);
	return (true);
}

bool	check_colors(char *str)
{
	char	**split;
	int		i;

	i = -1;
	split = ft_split(str, ',');
	if (see_matrix_size(split) != 3 || !string_is_digit(split[0])
		|| !string_is_digit(split[1]) || !string_is_digit(split[2]))
	{
		free_matrix(split);
		return (false);
	}
	while (split[++i])
	{
		if (ft_atoi(split[i]) < 0 || ft_atoi(split[i]) > 255)
		{
			free_matrix(split);
			return (false);
		}
	}
	free_matrix(split);
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textureUtils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:15:28 by huolivei          #+#    #+#             */
/*   Updated: 2023/09/20 14:50:30 by huolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	check_textures(char *str)
{
	int	i;
	int	fd;

	fd = 0;
	i = -1;
	while (str[++i])
		if (str[i] == '.')
			break ;
	if (str[i] != '.' && str[i + 1] != 'x' && str[i + 2] != 'p'
		&& str[i + 3] != 'm' && str[i + 4] != '\0')
		return (false);
}

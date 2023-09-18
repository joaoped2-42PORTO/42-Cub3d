/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 01:15:40 by huolivei          #+#    #+#             */
/*   Updated: 2023/09/18 12:55:54 by huolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t n, size_t daty)
{
	char	*total;
	size_t	i;

	total = malloc(n * daty);
	i = 0;
	if (!total)
		return (NULL);
	while (i < (n * daty))
	{
		total[i] = '\0';
		i++;
	}
	return (total);
}

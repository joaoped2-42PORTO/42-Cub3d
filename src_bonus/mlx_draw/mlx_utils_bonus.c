/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neddy <neddy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:33:00 by joaoped2          #+#    #+#             */
/*   Updated: 2023/10/07 16:29:48 by neddy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

unsigned int	mlx_rgb_to_int(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	paint_on_screen_by_pixel(t_image *img, int x, int y, int color)
{
	char	*dst;

	if (color == (int)0x00980088 || color == (int)16711935)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

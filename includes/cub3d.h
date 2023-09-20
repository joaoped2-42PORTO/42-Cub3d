/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped2 <joaoped2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:22:56 by huolivei          #+#    #+#             */
/*   Updated: 2023/09/20 14:26:39 by joaoped2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define screenHeight 1920
# define screenWidth 1080
# include "../libft/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_game
{
	char	**map;
	int		fd;
	int		max_x;
	int		max_y;
	char	*n_texture;
	char	*s_texture;
	char	*e_texture;
	char	*w_texture;
	char	*floor_texture;
	char	*ceeling_texture;
}			t_game;

typedef struct s_player
{
	float	player_y;
	float	player_x;
}			t_player;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}			t_mlx;


/* 			mapCheck.c				*/
void		read_map(t_game *game, char **av);
int			size_map(t_game *game);
bool		valid_map(t_game *game);

/* 			cleaner.c				*/
void		free_game(t_game *game);
void		free_matrix(char **str);

/* Testing */
void	openwindow(void);

#endif

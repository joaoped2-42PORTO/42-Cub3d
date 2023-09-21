/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped2 <joaoped2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:22:56 by huolivei          #+#    #+#             */
/*   Updated: 2023/09/21 16:44:55 by joaoped2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define screenHeight 1920
# define screenWidth 1080
# include "../libft/libft.h"
# include <../minilibx-linux/mlx.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_player
{
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
	double cameraX;
	double rayDirX;
	double rayDirY;
	int mapX;
	int mapY;
	double sideDistX;
	double sideDistY;
	double deltaDistX;
	double deltaDistY;
	double perpWallDist;
	int stepX;
	int stepY;
	int hit;
	int side;
	int lineHeight;
	int drawStart;
	int drawEnd;
}			t_player;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*north_texture;
	void	*south_texture;
	void	*west_texture;
	void	*east_texture;
	void	*floor_texture;
	void	*ceeling_texture;
}			t_mlx;

typedef	struct	s_game {
	char	**map;
	int		fd;
	int		max_x;
	int		max_y;
	int		map_start_i;
	char	*n_texture;
	char	*s_texture;
	char	*e_texture;
	char	*w_texture;
	char	*floor_texture;
	char	*ceeling_texture;
	t_player	player;
	void	*mlx;
	void	*win;
}			t_game;

/* 			cub3d.c				 */
int		see_matrix_size(char **str);
bool	check_input(char **av, t_game *game);

/* 			mapCheck.c			 */
void	read_map(t_game *game, char **av);
int		size_map(t_game *game);
bool	valid_map(t_game *game);

/* 			mapCheck.c				*/
void		read_map(t_game *game, char **av);
int			size_map(t_game *game);
bool		valid_map(t_game *game);

/* 			cleaner.c			 */
void	free_game(t_game *game);
void	free_matrix(char **str);

/* Testing */
int	openwindow(t_game *game);

/* 			mapElements.c		 */
int		west_east(t_game *game, char *str);
int		north_south(t_game *game, char *str);
int		ceeling_floor(t_game *game, char *str);
bool	check_elements_w(t_game *game);

/* 			elementTextures.c	 */
bool	check_elements_s(t_game *game);
bool	check_elements_e(t_game *game);
bool	check_elements_n(t_game *game);
bool	check_elements_f(t_game *game);
bool	check_elements_c(t_game *game);

/* 			textureUtils.c		 */
bool	check_textures_ext(char *str);
//bool	mlx_textures(t_game *game);
bool	check_colors(char *str);
bool	string_is_digit(char *str);

#endif

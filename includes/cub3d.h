/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neddy <neddy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:22:56 by huolivei          #+#    #+#             */
/*   Updated: 2023/09/26 16:30:05 by neddy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define screenHeight 1920
# define screenWidth 1080
# define MAXDOUBLE 1e30
# define IMGPX 50
# include "../libft/libft.h"
# include <../minilibx-linux/mlx.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}			t_image;

typedef struct s_wall
{
	double wallX;
	double wallY;
	int lineHeight;
	int drawStart;
	int drawEnd;
	int texX;
	int texY;
	double textposit;
	t_image n_wall;
	t_image s_wall;
	t_image e_wall;
	t_image w_wall;
}			t_wall;


typedef struct s_player
{
	int		x;
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
	float	m_speed;
	float	r_speed;
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

typedef struct s_colors
{
	int		red;
	int		green;
	int		blue;
}			t_colors;

typedef	struct	s_game {
	char	**map;
	char	player_direction;
	int		fd;
	int		max_x;				// ATENCAO! tem que ser -1 por causa do \n e \0
	int		max_y;
	int		map_start_i;
	int		player_count;
	unsigned int		f_color;
	unsigned int		c_color;
	char	*n_texture;
	char	*s_texture;
	char	*e_texture;
	char	*w_texture;
	char	*floor_texture;
	char	*ceeling_texture;
	t_player	player;
	void	*mlx;
	void	*win;
	t_image	img;
	t_image background;
	t_colors	floor;
	t_colors	ceeling;
	t_wall		wall;
}			t_game;

/* 			cub3d.c				 */
int		see_matrix_size(char **str);
bool	check_input(char **av, t_game *game);

/* 			mapCheck.c				*/
void		read_map(t_game *game, char **av);
int			size_map(t_game *game);
bool		valid_map(t_game *game);

/* 			cleaner.c			 */
void	free_game(t_game *game);
void	free_matrix(char **str);

/* Testing in game.c*/
int	openwindow(t_game *game);
unsigned int	mlx_rgb_to_int(int r, int g, int b);

/* 			dda.c			 */
void	doalldda(t_game *game);

/* 			window/draw		 */
void	draw_images_to_game(t_game *game, int x);
void	paint_on_screen_by_pixel(t_image *img, int x, int y, int color);
void	draw_images_to_game(t_game *game, int x);

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

/* 			checkMap.c			 */
bool	check_map(t_game *game);
bool	check_char(char **str, t_game *game);
bool	inside_map(t_game *game);
void	loop_change_map(t_game *game, int i, char **new_map);
void	change_max_x(t_game *game, char **str);

/* 			checkMapUtils.c		 */
void	change_map(t_game *game);
bool	map_closed(t_game *game);
bool	map_first_line(t_game *game, int i);
bool	map_max_y(t_game *game, int i);
bool	loop_map(t_game *game, int size, int *i);

/* 			checkMapUtils2.c	 */
bool	loop_map_closed(t_game *game, int i);
bool	loop_inside_map(t_game *game, int i, int j);
void	count_player(t_game *game, int i, int j);

#endif

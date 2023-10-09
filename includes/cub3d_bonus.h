/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped2 <joaoped2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:33:25 by marvin            #+#    #+#             */
/*   Updated: 2023/10/09 10:30:01 by joaoped2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# define SCREENHEIGHT 1920
# define SCREENWIDTH 1080
# define MAXDOUBLE 1e30
# define IMGPX 50
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_image
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				width;
	int				height;
}					t_image;

typedef struct s_wall
{
	double			wallx;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				texx;
	double			texy;
	t_image			n_wall;
	t_image			s_wall;
	t_image			e_wall;
	t_image			w_wall;
}					t_wall;

typedef struct s_gun
{
	t_image			gun1;
	t_image			gun2;
}					t_gun;

typedef struct s_player
{
	int				x;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			camerax;
	double			raydirx;
	double			raydiry;
	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	float			m_speed;
	float			r_speed;
}					t_player;

typedef struct s_mlx
{
	void			*mlx;
	void			*win;
	void			*north_texture;
	void			*south_texture;
	void			*west_texture;
	void			*east_texture;
	void			*floor_texture;
	void			*ceeling_texture;
}					t_mlx;

typedef struct s_colors
{
	int				red;
	int				green;
	int				blue;
}					t_colors;

typedef struct s_game
{
	bool			up_move;
	bool			down_move;
	bool			left_move;
	bool			right_move;
	bool			camera_left;
	bool			camera_right;
	bool			gun;
	char			**map;
	char			player_direction;
	int				fd;
	int				max_x;
	int				max_y;
	int				map_start_i;
	int				player_count;
	int				element_qty;
	unsigned int	f_color;
	unsigned int	c_color;
	char			*n_texture;
	char			*s_texture;
	char			*e_texture;
	char			*w_texture;
	char			*floor_texture;
	char			*ceeling_texture;
	t_player		player;
	void			*mlx;
	void			*win;
	t_image			img;
	t_image			background;
	t_colors		floor;
	t_colors		ceeling;
	t_wall			wall;
	t_gun			gun_img;
}					t_game;

/* 			cub3d.c					*/
int					see_matrix_size(char **str);
bool				check_input(char **av, t_game *game);

/* 			mapCheck.c				*/
void				read_map(t_game *game, char **av);
int					size_map(t_game *game);
bool				valid_map(t_game *game);

/* 			cleaner.c				*/
void				free_game(t_game *game);
void				free_matrix(char **str);
int					ft_clean_exit(t_game *game);

/* 			mapElements.c			*/
int					west_east(t_game *game, char *str);
int					north_south(t_game *game, char *str);
int					ceeling_floor(t_game *game, char *str);
bool				check_elements_w(t_game *game);

/* 			elementTextures.c		*/
bool				check_elements_s(t_game *game);
bool				check_elements_e(t_game *game);
bool				check_elements_n(t_game *game);
bool				check_elements_f(t_game *game);
bool				check_elements_c(t_game *game);

/* 			textureUtils.c			*/
bool				check_textures_ext(char *str);
// bool	mlx_textures(t_game *game);
bool				check_colors(char *str);
bool				string_is_digit(char *str);

/* 			checkMap.c				*/
bool				check_map(t_game *game);
bool				check_char(char **str, t_game *game);
bool				inside_map(t_game *game);
void				loop_change_map(t_game *game, int i, char **new_map);
void				change_string_textures(t_game *game);

/* 			checkMapUtils.c			*/
void				change_map(t_game *game);
bool				map_closed(t_game *game);
bool				map_first_line(t_game *game, int i);
bool				map_max_y(t_game *game, int i);
bool				loop_map(t_game *game, int size, int *i);

/* 			checkMapUtils2.c		*/
bool				loop_map_closed(t_game *game, int i);
bool				loop_inside_map(t_game *game, int i, int j);
bool				count_player(t_game *game, int i, int j);
void				change_max_x(t_game *game, char **str);
void				put_tabs(t_game *game, int i, int *tab);

/* 			window/game.c			*/
int					render_next_frame(t_game *game);
int					openwindow(t_game *game);
void				print_minimap(t_game *game, int i, int j, int color);

/*			window/init.c			*/
void				init_values(t_game *game);
void				init_images(t_game *game);

/* 			mlx_draw/draw_background.c		*/
void				print_background(t_game *game);

/* 			mlx_draw/draw.c			*/
int					img_px(t_image img, int x, int y);
int					check_for_x(t_game *game, int texx);
double				init_wall_x(t_game *game);
void				init_walls(t_game *game);
void				insert_wall_texture(t_game *game, int x, int y);
void				draw_images_to_game(t_game *game, int x);

/* 			mlx_draw/mlx_utils.c		*/
unsigned int		mlx_rgb_to_int(int r, int g, int b);
void				paint_on_screen_by_pixel(t_image *img, int x, int y,
						int color);
int					create_trgb(int t, int r, int g, int b);

/* 			mlx_draw/sprite.c		*/
void				gun_images(t_game *game);
void				gun(t_game *game);

/*			events/mlx_hooks.c 		*/
int					key_press(int keycode, t_game *game);
int					key_release(int keycode, t_game *game);

/* 			events/player_mov.c		*/
void				move_player(t_game *game);
void				move_up(t_game *game);
void				move_down(t_game *game);
void				move_left(t_game *game);
void				move_right(t_game *game);

/* 			events/camer_mov.c		 */
void				camera_left(t_game *game);
void				camera_right(t_game *game);

/* 			dda/calc_cam_dir.c			*/
void				calculate_camera_direction(t_game *game);

/* 			dda/calc_step.c				*/
void				calculate_step_forx(t_game *game);
void				calculate_step_fory(t_game *game);

/* 			dda/dda_checkers.c		*/
void				check_hit(t_game *game);

/* 			dda/dda.c				*/
void				doalldda(t_game *game);

/*			dda/ray_len.c			*/
void				calculate_ray_lenght_forx(t_game *game);
void				calculate_ray_lenght_fory(t_game *game);

/*			dda/ray_pos.c			*/
void				calculate_ray_pos(t_game *game);

#endif

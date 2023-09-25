/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neddy <neddy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:59:46 by joaoped2          #+#    #+#             */
/*   Updated: 2023/09/25 10:08:31 by neddy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_clean_exit(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_game(game);
	exit(0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == 65307)
		ft_clean_exit(game);
	if (keycode == 119)
		printf("W\n");
	if (keycode == 115)
		printf("S\n");
	if (keycode == 97)
		printf("A\n");
	if (keycode == 100)
		printf("D\n");
	return (0);
}

int	key_release(int keycode)
{
	if (keycode == 119)
		printf("W\n");
	if (keycode == 115)
		printf("S\n");
	if (keycode == 97)
		printf("A\n");
	if (keycode == 100)
		printf("D\n");
	return (0);
}

/* unsigned int	mlx_rgb_to_int(int o, int r, int g, int b)
{
	char	*dst;
	char	*dst;

	return (o << 24 | r << 16 | g << 8 | b);
} */
void	paint_on_screen_by_pixel(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	print_background(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < screenHeight)
	{
		x = 0;
		while (x < screenWidth)
		{
			if (screenHeight / 2 > y)
				paint_on_screen_by_pixel(&game->background, x, y, 0x00FF00);
			else
				paint_on_screen_by_pixel(&game->background, x, y, 0x0000FF);
			x++;
		}
		y++;
	}
}

void	init_values(t_game *game)
{
	game->player.posX = 22;
	game->player.posY = 12;
	game->player.dirX = -1;
	game->player.dirY = 0;
	game->player.planeX = 0;
	game->player.planeY = 0.66;
	game->ceeling.blue = -1;
	game->ceeling.green = -1;
	game->ceeling.red = -1;
	game->floor.blue = -1;
	game->floor.green = -1;
	game->floor.red = -1;
	game->player.hit = 0;
}

void	init_images(t_game *game)
{
	game->background.img = mlx_new_image(game->mlx, screenWidth, screenHeight);
	game->background.addr = mlx_get_data_addr(game->background.img,
												&game->background.bits_per_pixel,
												&game->background.line_length,
												&game->background.endian);
}

/*
sideDistX and sideDistY are initially the distance the ray has to travel from
its start position to the first x-side and the first y-side. Later in the code they
will be incremented while steps are taken.

deltaDistX and deltaDistY are the distance the ray has to travel to go from 1 x-side to the next x-side,
or from 1 y-side to the next y-side. The following image shows the initial sideDistX,
sideDistY and deltaDistX and deltaDistY:
*/
void	calculate_ray_lenght_forX(t_game *game)
{
	if (game->player.rayDirX == 0)
		game->player.deltaDistX = MAXDOUBLE;
	else
		game->player.deltaDistX = fabs(1 / game->player.rayDirX);
}

void	calculate_ray_lenght_forY(t_game *game)
{
	if (game->player.rayDirY == 0)
		game->player.deltaDistY = MAXDOUBLE;
	else
		game->player.deltaDistY = fabs(1 / game->player.rayDirY);
}

/*
The ray starts at the position of the player (posX, posY).

cameraX is the x-coordinate on the camera plane that the current x-coordinate of the screen represents,
	done this way so that the right side of the screen will get coordinate 1,
	the center of the screen gets coordinate 0,
	and the left side of the screen gets coordinate -1. Out of this,
	the direction of the ray can be calculated as the sum of the direction vector,
	and a part of the plane vector.
	This has to be done both for the x and y coordinate of the vector
	(since adding two vectors is adding their x-coordinates,
	and adding their y-coordinates).
*/
/*
mapX and mapY represent the current square of the map the ray is in.
The ray position itself is a floating point number and contains both info about in which square of the map we are,
and where in that square we are, but mapX and mapY are only the coordinates of that square.
*/
void	calculate_ray_pos(t_game *game)
{
	game->player.rayDirX = game->player.dirX + game->player.planeX
		* game->player.cameraX;
	game->player.rayDirY = game->player.dirX + game->player.planeY
		* game->player.cameraX;
	game->player.mapX = (int)game->player.posX;
	game->player.mapY = (int)game->player.posY;
}

/*
Now, before the actual DDA can start, first stepX, stepY, and the initial sideDistX and sideDistY still have to be calculated.

If the ray direction has a negative x-component, stepX is -1, if the ray direciton has a positive x-component it's +1. If the x-component is 0, it doesn't matter what value stepX has since it'll then be unused.
The same goes for the y-component.

If the ray direction has a negative x-component, sideDistX is the distance from the ray
starting position to the first side to the left, if the ray direciton has a positive x-component
the first side to the right is used instead.
The same goes for the y-component, but now with the first side above or below the position.
For these values, the integer value mapX is used and the real position subtracted from it,
and 1.0 is added in some of the cases depending if the side to the left or right, of the top or the bottom is used.
Then you get the perpendicular distance to this side, so multiply it with deltaDistX or deltaDistY
to get the real Euclidean distance.
*/

/*
calculate step and initial sideDist
*/
void	calculate_step_forX(t_game *game)
{
	if (game->player.rayDirX < 0)
	{
		game->player.stepX = -1;
		game->player.sideDistX = (game->player.posX - game->player.mapX)
			* game->player.deltaDistX;
	}
	else
	{
		game->player.stepX = 1;
		game->player.sideDistX = (game->player.mapX + 1.0 - game->player.posX)
			* game->player.deltaDistX;
	}
}

void	calculate_step_forY(t_game *game)
{
	if (game->player.rayDirY < 0)
	{
		game->player.stepY = -1;
		game->player.sideDistY = (game->player.posY - game->player.mapY)
			* game->player.deltaDistY;
	}
	else
	{
		game->player.stepY = 1;
		game->player.sideDistY = (game->player.mapY + 1.0 - game->player.posY)
			* game->player.deltaDistY;
	}
}

/*
Now the actual DDA starts. It's a loop that increments the ray with 1 square every time,
until a wall is hit. Each time, either it jumps a square in the x-direction (with stepX)
or a square in the y-direction (with stepY), it always jumps 1 square at once. If the ray's
direction would be the x-direction, the loop will only have to jump a square in the x-direction
everytime, because the ray will never change its y-direction. If the ray is a bit sloped to the
y-direction, then every so many jumps in the x-direction, the ray will have to jump one square
in the y-direction. If the ray is exactly the y-direction, it never has to jump in the x-direction, etc...

sideDistX and sideDistY get incremented with deltaDistX with every jump in their direction, and
mapX and mapY get incremented with stepX and stepY respectively.

When the ray has hit a wall, the loop ends, and then we'll know whether an x-side or y-side of
a wall was hit in the variable "side", and what wall was hit with mapX and mapY. We won't know
exactly where the wall was hit however, but that's not needed in this case because we won't use
textured walls for now.
*/

void	performdda(t_game *game)
{
	while (game->player.hit == 0)
	{
		if (game->player.sideDistX < game->player.sideDistY)
		{
			game->player.sideDistX += game->player.deltaDistX;
			game->player.mapX += game->player.stepX;
			game->player.side = 0;
		}
		else
		{
			game->player.sideDistY += game->player.deltaDistY;
			game->player.mapY += game->player.stepY;
			game->player.side = 1;
		}
		if (game->map[game->player.mapX][game->player.mapY] == '1')
			game->player.hit = 1;
	}
}
/*
This perpenducular distance is called "perpWallDist" in the code.
One way to compute it is to use the formula for shortest distance
from a point to a line, where the point is where the wall was hit,
and the line is the camera plane
However, it can be computed simpler than that: due to how deltaDist
and sideDist were scaled by a factor of |rayDir| above, the length
of sideDist already almost equals perpWallDist. We just need to
subtract deltaDist once from it, going one step back, because in the
DDA steps above we went one step further to end up inside the wall.

Depending on whether the ray hit an X side or Y side, the formula
is computed using sideDistX, or sideDistY.
*/
void	calculate_camera_direction(t_game *game)
{
	if (game->player.side == 0)
		game->player.perpWallDist = (game->player.sideDistX
				- game->player.deltaDistX);
	else
		game->player.perpWallDist = (game->player.sideDistY
				- game->player.deltaDistY);
	/*
	Now that we have the calculated distance (perpWallDist),
	we can calculate the height of the line that has to be
	drawn on screen: this is the inverse of perpWallDist,
	and then multiplied by h, the height in pixels of the screen,
	to bring it to pixel coordinates. You can of course also multiply
	it with another value, for example 2*h, if you want to walls
	to be higher or lower. The value of h will make the walls look
	like cubes with equal height, width and depth, while large values
	will create higher boxes (depending on your monitor).

	Then out of this lineHeight (which is thus the height of the vertical
	line that should be drawn), the start and end position of where we should
	really draw are calculated. The center of the wall should be at the center
	of the screen, and if these points lie outside the screen, they're capped to 0 or h-1.
	*/
	//Calculate height of line to draw on screen
	game->player.lineHeight = (int)(screenHeight / game->player.perpWallDist);
	//calculate lowest and highest pixel to fill in current stripe
	game->player.drawStart = -game->player.lineHeight / 2 + screenHeight / 2;
	if (game->player.drawStart < 0)
		game->player.drawStart = 0;
	game->player.drawEnd = game->player.lineHeight / 2 + screenHeight / 2;
	if (game->player.drawEnd >= screenHeight)
		game->player.drawEnd = screenHeight - 1;
}

void	doalldda(t_game *game)
{
	int	x;

	x = 0;
	while (x < screenWidth)
	{
		//calculate ray position and direction
		game->player.cameraX = 2 * x / (double)screenWidth - 1;//x-coordinate in camera space
		calculate_ray_pos(game); //Explained above
		calculate_ray_lenght_forX(game); //Explained above
		calculate_ray_lenght_forY(game); //Explained above
		calculate_step_forX(game); //Explained above
		calculate_step_forY(game); //Explained above
		performdda(game); //Explained above
		calculate_camera_direction(game);
		x++;
	}
}

int	render_next_frame(t_game *game)
{
	print_background(game);
	doalldda(game);
	mlx_put_image_to_window(game->mlx, game->win, game->background.img, 0, 0);
	return (0);
}

int	openwindow(t_game *game)
{
	init_values(game);
	game->mlx = mlx_init();
	init_images(game);
	game->win = mlx_new_window(game->mlx, screenHeight, screenWidth, "cub3d");
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_hook(game->win, 17, 1L << 17, ft_clean_exit, game);
	mlx_loop_hook(game->mlx, render_next_frame, game);
	mlx_loop(game->mlx);
	return (0);
}

// Website link: https://harm-smits.github.io/42docs/projects/cub3d

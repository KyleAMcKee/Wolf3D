/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 19:14:41 by kmckee            #+#    #+#             */
/*   Updated: 2018/01/26 16:47:46 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h> //REMOVE

# define HEIGHT 800
# define WIDTH 800
# define A 0
# define S 1
# define D 2
# define W 13
# define ESC 53

typedef struct	s_mini
{
	int		*pixel_str;
	void	*mlx;
	void	*win;
	void	*img;
	int		bbp;
	int 	size_line;
	int		endian;
	int		height;
	int		width;
}				t_mini;

typedef struct	s_map
{
	int		map[1000][1000];
	int		x_map;
	int		y_map;
	int		width;
	int		height;
}				t_map;

typedef struct	s_cam
{
	double	x_camera;
	double	x_plane;
	double	y_plane;
	void	*mlx;
	void	*win;
}				t_cam;

typedef struct	s_rays
{
	int		*pixel_str;
	void	*img;
	int		bbp;
	int		size_line;
	int		endian;
	double	x_pos;
	double	y_pos;
	double	x_dir;
	double	y_dir;
	double	x_ray_dir;
	double	y_ray_dir;
	double	x_side_dist;
	double	y_side_dist;
	double	delta_x;
	double	delta_y;
	double	perp_wall_dist;
	int		x_step;
	int		y_step;
	//int		hit;
	//int		side;
	//int		x_map;
	//int		y_map;
	int		line_height;
	int		draw_start;
	int		draw_end;
}				t_rays;

typedef struct	s_master
{
	t_mini	*mini;
	t_cam	*cam;
	t_map	*map;
	t_rays	*rays;
	void	(*table[128])(struct s_master *);
}				t_master;

/*
**	-----RAY CASTING-----
*/

void	raycast(t_master *master);
void	set_dir(t_master *master);
void	set_vars(t_master *master, int x);
void	set_constants(t_master *master);

/*
**	-----MAP DRAWING-----
*/
void	create_walls(t_master *master);
void	destroy_walls(t_master *master);
void	draw_walls(t_master *master, int x, int side);

/*
**	-----KEY EVENTS-----
*/

void	init_hooks(t_master *master);
void	jump_table(t_master *master);

/*
** -----MINI MAP-----
*/

void	drawminimap(t_master *master);
void	drawsquare(t_master *master, int index, int color);

/*
**	-----ERROR HANDLING-----
*/

int	incorrect_args(int error_num);

#endif

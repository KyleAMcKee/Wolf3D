/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 19:14:41 by kmckee            #+#    #+#             */
/*   Updated: 2018/02/01 19:54:27 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <math.h>
# include <stdlib.h>

# define HEIGHT 800
# define WIDTH 800
# define A 0
# define S 1
# define D 2
# define W 13
# define UP 126
# define LEFT 123
# define DOWN 125
# define RIGHT 124
# define ONE 18
# define TWO 19
# define TAB 48
# define ESC 53

# define MAP master->map
# define CAM master->cam
# define MINI master->mini
# define RAYS master->rays
# define MOUSE master->mouse
# define TEX master->texture

typedef struct	s_texture
{
	void		*img[15];
	int			*pixel_str[15];
	int			bpp;
	int			size_line;
	int			endian;
	int			w;
	int			h;
	int			tex1;
	int			tex2;
	int			tex3;
	int			tex4;
	int			floor;
	int			sky;
}				t_texture;

typedef struct	s_mouse
{
	int			x;
	int			y;
	int			old_x;
	int			old_y;
}				t_mouse;

typedef struct	s_mini
{
	int			*pixel_str;
	void		*mlx;
	void		*win;
	void		*img;
	int			bbp;
	int			size_line;
	int			endian;
	int			height;
	int			width;
}				t_mini;

typedef struct	s_map
{
	int			map[1000][1000];
	int			x_map;
	int			y_map;
	int			width;
	int			height;
}				t_map;

typedef struct	s_cam
{
	double		x_camera;
	double		x_plane;
	double		y_plane;
	void		*mlx;
	void		*win;
}				t_cam;

typedef struct	s_rays
{
	int			*pixel_str;
	int			*end_str;
	void		*img;
	void		*end_img;
	int			bbp;
	int			size_line;
	int			endian;
	double		x_pos;
	double		y_pos;
	double		x_dir;
	double		y_dir;
	double		x_ray_dir;
	double		y_ray_dir;
	double		x_side_dist;
	double		y_side_dist;
	double		delta_x;
	double		delta_y;
	double		perp_wall_dist;
	double		wall_x;
	double		x_step;
	double		y_step;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		floor_x;
	double		floor_y;
	double		current_floor_x;
	double		current_floor_y;
	double		current_dist;
	int			height;
	int			width;
	int			move;
}				t_rays;

typedef struct	s_master
{
	t_mini		*mini;
	t_cam		*cam;
	t_map		*map;
	t_rays		*rays;
	t_mouse		*mouse;
	t_texture	*texture;
	int			shrek_mode;
	int			count;
	void		(*table[128])(struct s_master *);
}				t_master;

/*
**  -----INITIALIZE MAP / GAME-----
*/

void			create_structs(t_master *master);
void			start_game(t_master *master, int height);
int				read_map(t_master *master, int fd, int h);
void			set_constants(t_master *master);
void			determine_start(t_master *master);

/*
**	-----RAY CASTING-----
*/

void			raycast(t_master *master);
void			set_dir(t_master *master);
void			set_vars(t_master *master, int x);
void			set_constants(t_master *master);

/*
**	-----MAP DRAWING-----
*/

void			draw_walls(t_master *master, int x, int side);
void			draw_floor(t_master *master, int x, int side);
void			textures(t_master *master);
int				shader(t_master *master, int color);

/*
**	-----KEY EVENTS-----
*/

void			init_hooks(t_master *master);
void			jump_table(t_master *master);
void			key_w(t_master *master);
void			key_a(t_master *master);
void			key_s(t_master *master);
void			key_d(t_master *master);
void			key_one(t_master *master);
void			key_two(t_master *master);
void			key_tab(t_master *master);
void			display_usage(t_master *master);
int				key_press(int keycode, t_master *master);
int				mouse(int x, int y, t_master *master);

/*
** -----MINI MAP-----
*/

void			drawminimap(t_master *master);
void			drawsquare(t_master *master, int index, int color);

/*
**	-----ERROR HANDLE / EXIT-----
*/

int				error_handle(int error_num);
void			exit_game(t_master *master);

#endif

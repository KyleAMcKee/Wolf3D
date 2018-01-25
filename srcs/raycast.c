/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 14:49:59 by kmckee            #+#    #+#             */
/*   Updated: 2018/01/25 11:18:51 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	set_constants(t_master *master)
{	
	master->rays->x_pos = 8; // How to
	master->rays->y_pos = 3; // Determine these?
	master->rays->x_dir = -1;
	master->rays->y_dir = 0;
	master->cam->x_plane = 0;
	master->cam->y_plane = 0.66;
	master->mini->width = master->map->width * 10;
	master->mini->height = master->map->height * 10;
	master->cam->mlx = mlx_init();
	master->mini->win = mlx_new_window(master->cam->mlx, master->mini->width, master->mini->height, "Mini Map");
	master->cam->win = mlx_new_window(master->cam->mlx, HEIGHT, WIDTH, "Raycaster");
}

void	set_vars(t_master *master, int x)
{
	master->map->x_map = (int)master->rays->x_pos;
	master->map->y_map = (int)master->rays->y_pos;
	master->cam->x_camera = (2 * x / (double)WIDTH) - 1;
	master->rays->x_ray_dir = master->rays->x_dir + master->cam->x_plane * master->cam->x_camera; 
	master->rays->y_ray_dir = master->rays->y_dir + master->cam->y_plane * master->cam->x_camera;
	master->rays->delta_x = fabs(1 / master->rays->x_ray_dir);	
	master->rays->delta_y = fabs(1 / master->rays->y_ray_dir);
}

void	set_dir(t_master *master)
{
	if (master->rays->x_ray_dir < 0)
	{
		master->rays->x_step = -1;
		master->rays->x_side_dist = (master->rays->x_pos - master->map->x_map) * master->rays->delta_x;
	}
	else
	{
		master->rays->x_step = 1;
		master->rays->x_side_dist = (master->map->x_map + 1.0 - master->rays->x_pos) * master->rays->delta_x;
	}
	//master->rays->x_ray_dir < 0 ? master->rays->x_step = -1 : master->rays->x_step = 1;
	if (master->rays->y_ray_dir < 0)
	{
		master->rays->y_step = -1;
		master->rays->y_side_dist = (master->rays->y_pos - master->map->y_map) * master->rays->delta_y;
	}	
	else
	{
		master->rays->y_step = 1;
		master->rays->y_side_dist = (master->map->y_map + 1.0 - master->rays->y_pos) * master->rays->delta_y;
	}
}

void	raycast(t_master *master)
{
	int x;
	int hit;
	int side;

	x = -1;
	create_walls(master);
	while (++x < WIDTH)
	{
		hit = 0;
		set_vars(master, x);
		set_dir(master);
		while (hit == 0)
		{
			if (master->rays->x_side_dist < master->rays->y_side_dist)
			{
				master->rays->x_side_dist += master->rays->delta_x;
				master->map->x_map += master->rays->x_step;
				side = 0;
			}
			else
			{
				master->rays->y_side_dist += master->rays->delta_y;
				master->map->y_map += master->rays->y_step;
				side = 1;
			}
			if (master->map->map[master->map->x_map][master->map->y_map] > 0)
				hit = 1;	
		}
		if (side == 0)
			master->rays->perp_wall_dist = (master->map->x_map - master->rays->x_pos + (1 - master->rays->x_step) / 2) / master->rays->x_ray_dir;
		else
			master->rays->perp_wall_dist = (master->map->y_map - master->rays->y_pos + (1 - master->rays->y_step) / 2) / master->rays->y_ray_dir;
		master->rays->line_height = (int)(HEIGHT / master->rays->perp_wall_dist);
		draw_walls(master, x, side);
	}
	destroy_walls(master);
}

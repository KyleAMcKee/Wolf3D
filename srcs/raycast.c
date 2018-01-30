/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 14:49:59 by kmckee            #+#    #+#             */
/*   Updated: 2018/01/29 16:38:06 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	set_constants(t_master *master)
{	
	RAYS->x_pos = 8; // How to
	RAYS->y_pos = 3; // Determine these?
	RAYS->x_dir = -1;
	RAYS->y_dir = 0;
	CAM->x_plane = 0;
	CAM->y_plane = 0.66;
	MINI->width = MAP->width * 10;
	MINI->height = MAP->height * 10;
	CAM->mlx = mlx_init();
	MINI->win = mlx_new_window(CAM->mlx, MINI->width, MINI->height, "Mini Map");
	CAM->win = mlx_new_window(CAM->mlx, HEIGHT, WIDTH, "Raycaster");
}

void	set_vars(t_master *master, int x)
{
	MAP->x_map = (int)RAYS->x_pos;
	MAP->y_map = (int)RAYS->y_pos;
	CAM->x_camera = (2 * x / (double)WIDTH) - 1;
	RAYS->x_ray_dir = RAYS->x_dir + CAM->x_plane * CAM->x_camera; 
	RAYS->y_ray_dir = RAYS->y_dir + CAM->y_plane * CAM->x_camera;
	RAYS->delta_x = fabs(1 / RAYS->x_ray_dir);	
	RAYS->delta_y = fabs(1 / RAYS->y_ray_dir);
}

void	set_dir(t_master *master)
{
	if (RAYS->x_ray_dir < 0)
	{
		RAYS->x_step = -1;
		RAYS->x_side_dist = (RAYS->x_pos - MAP->x_map) * RAYS->delta_x;
	}
	else
	{
		RAYS->x_step = 1;
		RAYS->x_side_dist = (MAP->x_map + 1.0 - RAYS->x_pos) * RAYS->delta_x;
	}
	if (RAYS->y_ray_dir < 0)
	{
		RAYS->y_step = -1;
		RAYS->y_side_dist = (RAYS->y_pos - MAP->y_map) * RAYS->delta_y;
	}	
	else
	{
		RAYS->y_step = 1;
		RAYS->y_side_dist = (MAP->y_map + 1.0 - RAYS->y_pos) * RAYS->delta_y;
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
			if (RAYS->x_side_dist < RAYS->y_side_dist)
			{
				RAYS->x_side_dist += RAYS->delta_x;
				MAP->x_map += RAYS->x_step;
				side = 0;
			}
			else
			{
				RAYS->y_side_dist += RAYS->delta_y;
				MAP->y_map += RAYS->y_step;
				side = 1;
			}
			if (MAP->map[MAP->x_map][MAP->y_map] > 0)
				hit = 1;	
		}
		if (side == 0)
			RAYS->perp_wall_dist = (MAP->x_map - RAYS->x_pos + (1 - RAYS->x_step) / 2) / RAYS->x_ray_dir;
		else
			RAYS->perp_wall_dist = (MAP->y_map - RAYS->y_pos + (1 - RAYS->y_step) / 2) / RAYS->y_ray_dir;
		RAYS->line_height = (int)(HEIGHT / RAYS->perp_wall_dist);
		draw_walls(master, x, side);
	}
	MAP->x_map = (int)RAYS->x_pos;
	MAP->y_map = (int)RAYS->y_pos;
	destroy_walls(master);
}

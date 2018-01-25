/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 21:48:13 by kmckee            #+#    #+#             */
/*   Updated: 2018/01/25 11:08:02 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		key_press(int keycode, t_master *master)
{

	if (keycode == ESC)
		exit(0);
	if (keycode == W)
	{
		if (master->map->map[(int)master->rays->x_pos +
				 (int)master->rays->x_dir][(int)master->rays->y_pos] == 0)
			master->rays->x_pos += master->rays->x_dir;
		if (master->map->map[(int)master->rays->x_pos][(int)master->rays->y_pos + 
				(int)master->rays->y_dir] == 0) 
			master->rays->y_pos += master->rays->y_dir;
		mlx_clear_window(master->cam->mlx, master->cam->win);
		raycast(master);
		drawminimap(master);
	}
	if (keycode == A)
	{
		double	old_x_dir;
		double	old_x_plane;
		double c;
		double s;
		double angle;
		angle = 30 * (M_PI / 180);

		c = cos(angle);
		s = sin(angle);
		old_x_dir = master->rays->x_dir;
		mlx_clear_window(master->cam->mlx, master->cam->win);
		master->rays->x_dir = (old_x_dir * c) - (master->rays->y_dir * s);
		master->rays->y_dir = (old_x_dir * s) + (master->rays->y_dir * c);
		old_x_plane = master->cam->x_plane;
		master->cam->x_plane = (old_x_plane * c) - (master->cam->y_plane * s);
		master->cam->y_plane = (old_x_plane * s) + (master->cam->y_plane * c);
		raycast(master);
		drawminimap(master);
	}
	if (keycode == S)
	{
		if (master->map->map[(int)master->rays->x_pos - (int)master->rays->x_dir][(int)master->rays->y_pos] == 0)
			master->rays->x_pos -= (int)master->rays->x_dir;
		if (master->map->map[(int)master->rays->x_pos][(int)master->rays->y_pos - (int)master->rays->y_dir] == 0) 
			master->rays->y_pos -= (int)master->rays->y_dir;
		mlx_clear_window(master->cam->mlx, master->cam->win);
		raycast(master);
		drawminimap(master);
	}
	if (keycode == D)
	{
		double	old_x_dir;
		double	old_x_plane;
		double c;
		double s;
		double angle;

		angle = -30 * (M_PI / 180);
		c = cos(angle);
		s = sin(angle);
		old_x_dir = master->rays->x_dir;
		mlx_clear_window(master->cam->mlx, master->cam->win);
		master->rays->x_dir = (old_x_dir * c) - (master->rays->y_dir *s);
		master->rays->y_dir = (old_x_dir * s) + (master->rays->y_dir * c);
		old_x_plane = master->cam->x_plane;
		master->cam->x_plane = (old_x_plane * c) - (master->cam->y_plane * s);
		master->cam->y_plane = (old_x_plane * s) + (master->cam->y_plane * c);
	  	raycast(master);
		drawminimap(master);
    }
	return (0);
}

void	init_hooks(t_master *master)
{
	mlx_hook(master->cam->win, 2, 0, key_press, master);
}
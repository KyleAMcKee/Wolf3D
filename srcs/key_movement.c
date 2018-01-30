/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 18:52:01 by kmckee            #+#    #+#             */
/*   Updated: 2018/01/29 17:09:55 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	key_w(t_master *master)
{
	if (MAP->map[(int)(RAYS->x_pos + RAYS->x_dir)][(int)RAYS->y_pos] == 0)
		RAYS->x_pos += RAYS->x_dir;
	if (MAP->map[(int)RAYS->x_pos][(int)(RAYS->y_pos + RAYS->y_dir)] == 0)
		RAYS->y_pos += RAYS->y_dir;
	raycast(master);
	drawminimap(master);
}

void	key_s(t_master *master)
{
	if (MAP->map[(int)(RAYS->x_pos - RAYS->x_dir)][(int)RAYS->y_pos] == 0)
		RAYS->x_pos -= RAYS->x_dir;
	if (MAP->map[(int)RAYS->x_pos][(int)(RAYS->y_pos - RAYS->y_dir)] == 0)
		RAYS->y_pos -= RAYS->y_dir;
	raycast(master);
	drawminimap(master);
}

void	key_a(t_master *master)
{
	double	old_x_dir;
	double	old_x_plane;
	double	c;
	double	s;
	double	angle;
	angle = 30 * (M_PI / 180);

	c = cos(angle);
	s = sin(angle);
	old_x_dir = RAYS->x_dir;
	mlx_clear_window(CAM->mlx, CAM->win);
	RAYS->x_dir = (old_x_dir * c) - (RAYS->y_dir * s);
	RAYS->y_dir = (old_x_dir * s) + (RAYS->y_dir * c);
	old_x_plane = CAM->x_plane;
	CAM->x_plane = (old_x_plane * c) - (CAM->y_plane * s);
	CAM->y_plane = (old_x_plane * s) + (CAM->y_plane * c);
	raycast(master);
	drawminimap(master);
}

void	key_d(t_master *master)
{
	double	old_x_dir;
	double	old_x_plane;
	double	c;
	double	s;
	double	angle;

	angle = -30 * (M_PI / 180);
	c = cos(angle);
	s = sin(angle);
	old_x_dir = RAYS->x_dir;
	mlx_clear_window(CAM->mlx, CAM->win);
	RAYS->x_dir = (old_x_dir * c) - (RAYS->y_dir * s);
	RAYS->y_dir = (old_x_dir * s) + (RAYS->y_dir * c);
	old_x_plane = CAM->x_plane;
	CAM->x_plane = (old_x_plane * c) - (CAM->y_plane * s);
	CAM->y_plane = (old_x_plane * s) + (CAM->y_plane * c);
	raycast(master);
	drawminimap(master);
}

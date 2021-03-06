/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 18:52:01 by kmckee            #+#    #+#             */
/*   Updated: 2018/02/01 15:46:58 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	key_w(t_master *master)
{
	if (RAYS->move == 1)
	{
		if (MAP->map[(int)(RAYS->x_pos + RAYS->x_dir)][(int)RAYS->y_pos] == 3)
		{
			RAYS->x_pos += RAYS->x_dir * 0.2;
			RAYS->move = 0;
			exit_game(master);
		}
		if (MAP->map[(int)RAYS->x_pos][(int)(RAYS->y_pos + RAYS->y_dir)] == 3)
		{
			RAYS->y_pos += RAYS->y_dir * 0.2;
			RAYS->move = 0;
			exit_game(master);
		}
		if (MAP->map[(int)(RAYS->x_pos + RAYS->x_dir)][(int)RAYS->y_pos] == 0)
			RAYS->x_pos += RAYS->x_dir * 0.2;
		if (MAP->map[(int)RAYS->x_pos][(int)(RAYS->y_pos + RAYS->y_dir)] == 0)
			RAYS->y_pos += RAYS->y_dir * 0.2;
		raycast(master);
		drawminimap(master);
	}
	else
		return ;
}

void	key_s(t_master *master)
{
	if (RAYS->move == 1)
	{
		if (MAP->map[(int)(RAYS->x_pos - RAYS->x_dir)][(int)RAYS->y_pos] == 0)
			RAYS->x_pos -= RAYS->x_dir * 0.2;
		if (MAP->map[(int)RAYS->x_pos][(int)(RAYS->y_pos - RAYS->y_dir)] == 0)
			RAYS->y_pos -= RAYS->y_dir * 0.2;
		raycast(master);
		drawminimap(master);
	}
	else
		return ;
}

void	key_a(t_master *master)
{
	double	old_x_dir;
	double	old_x_plane;
	double	c;
	double	s;
	double	angle;

	if (RAYS->move == 1)
	{
		angle = 30 * (M_PI / 180);
		c = cos(angle);
		s = sin(angle);
		old_x_dir = RAYS->x_dir;
		RAYS->x_dir = (old_x_dir * c) - (RAYS->y_dir * s);
		RAYS->y_dir = (old_x_dir * s) + (RAYS->y_dir * c);
		old_x_plane = CAM->x_plane;
		CAM->x_plane = (old_x_plane * c) - (CAM->y_plane * s);
		CAM->y_plane = (old_x_plane * s) + (CAM->y_plane * c);
		raycast(master);
	}
	else
		return ;
}

void	key_d(t_master *master)
{
	double	old_x_dir;
	double	old_x_plane;
	double	c;
	double	s;
	double	angle;

	if (RAYS->move == 1)
	{
		angle = -30 * (M_PI / 180);
		c = cos(angle);
		s = sin(angle);
		old_x_dir = RAYS->x_dir;
		RAYS->x_dir = (old_x_dir * c) - (RAYS->y_dir * s);
		RAYS->y_dir = (old_x_dir * s) + (RAYS->y_dir * c);
		old_x_plane = CAM->x_plane;
		CAM->x_plane = (old_x_plane * c) - (CAM->y_plane * s);
		CAM->y_plane = (old_x_plane * s) + (CAM->y_plane * c);
		raycast(master);
	}
	else
		return ;
}

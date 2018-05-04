/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:07:39 by kmckee            #+#    #+#             */
/*   Updated: 2018/01/30 17:58:43 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int	mouse(int x, int y, t_master *master)
{
	double	old_x_dir;
	double	old_x_plane;
	double	c;
	double	s;
	double	angle;

	angle = 0;
	if (x < MOUSE->old_x)
		angle = (MOUSE->old_x - x) * (M_PI / 180) / 2;
	else if (x > MOUSE->old_x)
		angle = -(x - MOUSE->old_x) * (M_PI / 180) / 2;
	c = cos(angle);
	s = sin(angle);
	old_x_dir = RAYS->x_dir;
	RAYS->x_dir = (old_x_dir * c) - (RAYS->y_dir * s);
	RAYS->y_dir = (old_x_dir * s) + (RAYS->y_dir * c);
	old_x_plane = CAM->x_plane;
	CAM->x_plane = (old_x_plane * c) - (CAM->y_plane * s);
	CAM->y_plane = (old_x_plane * s) + (CAM->y_plane * c);
	raycast(master);
	drawminimap(master);
	MOUSE->old_x = x;
	MOUSE->old_y = y;
	return (0);
}

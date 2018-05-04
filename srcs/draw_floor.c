/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:28:19 by kmckee            #+#    #+#             */
/*   Updated: 2018/02/01 19:27:31 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	floor_vars(t_master *master, int side)
{
	if (side == 0)
	{
		if (RAYS->x_ray_dir > 0)
			RAYS->floor_x = MAP->x_map;
		else
			RAYS->floor_x = MAP->x_map + 1.0;
		RAYS->floor_y = MAP->y_map + RAYS->wall_x;
	}
	else if (side == 1)
	{
		if (RAYS->y_ray_dir > 0)
			RAYS->floor_y = MAP->y_map;
		else
			RAYS->floor_y = MAP->y_map + 1.0;
		RAYS->floor_x = MAP->x_map + RAYS->wall_x;
	}
}

void	draw_floor(t_master *master, int x, int side)
{
	double	wall_dist;
	double	current_dist;
	double	weight;
	int		floor_tex_x;
	int		floor_tex_y;

	floor_vars(master, side);
	wall_dist = RAYS->perp_wall_dist;
	if (RAYS->draw_end < 0)
		RAYS->draw_end = HEIGHT;
	while (RAYS->draw_end++ < HEIGHT - 1)
	{
		current_dist = HEIGHT / (2.0 * RAYS->draw_end - HEIGHT);
		weight = current_dist / wall_dist;
		RAYS->current_floor_x = weight * RAYS->floor_x +
			(1.0 - weight) * RAYS->x_pos;
		RAYS->current_floor_y = weight * RAYS->floor_y +
			(1.0 - weight) * RAYS->y_pos;
		floor_tex_x = (int)(RAYS->current_floor_x * TEX->w) % TEX->w;
		floor_tex_y = (int)(RAYS->current_floor_y * TEX->h) % TEX->h;
		RAYS->pixel_str[(RAYS->draw_end * HEIGHT) + x] =
			TEX->pixel_str[TEX->floor][TEX->h * floor_tex_y + floor_tex_x];
		RAYS->pixel_str[((HEIGHT - RAYS->draw_end) * WIDTH) + x] =
			TEX->pixel_str[TEX->sky][TEX->h * floor_tex_y + floor_tex_x];
	}
}

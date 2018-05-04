/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 14:47:35 by kmckee            #+#    #+#             */
/*   Updated: 2018/02/01 15:48:10 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		determine_side(t_master *master, int text_x, int text_y, int side)
{
	int color;

	if (MAP->map[MAP->x_map][MAP->y_map] == 3)
		color = TEX->pixel_str[14][(TEX->h * text_y) + text_x];
	else if (side == 0 && RAYS->x_ray_dir > 0)
		color = TEX->pixel_str[TEX->tex1][(TEX->h * text_y) + text_x];
	else if (side == 0 && RAYS->x_ray_dir < 0)
		color = TEX->pixel_str[TEX->tex2][(TEX->h * text_y) + text_x];
	else if (side == 1 && RAYS->y_ray_dir > 0)
		color = TEX->pixel_str[TEX->tex3][(TEX->h * text_y) + text_x];
	else
		color = TEX->pixel_str[TEX->tex4][(TEX->h * text_y) + text_x];
	color = shader(master, color);
	return (color);
}

int		index_find(t_master *master, int side, int text_x)
{
	int		color;
	int		text_y;
	int		calc_y;

	if (side == 0)
		RAYS->wall_x = RAYS->y_pos + RAYS->perp_wall_dist * RAYS->y_ray_dir;
	else
		RAYS->wall_x = RAYS->x_pos + RAYS->perp_wall_dist * RAYS->x_ray_dir;
	RAYS->wall_x -= floor(RAYS->wall_x);
	calc_y = RAYS->draw_start * 256 - HEIGHT * 128 + RAYS->line_height * 128;
	text_y = ((calc_y * TEX->h) / RAYS->line_height) / 256;
	color = determine_side(master, text_x, text_y, side);
	return (color);
}

void	draw_walls(t_master *master, int x, int side)
{
	int color;
	int text_x;

	RAYS->draw_start = -(RAYS->line_height) / 2 + HEIGHT / 2;
	text_x = (int)(RAYS->wall_x * (double)TEX->w);
	if (RAYS->draw_start < 0)
		RAYS->draw_start = 0;
	RAYS->draw_end = RAYS->line_height / 2 + HEIGHT / 2;
	if (RAYS->draw_end >= HEIGHT)
		RAYS->draw_end = HEIGHT - 1;
	while (RAYS->draw_start++ < RAYS->draw_end)
	{
		color = index_find(master, side, text_x);
		RAYS->pixel_str[(RAYS->draw_start * WIDTH) + x] = color;
	}
	draw_floor(master, x, side);
}

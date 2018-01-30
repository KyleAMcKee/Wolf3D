/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 15:13:45 by kmckee            #+#    #+#             */
/*   Updated: 2018/01/29 16:59:52 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	create_minimap(t_master *master)
{
	master->mini->img = mlx_new_image(master->cam->mlx, master->mini->width,
			master->mini->height);
	master->mini->pixel_str = (int *)mlx_get_data_addr(master->mini->img,
			&master->mini->bbp, &master->mini->size_line,
			&master->mini->endian);
}

void	destroy_minimap(t_master *master)
{
	mlx_put_image_to_window(master->cam->mlx, master->mini->win,
			master->mini->img, 0, 0);
	mlx_destroy_image(master->cam->mlx, master->mini->img);
}

void	drawsquare(t_master *master, int index, int color)
{
	int i;
	int j;

	i = -1;
	while (++i < 10)
	{
		j = -1;
		while (++j < 10)
		{
			if (j == 0 || i == 0)
				master->mini->pixel_str[index++] = 0x000000;
			else
				master->mini->pixel_str[index++] = color;
		}
		index += master->mini->width - 10;
	}
}

void	drawminimap(t_master *master)
{
	int index;
	int y;
	int x;

	create_minimap(master);
	index = 0;
	y = -1;
	while (++y < master->map->height)
	{
		x = -1;
		while (++x < master->map->width)
		{
			if (y == (int)master->rays->x_pos && x == (int)master->rays->y_pos)
				drawsquare(master, index, 0xFF0000);
			else if (master->map->map[y][x] == 0)
				drawsquare(master, index, 0xFFFFFF);
			else
				drawsquare(master, index, 0x708090);
			index += 10;
		}
		index += master->mini->width * 9;
	}
	destroy_minimap(master);
}

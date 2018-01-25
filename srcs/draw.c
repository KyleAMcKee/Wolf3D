/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 14:47:35 by kmckee            #+#    #+#             */
/*   Updated: 2018/01/25 11:06:37 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	create_walls(t_master *master)
{
	master->rays->img = mlx_new_image(master->cam->mlx, WIDTH, HEIGHT);
	master->rays->pixel_str = (int *)mlx_get_data_addr(master->rays->img,
			&master->rays->bbp, &master->rays->size_line,
			&master->rays->endian);
}

void	destroy_walls(t_master *master)
{
	mlx_put_image_to_window(master->cam->mlx, master->cam->win,
			master->rays->img, 0, 0);
	mlx_destroy_image(master->cam->mlx, master->rays->img);
}

void	draw_walls(t_master *master, int x, int side)
{
	master->rays->draw_start = -(master->rays->line_height) / 2 + HEIGHT / 2;
	if (master->rays->draw_start < 0)
		master->rays->draw_start = 0;
	master->rays->draw_end = master->rays->line_height / 2 + HEIGHT / 2;
	if (master->rays->draw_end >= HEIGHT)
		master->rays->draw_end = HEIGHT - 1;
	while (master->rays->draw_start++ < master->rays->draw_end)
	{
		if (side == 1)
			master->rays->pixel_str[(master->rays->draw_start * WIDTH) + x] = 0x00059F;
		else
			master->rays->pixel_str[(master->rays->draw_start * WIDTH) + x] = 0x2C2CFF;
	}
}

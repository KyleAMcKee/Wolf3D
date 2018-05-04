/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 13:15:22 by kmckee            #+#    #+#             */
/*   Updated: 2018/02/01 19:47:01 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		error_handle(int error_num)
{
	if (error_num == 1)
		ft_putstr("Map input is required\n");
	else if (error_num == 2)
		ft_putstr("Only one map input is allowed\n");
	else if (error_num == 3)
		ft_putstr("Must be a valid .wolf file\n");
	else if (error_num == 4)
		ft_putstr("No valid start position found\n");
	else if (error_num == 5)
		ft_putstr("Map must contain only numbers 0 - 9\n");
	else if (error_num == 6)
		ft_putstr("No such wolf file exists\n");
	exit(0);
	return (0);
}

void	exit_game(t_master *master)
{
	ft_putstr("Congratulations you found the exit!\n");
	if (master->shrek_mode == 1)
		system("killall afplay");
	master->shrek_mode = 0;
	mlx_destroy_image(CAM->mlx, RAYS->img);
	mlx_clear_window(CAM->mlx, CAM->win);
	mlx_put_image_to_window(CAM->mlx, CAM->win, RAYS->end_img, 0, 0);
	mlx_do_sync(CAM->mlx);
	mlx_put_image_to_window(CAM->mlx, CAM->win, RAYS->end_img, 0, 0);
	mlx_string_put(CAM->mlx, CAM->win, 125, 700, 0xFF00FF,
			"Level complete, press ESC to exit and try another level");
	mlx_do_sync(CAM->mlx);
}

void	key_tab(t_master *master)
{
	master->count++;
}

void	display_usage(t_master *master)
{
	mlx_string_put(CAM->mlx, CAM->win, 10, 700, 0xFFFFFF,
			"Move around: WASD, arrow keys, and mouse");
	mlx_string_put(CAM->mlx, CAM->win, 10, 717, 0xFF0000,
			"Normal mode: 1");
	mlx_string_put(CAM->mlx, CAM->win, 10, 734, 0x00FF00,
			"Shrek mode: 2");
}

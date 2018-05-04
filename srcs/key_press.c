/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 21:48:13 by kmckee            #+#    #+#             */
/*   Updated: 2018/02/01 19:42:00 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		key_press(int keycode, t_master *master)
{
	if (keycode <= 128)
		master->table[keycode](master);
	if (keycode == ESC)
	{
		if (master->shrek_mode == 1)
			system("killall afplay");
		exit(0);
	}
	return (0);
}

void	nothing(t_master *master)
{
	(void)master;
}

int		exit_win(t_master *master)
{
	(void)master;
	exit(0);
	return (0);
}

void	jump_table(t_master *master)
{
	int i;

	i = -1;
	while (++i < 128)
		master->table[i] = &nothing;
	master->table[W] = &key_w;
	master->table[A] = &key_a;
	master->table[S] = &key_s;
	master->table[D] = &key_d;
	master->table[UP] = &key_w;
	master->table[LEFT] = &key_a;
	master->table[DOWN] = &key_s;
	master->table[RIGHT] = &key_d;
	master->table[ONE] = &key_one;
	master->table[TWO] = &key_two;
	master->table[TAB] = &key_tab;
}

void	init_hooks(t_master *master)
{
	mlx_hook(master->cam->win, 2, 0, key_press, master);
	mlx_hook(master->cam->win, 6, 0, mouse, master);
	mlx_hook(master->cam->win, 17, 0, exit_win, master);
}

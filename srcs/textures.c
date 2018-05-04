/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 22:56:35 by kmckee            #+#    #+#             */
/*   Updated: 2018/02/01 15:50:55 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	textures(t_master *master)
{
	int			i;
	static char	*textures[] = {
		"images/Shrek.XPM", "images/donkey.XPM", "images/ogresign.XPM",
		"images/shrek1.XPM", "images/mossyfloor.XPM", "images/stars.XPM",
		"images/redbrick.XPM", "images/bluestone.XPM", "images/bookshelf.XPM",
		"images/wallpapergreen.XPM", "images/checker.XPM", "images/wood.XPM",
		"images/pillar.XPM", "images/redbrick.XPM", "images/kyle.XPM"
	};

	i = 0;
	while (i < 15)
	{
		TEX->img[i] = mlx_xpm_file_to_image(master->cam->mlx,
			textures[i], &TEX->w, &TEX->h);
		TEX->pixel_str[i] = (int*)mlx_get_data_addr(TEX->img[i],
			&TEX->bpp, &TEX->size_line, &TEX->endian);
		i++;
	}
}

/*
** -----WOLF MODE-----
*/

void	key_one(t_master *master)
{
	if (master->shrek_mode == 1)
		system("killall afplay");
	master->shrek_mode = 0;
	TEX->tex1 = 6;
	TEX->tex2 = 7;
	TEX->tex3 = 8;
	TEX->tex4 = 9;
	TEX->floor = 10;
	TEX->sky = 11;
	raycast(master);
}

/*
** -----SHREK MODE-----
*/

void	key_two(t_master *master)
{
	system("afplay audio/myswamp.mp3 &");
	TEX->tex1 = 0;
	TEX->tex2 = 1;
	TEX->tex3 = 2;
	TEX->tex4 = 3;
	TEX->floor = 4;
	TEX->sky = 5;
	raycast(master);
	if (master->shrek_mode != 1)
	{
		sleep(3);
		system("afplay audio/allstar.mp3 &");
	}
	master->shrek_mode = 1;
}

/*
** -----KYLE MODE-----
*/

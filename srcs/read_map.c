/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 17:47:07 by kmckee            #+#    #+#             */
/*   Updated: 2018/02/01 16:47:01 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	set_constants(t_master *master)
{
	RAYS->move = 1;
	RAYS->x_dir = -1;
	RAYS->y_dir = 0;
	CAM->x_plane = 0;
	CAM->y_plane = 0.66;
	MINI->width = MAP->width * 10;
	MINI->height = MAP->height * 10;
	CAM->mlx = mlx_init();
	MINI->win = mlx_new_window(CAM->mlx, MINI->width, MINI->height, "Mini Map");
	CAM->win = mlx_new_window(CAM->mlx, HEIGHT, WIDTH, "Raycaster");
	RAYS->img = mlx_new_image(master->cam->mlx, WIDTH, HEIGHT);
	RAYS->pixel_str = (int *)mlx_get_data_addr(RAYS->img,
			&RAYS->bbp, &RAYS->size_line, &RAYS->endian);
	RAYS->end_img = mlx_xpm_file_to_image(CAM->mlx, "./images/fireworks.XPM",
			&RAYS->height, &RAYS->width);
	RAYS->end_str = (int *)mlx_get_data_addr(RAYS->img,
			&RAYS->bbp, &RAYS->size_line, &RAYS->endian);
	master->count = 1;
	determine_start(master);
}

void	create_more_structs(t_master *master)
{
	t_mouse		*mouse;
	t_texture	*texture;

	mouse = (t_mouse*)malloc(sizeof(t_mouse));
	texture = (t_texture*)malloc(sizeof(t_texture));
	master->mouse = mouse;
	master->texture = texture;
	jump_table(master);
}

void	create_structs(t_master *master)
{
	t_map	*map;
	t_cam	*cam;
	t_rays	*rays;
	t_mini	*mini;

	map = (t_map*)malloc(sizeof(t_map));
	cam = (t_cam*)malloc(sizeof(t_cam));
	rays = (t_rays*)malloc(sizeof(t_rays));
	mini = (t_mini*)malloc(sizeof(t_mini));
	master->cam = cam;
	master->map = map;
	master->rays = rays;
	master->mini = mini;
	create_more_structs(master);
}

void	start_game(t_master *master, int height)
{
	master->map->height = height;
	set_constants(master);
	textures(master);
	key_one(master);
	raycast(master);
	drawminimap(master);
	init_hooks(master);
	mlx_loop(CAM->mlx);
}

int		read_map(t_master *master, int fd, int h)
{
	int		w;
	char	*line;
	char	**num_arr;

	w = -1;
	while (get_next_line(fd, &line))
	{
		num_arr = ft_strsplit(line, ' ');
		while (num_arr[++w] != NULL)
		{
			if (!(ft_isdigit(*num_arr[w])))
				error_handle(5);
			master->map->map[h][w] = ft_atoi(num_arr[w]);
			free(num_arr[w]);
		}
		free(num_arr);
		free(line);
		h++;
		master->map->width = w;
		w = -1;
	}
	return (h);
}

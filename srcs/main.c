/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 19:15:56 by kmckee            #+#    #+#             */
/*   Updated: 2018/01/25 11:04:29 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdio.h>

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
}

void	start_game(t_master *master, int height)
{
	master->map->height = height;
	set_constants(master);
	raycast(master);
	master->mini->win = mlx_new_window(master->cam->mlx,
			master->mini->width, master->mini->height, "Mini Map");
	drawminimap(master);
	init_hooks(master);
	mlx_loop(master->cam->mlx);
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

int		main(int argc, char **argv)
{
	int			fd;
	int			h;
	t_master	*master;

	h = 0;
	if (argc != 2)
		return (argc < 2 ? incorrect_args(1) : incorrect_args(2));
	if (!ft_strequ(&argv[1][ft_strlen(argv[1]) - 5], ".wolf"))
		return (incorrect_args(3));
	fd = open(argv[1], O_RDONLY);
	master = (t_master*)malloc(sizeof(t_master));
	create_structs(master);
	h = read_map(master, fd, h);
	start_game(master, h);
}

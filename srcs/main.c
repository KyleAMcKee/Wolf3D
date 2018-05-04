/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 19:15:56 by kmckee            #+#    #+#             */
/*   Updated: 2018/02/01 11:15:52 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		main(int argc, char **argv)
{
	int			fd;
	int			h;
	t_master	*master;

	h = 0;
	if (argc != 2)
		return (argc < 2 ? error_handle(1) : error_handle(2));
	if (!ft_strequ(&argv[1][ft_strlen(argv[1]) - 5], ".wolf"))
		return (error_handle(3));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (error_handle(6));
	master = (t_master*)malloc(sizeof(t_master));
	create_structs(master);
	h = read_map(master, fd, h);
	start_game(master, h);
}

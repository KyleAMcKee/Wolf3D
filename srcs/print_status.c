/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 16:39:56 by kmckee            #+#    #+#             */
/*   Updated: 2018/01/29 16:28:56 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	print_status(t_master *master)
{
	printf("x camera: %f\n", CAM->x_camera); 
	printf("x plane: %f, y plane: %f\n", CAM->x_plane, CAM->y_plane); 
	printf("x position: %f as int: %i, y position: %f as int: %i\n", RAYS->x_pos, (int)RAYS->x_pos, RAYS->y_pos, (int)RAYS->y_pos);
	printf("x direction: %f, y direction: %f\n", RAYS->x_dir, RAYS->y_dir);	
	printf("map x position: %i, map y position: %i\n", MAP->x_map, MAP->y_map);
	printf("x ray direction: %f, y ray direction %f\n\n", RAYS->x_ray_dir, RAYS->y_ray_dir);
//	printf("x position: %f as int: %i, y position: %f as int: %i\n", RAYS->x_pos, (int)RAYS->x_pos, RAYS->y_pos, (int)RAYS->y_pos);
}

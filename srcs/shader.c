/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 14:43:38 by kmckee            #+#    #+#             */
/*   Updated: 2018/01/30 15:17:06 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int	shader(t_master *master, int color)
{
	double	red;
	double	green;
	double	blue;
	double	multiplier;

	red = (double)(color >> 16 & 0xFF);
	green = (double)(color >> 8 & 0xFF);
	blue = (double)(color & 0xFF);
	multiplier = (100 / (RAYS->perp_wall_dist * 0.2)) > 100 ? 100 :
		100 / (RAYS->perp_wall_dist * 0.2);
	red *= multiplier / 100;
	green *= multiplier / 100;
	blue *= multiplier / 100;
	color = ((int)red << 16) + ((int)green << 8) + (int)blue;
	return (color);
}

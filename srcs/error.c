/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 13:15:22 by kmckee            #+#    #+#             */
/*   Updated: 2018/01/18 13:57:41 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int	incorrect_args(int error_num)
{
	if (error_num == 1)
		ft_putstr("need to use a map\n");
	if (error_num == 2)
		ft_putstr("only one map at a time, bruh\n");
	if (error_num == 3)
		ft_putstr("Must be a valid .wolf file\n");
	return (0);
}

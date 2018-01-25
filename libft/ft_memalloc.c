/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 19:08:47 by kmckee            #+#    #+#             */
/*   Updated: 2017/09/26 17:28:20 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*a;
	size_t			i;

	a = (void *)malloc(sizeof(void) * size);
	i = 0;
	if (a)
	{
		while (i < size)
		{
			a[i] = 0;
			i++;
		}
	}
	return (a);
}

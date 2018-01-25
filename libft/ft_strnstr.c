/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 21:51:19 by kmckee            #+#    #+#             */
/*   Updated: 2017/09/30 14:40:20 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lil, size_t len)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	j = 0;
	k = 0;
	if (lil[j] == '\0')
		return ((char*)big);
	while (big[k] != '\0' && k < len)
	{
		while (big[i] == lil[j] && i < len)
		{
			if (lil[j + 1] == '\0')
				return ((char*)&big[k]);
			i++;
			j++;
		}
		k++;
		i = k;
		j = 0;
	}
	return (0);
}

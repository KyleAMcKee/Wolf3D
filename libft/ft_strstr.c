/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 21:08:49 by kmckee            #+#    #+#             */
/*   Updated: 2017/09/26 16:58:23 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	if (little[j] == '\0')
		return ((char*)big);
	while (big[k] != '\0')
	{
		while (big[i] == little[j])
		{
			if (little[j + 1] == '\0')
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 10:36:39 by kmckee            #+#    #+#             */
/*   Updated: 2017/09/26 17:10:15 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int len;
	int first;

	len = ft_strlen(str);
	first = str[0];
	while (len >= 0)
	{
		if (str[len] == c)
		{
			return ((char*)&str[len]);
		}
		len--;
	}
	return (0);
}

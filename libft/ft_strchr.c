/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 22:10:32 by kmckee            #+#    #+#             */
/*   Updated: 2017/09/26 16:58:59 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(str);
	while (i <= len)
	{
		if (str[i] == c)
		{
			return ((char*)&str[i]);
		}
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 15:34:32 by kmckee            #+#    #+#             */
/*   Updated: 2017/09/30 16:06:04 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		total;
	char	*newstring;

	if (s1 == 0 || s2 == 0)
		return (0);
	i = 0;
	j = 0;
	total = ft_strlen(s1) + ft_strlen(s2);
	newstring = ft_strnew(total);
	if (newstring == 0)
		return (0);
	newstring[total] = '\0';
	while (s1[i] != '\0')
	{
		newstring[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		newstring[i++] = s2[j++];
	}
	return (newstring);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 21:42:11 by kmckee            #+#    #+#             */
/*   Updated: 2017/11/01 20:04:42 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfjoin(char *s1, char *s2)
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
		newstring[i++] = s2[j++];
	free(s1);
	return (newstring);
}

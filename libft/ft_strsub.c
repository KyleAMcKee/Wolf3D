/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 15:15:38 by kmckee            #+#    #+#             */
/*   Updated: 2017/09/30 15:11:32 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	int		i;

	new = (char*)malloc(sizeof(char) * len + 1);
	if (new == 0 || s == 0)
		return (0);
	new[len] = '\0';
	i = 0;
	while (len--)
	{
		new[i] = s[start + i];
		i++;
	}
	return (new);
}

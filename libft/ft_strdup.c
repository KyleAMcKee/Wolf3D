/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:39:27 by kmckee            #+#    #+#             */
/*   Updated: 2017/09/26 17:23:29 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*new;

	len = ft_strlen(s1);
	new = (char *)malloc(len * sizeof(char) + 1);
	if (new == 0)
		return (0);
	new = ft_strcpy(new, s1);
	return (new);
}

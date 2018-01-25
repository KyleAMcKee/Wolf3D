/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 14:27:32 by kmckee            #+#    #+#             */
/*   Updated: 2017/09/30 15:55:17 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	char	*save_new;
	char	*save_src;
	size_t	size;
	int		i;

	if (s && f)
	{
		size = ft_strlen((char *)s);
		new = (char *)malloc((size + 1) * sizeof(char));
		if (new == 0)
			return (0);
		save_new = new;
		save_src = (char *)s;
		i = 0;
		while (*save_src)
		{
			*new = (*f)(i, (char)*save_src++);
			new++;
			i++;
		}
		*new = '\0';
		return (save_new);
	}
	return (0);
}

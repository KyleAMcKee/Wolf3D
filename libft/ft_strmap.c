/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 09:52:12 by kmckee            #+#    #+#             */
/*   Updated: 2017/09/30 15:52:54 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	char	*save_new;
	char	*save_src;
	size_t	size;

	if (s && f)
	{
		size = ft_strlen((char *)s);
		new = (char *)malloc((size + 1) * sizeof(char));
		if (new == 0)
			return (0);
		save_new = new;
		save_src = (char *)s;
		while (*save_src)
		{
			*new = (*f)((char)*save_src);
			save_src++;
			new++;
		}
		*new = '\0';
		return (save_new);
	}
	return (0);
}

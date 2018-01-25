/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 18:55:43 by kmckee            #+#    #+#             */
/*   Updated: 2017/09/26 17:11:49 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t srcsize;
	size_t dstsize;

	srcsize = ft_strlen(src);
	dstsize = ft_strlen(dst);
	if (size < dstsize + 1)
		return (srcsize + size);
	if (size > dstsize + 1)
	{
		ft_strncat(dst, src, ((int)size - (int)dstsize - 1));
		return (dstsize + srcsize);
	}
	return (dstsize + srcsize);
}

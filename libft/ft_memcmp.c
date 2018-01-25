/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 10:53:37 by kmckee            #+#    #+#             */
/*   Updated: 2017/09/28 17:14:11 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;

	if (n == 0)
		return (0);
	a = (unsigned char *)str1;
	b = (unsigned char *)str2;
	i = 0;
	while (a[i] == b[i] && i < n - 1)
	{
		i++;
	}
	return (a[i] - b[i]);
}

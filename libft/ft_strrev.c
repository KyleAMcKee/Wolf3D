/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 19:07:49 by kmckee            #+#    #+#             */
/*   Updated: 2017/09/27 15:49:05 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		start;
	int		end;
	int		len;
	char	temp;

	len = ft_strlen(str);
	start = 0;
	end = len - 1;
	while (start < end)
	{
		temp = str[end];
		str[end] = str[start];
		str[start] = temp;
		start++;
		end--;
	}
	return (str);
}

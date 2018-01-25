/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 10:34:19 by kmckee            #+#    #+#             */
/*   Updated: 2017/09/26 17:12:39 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordcount(const char *str)
{
	int wordcount;
	int i;

	wordcount = 0;
	i = 0;
	if (ft_iswhitespace(str[0]) == 0)
		wordcount++;
	while (str[i] != '\0')
	{
		while (ft_iswhitespace(str[i]) == 1)
		{
			if (ft_iswhitespace(str[i + 1]) == 0 && str[i + 1] != '\0')
				wordcount++;
			i++;
		}
		i++;
	}
	return (wordcount);
}

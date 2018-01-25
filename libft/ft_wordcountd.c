/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcountd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 15:46:04 by kmckee            #+#    #+#             */
/*   Updated: 2017/09/26 17:16:37 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordcountd(const char *str, char d)
{
	int wordcount;
	int i;

	wordcount = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != d)
		{
			wordcount++;
			while (str[i] != d && str[i] != '\0')
				i++;
		}
		else
		{
			i++;
		}
	}
	return (wordcount);
}

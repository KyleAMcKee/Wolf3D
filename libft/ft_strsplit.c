/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 10:15:31 by kmckee            #+#    #+#             */
/*   Updated: 2017/09/30 16:00:39 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcreate(char const *s, int len, int i)
{
	char *str;

	str = (char*)malloc(sizeof(char) * len + 1);
	if (str == 0)
		return (0);
	str[len--] = '\0';
	while (len >= 0)
	{
		str[len] = s[i];
		len--;
		i--;
	}
	return (str);
}

static char	**ft_split(char const *s, char **bigstring, int wordcount, char c)
{
	int i;
	int index;
	int strlen;

	i = 0;
	index = 0;
	strlen = 0;
	while (index < wordcount)
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		while (s[i] != '\0' && s[i] != c)
		{
			i++;
			strlen++;
		}
		if (s[i] == c || s[i] == '\0')
		{
			bigstring[index] = ft_strcreate(s, strlen, i - 1);
			index++;
		}
		strlen = 0;
	}
	return (bigstring);
}

char		**ft_strsplit(char const *s, char c)
{
	int		wordcount;
	char	**bigstring;

	if (s == 0)
		return (0);
	wordcount = ft_wordcountd(s, c);
	bigstring = (char**)malloc(sizeof(char*) * wordcount + 1);
	if (bigstring == 0)
		return (0);
	bigstring[wordcount] = 0;
	return (ft_split(s, bigstring, wordcount, c));
}

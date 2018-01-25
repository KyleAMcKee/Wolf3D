/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 15:54:20 by kmckee            #+#    #+#             */
/*   Updated: 2017/09/30 16:06:57 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	findend(char const *s, int stringlen)
{
	while (s[stringlen] == ' ' || s[stringlen] == '\t' || s[stringlen] == '\n')
		stringlen--;
	return (stringlen);
}

static	int	findstart(char const *s)
{
	int i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	{
		i++;
	}
	return (i);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		start;
	int		end;
	int		stringlen;
	char	*newstring;

	if (s == 0)
		return (0);
	i = 0;
	start = 0;
	stringlen = ft_strlen(s) - 1;
	start = findstart(s);
	if (s[start + 1] == '\0')
		return ("");
	end = findend(s, stringlen);
	newstring = (char *)malloc(sizeof(char) * (end - start) + 2);
	if (newstring == 0)
		return (ft_strnew(0));
	newstring[end - start + 1] = '\0';
	i = 0;
	while (end >= start)
	{
		newstring[i++] = s[start++];
	}
	return (newstring);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 10:35:31 by kmckee            #+#    #+#             */
/*   Updated: 2017/09/30 14:39:10 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_digitcount(int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n = n * -1;
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static	char	*ft_positive(int num)
{
	int		i;
	char	*str;

	i = ft_digitcount(num);
	str = ft_strnew(i);
	if (!str)
		return (0);
	str[i] = '\0';
	while (i--)
	{
		str[i] = (num % 10) + '0';
		num = num / 10;
	}
	return (str);
}

static	char	*ft_negative(int num)
{
	int		i;
	char	*str;

	i = ft_digitcount(num);
	str = ft_strnew(i);
	if (!str)
		return (0);
	str[i] = '\0';
	num = -num;
	while (i--)
	{
		str[i] = (num % 10) + '0';
		num = num / 10;
	}
	str[0] = '-';
	return (str);
}

char			*ft_itoa(int n)
{
	char *zero;

	if (n == 0)
	{
		zero = ft_strnew(1);
		zero[0] = '0';
		zero[1] = '\0';
		return (zero);
	}
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n >= 0)
		return (ft_positive(n));
	if (n < 0)
		return (ft_negative(n));
	return (0);
}

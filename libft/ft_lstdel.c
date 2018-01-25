/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 20:06:21 by kmckee            #+#    #+#             */
/*   Updated: 2017/09/28 16:20:57 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*temp1;
	t_list	*temp2;

	temp1 = *alst;
	while (temp1 != 0)
	{
		temp2 = temp1->next;
		del(temp1->content, temp1->content_size);
		free(temp1);
		temp1 = temp2;
	}
	*alst = (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 14:44:53 by kmckee            #+#    #+#             */
/*   Updated: 2017/09/26 17:09:18 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;

	new = (t_list*)malloc(sizeof(t_list));
	if (new == 0)
		return (0);
	if (content == 0)
	{
		new->content = 0;
		new->content_size = 0;
	}
	else
	{
		new->content = malloc(sizeof(size_t) * content_size);
		new->content = ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
		new->next = 0;
	}
	return (new);
}

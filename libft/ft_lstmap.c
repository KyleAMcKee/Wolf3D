/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 10:51:58 by kmckee            #+#    #+#             */
/*   Updated: 2017/09/28 16:20:33 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *temp;
	t_list *first;

	temp = f(lst);
	new = ft_lstnew(temp->content, temp->content_size);
	if (new == 0)
		return (0);
	first = new;
	lst = lst->next;
	while (lst)
	{
		temp = f(lst);
		new->next = ft_lstnew(temp->content, temp->content_size);
		if (new == 0)
			return (0);
		lst = lst->next;
		new = new->next;
	}
	return (first);
}

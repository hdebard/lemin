/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 08:15:23 by hdebard           #+#    #+#             */
/*   Updated: 2015/12/04 20:24:50 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*n_elem;
	t_list		*tmp;
	t_list		*new;
	t_list		*tmp2;

	n_elem = NULL;
	if (lst)
	{
		while (lst)
		{
			tmp = (*f)(lst);
			new = ft_lstnew(tmp->content, tmp->content_size);
			if (n_elem)
				tmp2->next = new;
			else
				n_elem = new;
			tmp2 = new;
			lst = lst->next;
		}
	}
	return (n_elem);
}

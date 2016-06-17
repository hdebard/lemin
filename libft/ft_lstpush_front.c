/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 10:43:49 by hdebard           #+#    #+#             */
/*   Updated: 2015/12/05 10:56:37 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstpush_front(t_list **list, void const *c, size_t size)
{
	t_list		*new;
	t_list		*ptr;

	ptr = *list;
	if (ptr)
	{
		new = ft_lstnew(c, size);
		new->next = ptr;
		*list = new;
	}
	else
		*list = ft_lstnew(c, size);
}

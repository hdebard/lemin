/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 10:48:23 by hdebard           #+#    #+#             */
/*   Updated: 2015/12/05 12:23:49 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstpush_back(t_list **list, void const *c, size_t size)
{
	t_list		*new;
	t_list		*ptr;

	ptr = *list;
	if (ptr)
	{
		while (ptr->next)
			ptr = ptr->next;
		new = ft_lstnew(c, size);
		ptr->next = new;
	}
	else
		ptr = ft_lstnew(c, size);
}

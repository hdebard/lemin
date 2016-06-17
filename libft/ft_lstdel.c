/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 08:05:03 by hdebard           #+#    #+#             */
/*   Updated: 2015/12/04 08:47:06 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*tmp;

	tmp = NULL;
	if (*alst)
	{
		while (*alst)
		{
			(*del)((*alst)->content, (*alst)->content_size);
			tmp = *alst;
			free(*alst);
			*alst = tmp->next;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 07:51:31 by hdebard           #+#    #+#             */
/*   Updated: 2015/12/04 08:57:42 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*n_elem;

	n_elem = (t_list *)malloc(sizeof(t_list));
	if (n_elem == NULL)
		return (n_elem);
	if (content == NULL)
	{
		n_elem->content = NULL;
		n_elem->content_size = 0;
	}
	else
	{
		n_elem->content = (void*)malloc(sizeof(content_size));
		if (n_elem->content == NULL)
		{
			free(n_elem);
			return (NULL);
		}
		ft_memcpy(n_elem->content, content, content_size);
		n_elem->content_size = content_size;
	}
	n_elem->next = NULL;
	return (n_elem);
}

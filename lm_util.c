/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 22:37:07 by hdebard           #+#    #+#             */
/*   Updated: 2016/06/09 17:36:23 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				lm_pathlen(t_list *path)
{
	t_list			*ptr;
	int				len;

	len = 0;
	ptr = path;
	while (ptr)
	{
		ptr = ptr->next;
		len++;
	}
	return (len);
}

int				lm_nlistlen(t_nlist *path)
{
	t_nlist			*ptr;
	int				len;

	ptr = path->next;
	len = 2;
	while (ptr)
	{
		len++;
		ptr = ptr->next;
	}
	return (len);
}

int				lm_double_nlistlen(t_dnlist *path)
{
	t_nlist			*ptr;
	int				len;

	ptr = path->next;
	len = 1;
	while (ptr)
	{
		len++;
		ptr = ptr->next;
	}
	return (len);
}

int				ft_strascii(char *str)
{
	int c;

	c = 0;
	while (str[c])
	{
		if (ft_isascii(str[c]) != 1)
			return (0);
		c++;
	}
	return (1);
}

t_list			*lm_lst_append(t_list *list, void *data)
{
	t_list			*ptr;

	if (list == NULL)
	{
		if ((list = (t_list*)malloc(sizeof(t_list))) == NULL)
			return (NULL);
		ptr = list;
	}
	else
	{
		ptr = list;
		while (ptr->next)
			ptr = ptr->next;
		if ((ptr->next = (t_list*)malloc(sizeof(t_list))) == NULL)
			return (NULL);
		ptr = ptr->next;
	}
	ptr->next = NULL;
	if ((ptr->content = ft_strdup(data)) == NULL)
		return (NULL);
	return (list);
}

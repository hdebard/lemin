/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 20:23:36 by hdebard           #+#    #+#             */
/*   Updated: 2016/06/09 17:51:53 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		lm_clear_paths(t_lemin *lemin)
{
	t_nlist			*ptr;

	while (lemin->n_path)
	{
		ptr = lemin->n_path->next;
		while (ptr)
		{
			free(ptr);
			ptr = ptr->next;
		}
		lemin->n_path = lemin->n_path->next_list;
	}
}

void		lm_cn_path(t_dnlist *new, t_nlist *ptr, t_lemin *l)
{
	t_nlist *tmp;

	new->next = (t_nlist*)malloc(sizeof(t_nlist));
	tmp = new->next;
	tmp->n = ptr->n;
	ptr = ptr->next;
	while (ptr)
	{
		tmp->next = (t_nlist*)malloc(sizeof(t_nlist));
		tmp = tmp->next;
		tmp->n = ptr->n;
		ptr = ptr->next;
	}
	tmp->next = (t_nlist*)malloc(sizeof(t_nlist));
	tmp = tmp->next;
	tmp->n = l->end->n;
	tmp->next = NULL;
}

t_dnlist	*lm_make_path(t_nlist *path, t_lemin *lemin)
{
	t_dnlist		*new;
	t_nlist			*ptr;

	new = (t_dnlist*)malloc(sizeof(t_dnlist));
	new->next_list = NULL;
	new->n = path->n;
	ptr = path->next;
	if (ptr)
		lm_cn_path(new, ptr, lemin);
	else
	{
		new->next = (t_nlist*)malloc(sizeof(t_nlist));
		new->next->n = lemin->end->n;
		new->next->next = NULL;
	}
	return (new);
}

void		lm_check_multy_path(t_nlist *path, t_lemin *lemin)
{
	t_dnlist		*tmp;
	t_dnlist		*last;
	t_nlist			*ptr;
	t_nlist			*ptr2;

	tmp = lemin->n_path;
	while (tmp)
	{
		ptr = tmp->next;
		ptr2 = path->next;
		while (ptr->next)
		{
			if (ptr->n == ptr2->n)
				return ;
			ptr = ptr->next;
		}
		last = tmp;
		tmp = tmp->next_list;
	}
	last->next_list = lm_make_path(path, lemin);
}

void		lm_save_path(t_nlist *path, t_lemin *lemin)
{
	int				len;

	if ((len = lm_nlistlen(path)) > lemin->path_len && lemin->path_len != -1)
		return ;
	else if (len == lemin->path_len)
		lm_check_multy_path(path, lemin);
	else
	{
		lm_clear_paths(lemin);
		lemin->n_path = lm_make_path(path, lemin);
		lemin->path_len = lm_double_nlistlen(lemin->n_path);
	}
}

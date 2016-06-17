/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 20:19:35 by hdebard           #+#    #+#             */
/*   Updated: 2016/06/08 22:39:18 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				lm_resolve_check(t_nlist *path, int x, t_lemin *lemin)
{
	t_nlist			*ptr;

	ptr = path;
	while (ptr->next)
	{
		if (x == ptr->n)
			return (0);
		ptr = ptr->next;
	}
	if (x == lemin->end->n)
	{
		lm_save_path(path, lemin);
		return (0);
	}
	ptr->next = (t_nlist*)malloc(sizeof(t_nlist));
	ptr->next->n = x;
	ptr->next->next = NULL;
	return (1);
}

void			lm_resolve_delete(t_nlist *path)
{
	t_nlist			*ptr;

	ptr = path;
	if (ptr && ptr->next && !ptr->next->next)
	{
	}
	else
	{
		while (ptr && ptr->next && ptr->next->next)
			ptr = ptr->next;
	}
	free(ptr->next);
	ptr->next = NULL;
}

void			lm_link_found(t_nlist *path, int n, t_lemin *lemin)
{
	if (lm_resolve_check(path, n, lemin) == 1)
	{
		lm_recursive(path, lemin);
		lm_resolve_delete(path);
	}
}

void			lm_recursive(t_nlist *path, t_lemin *lemin)
{
	t_nlist			*ptr;
	t_link			*tmp;

	ptr = path;
	if (lemin->path_len != -1 && lm_nlistlen(path) > lemin->path_len)
		return ;
	while (ptr->next)
		ptr = ptr->next;
	tmp = lemin->links;
	while (tmp)
	{
		if (tmp->n1 == ptr->n)
			lm_link_found(path, tmp->n2, lemin);
		else if (tmp->n2 == ptr->n)
			lm_link_found(path, tmp->n1, lemin);
		tmp = tmp->next;
	}
}

int				lm_resolve(t_lemin *lemin)
{
	t_nlist			*path;

	path = (t_nlist*)malloc(sizeof(t_nlist));
	path->next = NULL;
	path->n = lemin->start->n;
	lemin->n_path = NULL;
	lemin->path_len = -1;
	lm_recursive(path, lemin);
	if (lemin->n_path != NULL)
		return (1);
	return (0);
}

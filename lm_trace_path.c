/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_trace_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 20:42:04 by hdebard           #+#    #+#             */
/*   Updated: 2016/06/09 17:53:27 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char	*lm_get_name(int nbr, t_lemin *lemin)
{
	t_room		*ptr;
	char		*name;

	ptr = lemin->rooms;
	name = NULL;
	while (ptr)
	{
		if (ptr->n == nbr)
		{
			name = ft_strdup(ptr->name);
			break ;
		}
		ptr = ptr->next;
	}
	return (name);
}

void	lm_cpath(t_nlist *ptr, t_dlist *tmp_p, t_lemin *lemin)
{
	t_list			*tmp_l;

	while (ptr)
	{
		if (tmp_p->next == NULL)
		{
			tmp_p->next = (t_list*)malloc(sizeof(t_list));
			tmp_l = tmp_p->next;
		}
		else
		{
			tmp_l->next = (t_list*)malloc(sizeof(t_list));
			tmp_l = tmp_l->next;
		}
		tmp_l->next = NULL;
		tmp_l->content = lm_get_name(ptr->n, lemin);
		ptr = ptr->next;
	}
}

void	lm_trace_path(t_lemin *lemin)
{
	t_dnlist		*tmp;
	t_dlist			*start;
	t_dlist			*tmp_path;

	start = (t_dlist*)malloc(sizeof(t_dlist));
	start->next = NULL;
	start->next_list = NULL;
	tmp = lemin->n_path;
	tmp_path = start;
	while (tmp)
	{
		lm_cpath(tmp->next, tmp_path, lemin);
		tmp = tmp->next_list;
		if (tmp != NULL)
		{
			tmp_path->next_list = (t_dlist*)malloc(sizeof(t_dlist));
			tmp_path->next_list->next_list = NULL;
			tmp_path = tmp_path->next_list;
			tmp_path->next = NULL;
		}
	}
	lemin->path = start;
}

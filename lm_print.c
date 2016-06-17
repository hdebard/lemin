/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 20:45:50 by hdebard           #+#    #+#             */
/*   Updated: 2016/06/09 17:53:54 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_nlist		*lm_add_ant(t_nlist *ant, int *c)
{
	t_nlist		*ptr;

	if (ant == NULL)
	{
		ptr = (t_nlist*)malloc(sizeof(t_nlist));
		ant = ptr;
	}
	else
	{
		ptr = ant;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = (t_nlist*)malloc(sizeof(t_nlist));
		ptr = ptr->next;
	}
	ptr->next = NULL;
	ptr->n = 0;
	*c += 1;
	return (ant);
}

void		lm_print_ants(t_lemin *lemin, t_nlist *ant, int f)
{
	t_nlist		*ptr;
	t_list		*tmp;
	int			i;
	int			c;

	c = 1;
	ptr = ant;
	while (ptr)
	{
		tmp = lemin->path->next;
		if (c != 1)
			ft_putchar(' ');
		i = ptr->n;
		while (i--)
			tmp = tmp->next;
		ft_putchar('L');
		ft_putnbr(c + f);
		ft_putchar('-');
		ft_putstr(tmp->content);
		ptr = ptr->next;
		c++;
	}
	ft_putendl("");
}

t_nlist		*lm_shift_ant(t_nlist *ant, int len, int *f)
{
	t_nlist *ptr;

	ptr = ant;
	while (ptr)
	{
		if (ptr->n == len - 1)
		{
			ant = ptr->next;
			free(ptr);
			ptr = ant;
			*f += 1;
			if (ant == NULL)
				break ;
		}
		ptr->n++;
		if (ptr)
			ptr = ptr->next;
	}
	return (ant);
}

void		lm_print_file(t_lemin *lemin)
{
	t_list *ptr;

	ptr = lemin->file;
	while (ptr)
	{
		ft_putendl(ptr->content);
		ptr = ptr->next;
	}
	ft_putendl("");
}

int			lm_print(t_lemin *lemin)
{
	t_nlist *ant;
	int		len;
	int		f;
	int		c;

	c = 0;
	f = 0;
	len = lm_pathlen(lemin->path->next);
	ant = NULL;
	lm_print_file(lemin);
	while (lemin->n > c || ant != NULL)
	{
		if (lemin->n > c)
			ant = lm_add_ant(ant, &c);
		lm_print_ants(lemin, ant, f);
		ant = lm_shift_ant(ant, len, &f);
	}
	return (1);
}

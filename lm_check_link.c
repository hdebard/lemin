/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_check_link.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 22:52:16 by hdebard           #+#    #+#             */
/*   Updated: 2016/06/09 17:50:46 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				lm_link_names(char **array, t_lemin *new)
{
	t_room			*ptr;
	int				i;
	int				j;

	j = -1;
	i = -1;
	ptr = new->rooms;
	while (ptr)
	{
		if (ft_strcmp(ptr->name, array[0]) == 0)
			i = ptr->n;
		else if (ft_strcmp(ptr->name, array[1]) == 0)
			j = ptr->n;
		ptr = ptr->next;
	}
	if (i != -1 && j != -1)
		lm_new_link(new, i, j);
	else
		return (1);
	return (0);
}

int				lm_check_link(char *str, t_lemin *new)
{
	char			**array;
	int				len;

	array = ft_strsplit(str, '-');
	if ((len = ft_str_arraylen(array)) < 2)
		return (1);
	else if (len == 2)
	{
		if (lm_link_names(array, new) == 1)
			return (1);
	}
	else
	{
		if (lm_check_dash(str, new) != 0)
			return (1);
	}
	free(array);
	return (0);
}

int				lm_dash_len(char *str, int len)
{
	if (len != 0)
		str[len] = '-';
	while (str[len] && str[len] != '-')
		len++;
	if (str[len] == '-')
		str[len] = '\0';
	return (len);
}

int				lm_check_dash(char *str, t_lemin *new)
{
	t_room			*ptr;
	int				i;
	int				j;
	int				len;

	len = lm_dash_len(str, 0);
	while (len > 0)
	{
		ptr = new->rooms;
		i = -1;
		j = -1;
		while (ptr)
		{
			if (ft_strcmp(ptr->name, str) == 0)
				i = ptr->n;
			else if (ft_strcmp(ptr->name, str + len + 1) == 0)
				j = ptr->n;
			if (i > -1 && j > -1)
				return (lm_new_link(new, i, j));
			ptr = ptr->next;
		}
		if (i == -1 || j == -1)
			len = lm_dash_len(str, len);
	}
	return (1);
}

int				lm_new_link(t_lemin *new, int i, int j)
{
	t_link			*ptr;

	if (new->links == NULL)
	{
		new->links = (t_link*)malloc(sizeof(t_link));
		ptr = new->links;
	}
	else
	{
		ptr = new->links;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = (t_link*)malloc(sizeof(t_link));
		ptr = ptr->next;
	}
	ptr->n1 = i;
	ptr->n2 = j;
	ptr->next = NULL;
	return (0);
}

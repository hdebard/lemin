/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_check_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 22:38:24 by hdebard           #+#    #+#             */
/*   Updated: 2016/06/09 17:49:53 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				lm_duplicate_room(char *str, char *pos, t_lemin *new)
{
	struct s_room	*ptr;
	char			**array;
	int				n1;
	int				n2;

	array = ft_strsplit(pos + 1, ' ');
	n1 = ft_atoi(array[0]);
	n2 = ft_atoi(array[1]);
	ptr = new->rooms;
	while (ptr)
	{
		if ((ptr->xpos == n1 && ptr->ypos == n2)
			|| ft_strcmp(str, ptr->name) == 0)
			return (1);
		ptr = ptr->next;
	}
	free(array);
	return (0);
}

int				lm_check_position(char *str)
{
	int				length;
	int				count;
	int				token;

	token = 0;
	count = 0;
	length = ft_strlen(str);
	if (ft_isdigit(str[length - 1]) == 0)
		return (-1);
	while (--length >= 0)
	{
		if (token == 0 && ft_isdigit(str[length]) == 1)
		{
			count++;
			token = 1;
		}
		else if (str[length] == ' ')
			token = 0;
		if (count == 2 && token == 0)
			return (length);
	}
	return (-1);
}

int				lm_check_room(char *str, t_lemin *new, int m)
{
	int				len;

	if (str[0] == 'L')
		return (1);
	if ((len = lm_check_position(str)) == -1)
		return (1);
	str[len] = '\0';
	if (lm_duplicate_room(str, str + len, new) != 0)
		return (1);
	str[len] = ' ';
	if (lm_new_room(new) != 0)
		return (1);
	if (lm_fill_room(str, len, new, m) != 0)
		return (1);
	return (0);
}

int				lm_new_room(t_lemin *new)
{
	t_room			*ptr;
	int				i;

	i = 0;
	ptr = new->rooms;
	if (new->rooms == NULL)
	{
		if ((new->rooms = (t_room*)malloc(sizeof(t_room))) == NULL)
			return (1);
		ptr = new->rooms;
	}
	else
	{
		i++;
		while (ptr->next && i++)
			ptr = ptr->next;
		if ((ptr->next = (t_room*)malloc(sizeof(t_room))) == NULL)
			return (1);
		ptr = ptr->next;
	}
	ptr->next = NULL;
	ptr->n = i;
	return (0);
}

int				lm_fill_room(char *str, int len, t_lemin *new, int m)
{
	char			**array;
	t_room			*new_room;

	new_room = new->rooms;
	while (new_room->next)
		new_room = new_room->next;
	array = ft_strsplit(str + len, ' ');
	str[len] = 0;
	new_room->xpos = ft_atoi(array[0]);
	new_room->ypos = ft_atoi(array[1]);
	new_room->weigth = -1;
	if ((new_room->name = ft_strdup(str)) == NULL)
		return (1);
	new_room->next = NULL;
	if (m == 1)
		new->start = new_room;
	else if (m == 2)
		new->end = new_room;
	str[len] = ' ';
	free(array);
	return (0);
}

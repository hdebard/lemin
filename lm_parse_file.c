/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_parse_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 22:32:53 by hdebard           #+#    #+#             */
/*   Updated: 2016/06/09 17:49:09 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_lemin			*lm_parse_file(void)
{
	t_lemin			*new;

	if ((new = lm_init_lemin()) == NULL)
		return (NULL);
	else if ((new->file = lm_read_file(new)) == NULL)
		return (NULL);
	else if (new->rooms == NULL)
		return (NULL);
	else if (new->rooms->next == NULL)
		return (NULL);
	else if (new->links == NULL)
		return (NULL);
	else if (new->start == NULL)
		return (NULL);
	else if (new->end == NULL)
		return (NULL);
	return (new);
}

t_lemin			*lm_init_lemin(void)
{
	t_lemin			*new;

	if ((new = (t_lemin*)malloc(sizeof(t_lemin))) == NULL)
		return (NULL);
	new->rooms = NULL;
	new->start = NULL;
	new->end = NULL;
	new->links = NULL;
	new->file = NULL;
	new->path = NULL;
	new->n = -1;
	return (new);
}

t_list			*lm_read_file(t_lemin *lemin)
{
	t_list			*new;
	char			*buff;
	int				c;

	new = NULL;
	buff = NULL;
	c = 0;
	while (get_next_line(0, &buff) != 0)
	{
		if (!buff || buff[0] == '\0' || ft_strascii(buff) != 1)
			break ;
		c = lm_check_line(buff, lemin, c);
		if (c != 3 && (new = lm_lst_append(new, buff)) == NULL)
			return (NULL);
		free(buff);
		buff = NULL;
		if (c == -1)
			break ;
	}
	if (buff)
		free(buff);
	return (new);
}

int				lm_check_line(char *line, t_lemin *new, int c)
{
	if (new->n == -1)
		return (lm_check_ant(line, new));
	else if (ft_strncmp(line, "##start", 7) == 0)
		return (1);
	else if (ft_strncmp(line, "##end", 6) == 0)
		return (2);
	else if (ft_strncmp(line, "#", 1) == 0)
	{
		if (c == 1 || c == 2)
			return (c);
		return (3);
	}
	else if (new->links == NULL
			&& lm_check_room(line, new, c) == 0)
		return (0);
	else if ((c == 0 || c == 3) && lm_check_link(line, new) == 0)
		return (0);
	else
		return (-1);
}

int				lm_check_ant(char *ant, t_lemin *lemin)
{
	if (ft_isint(ant) == 0)
		return (-1);
	if (ft_isnumber(ant) == 0)
		return (-1);
	if ((lemin->n = ft_atoi(ant)) < 1)
		return (-1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 00:36:46 by hdebard           #+#    #+#             */
/*   Updated: 2016/03/29 12:48:53 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			get_next_line(int fd, char **line)
{
	static t_gnl	*list;
	t_gnl			*ptr;
	char			*buff;

	if ((buff = (char*)malloc(sizeof(char) * BUFF_SIZE + 1)) == NULL)
		return (-1);
	if (!line)
		return (-1);
	if (!list)
	{
		if ((list = new_list(fd)) == NULL)
			return (-1);
		return (get_line(list, buff, line));
	}
	ptr = list;
	while (ptr->fd != fd && ptr->next != NULL)
		ptr = ptr->next;
	if (ptr->fd != fd && ptr->next == NULL)
	{
		if ((ptr->next = new_list(fd)) == NULL)
			return (-1);
		ptr = ptr->next;
	}
	return (get_line(ptr, buff, line));
}

int			get_line(t_gnl *list, char *buff, char **line)
{
	int		ret;

	if (new_line(list, line, buff) == 1)
		return (1);
	while ((ret = read(list->fd, buff, BUFF_SIZE)) != 0)
	{
		buff[ret] = '\0';
		if (save_buff(list, buff, ret) == 0 || ret == -1)
			return (-1);
		if ((ret = new_line(list, line, buff)) == 1)
			break ;
		if (ret == -1)
			return (-1);
	}
	if (ret != 0)
		return (1);
	if (ft_strlen(list->buff) == 0)
		return (0);
	buff[0] = '\n';
	buff[1] = '\0';
	if (save_buff(list, buff, 1) == 0)
		return (-1);
	if (new_line(list, line, buff) == -1)
		return (-1);
	return (1);
}

int			save_buff(t_gnl *list, char *buff, int ret)
{
	char	*new_buff;
	int		i;
	int		j;

	if ((new_buff = (char*)malloc(sizeof(char) * (ft_strlen(list->buff) +
					ft_strlen(buff) + ret + 1))) == NULL)
		return (0);
	ret--;
	i = 0;
	while (list->buff[i] != '\0')
	{
		new_buff[i] = list->buff[i];
		i++;
	}
	j = 0;
	while (buff[j] != '\0')
	{
		new_buff[i + j] = buff[j];
		j++;
	}
	free(list->buff);
	new_buff[i + j] = '\0';
	list->buff = new_buff;
	return (1);
}

int			new_line(t_gnl *list, char **line, char *buff)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ptr = list->buff;
	if (ft_strchr(list->buff, '\n') == NULL)
		return (0);
	i = ft_strchr(list->buff, '\n') - list->buff;
	list->buff[i] = '\0';
	if ((*line = ft_strdup(ptr)) == NULL)
		return (-1);
	i++;
	if ((list->buff = (char*)malloc(sizeof(char) *
									ft_strlen(ptr + i) + 1)) == NULL)
		return (-1);
	while (ptr[i] != '\0')
		list->buff[j++] = ptr[i++];
	list->buff[j] = '\0';
	free(buff);
	free(ptr);
	return (1);
}

t_gnl		*new_list(int fd)
{
	t_gnl	*nlist;

	if ((nlist = (t_gnl*)malloc(sizeof(t_gnl))) == NULL)
		return (NULL);
	if ((nlist->buff = ft_strdup("")) == NULL)
		return (NULL);
	nlist->fd = fd;
	nlist->next = NULL;
	return (nlist);
}

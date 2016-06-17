/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 22:23:01 by hdebard           #+#    #+#             */
/*   Updated: 2016/06/09 17:51:09 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "libft.h"

typedef struct		s_lemin
{
	struct s_room		*rooms;
	struct s_room		*start;
	struct s_room		*end;
	struct s_link		*links;
	struct s_dlist		*path;
	struct s_dnlist		*n_path;
	t_list				*file;
	int					path_len;
	int					n;
}					t_lemin;

typedef struct		s_room
{
	struct s_room		*next;
	char				*name;
	int					n;
	int					weigth;
	int					xpos;
	int					ypos;
}					t_room;

typedef struct		s_link
{
	struct s_link		*next;
	int					n1;
	int					n2;
}					t_link;

typedef struct		s_nlist
{
	struct s_nlist		*next;
	int					n;
}					t_nlist;

typedef struct		s_dnlist
{
	struct s_dnlist		*next_list;
	struct s_nlist		*next;
	int					n;
}					t_dnlist;

typedef struct		s_dlist
{
	struct s_dlist		*next_list;
	struct s_list		*next;
}					t_dlist;

/*
** lm_parse_file.c
*/
t_lemin				*lm_parse_file(void);
t_lemin				*lm_init_lemin(void);
t_list				*lm_read_file(t_lemin *lemin);
int					lm_check_line(char *line, t_lemin *new, int c);
int					lm_check_ant(char *ant, t_lemin *lemin);

/*
**lm_check_room.c
*/
int					lm_duplicate_room(char *str, char *pos, t_lemin *new);
int					lm_check_position(char *str);
int					lm_check_room(char *str, t_lemin *new, int m);
int					lm_new_room(t_lemin *new);
int					lm_fill_room(char *str, int len, t_lemin *new, int m);

/*
** lm_check_link.c
*/
int					lm_link_names(char **array, t_lemin *new);
int					lm_check_link(char *str, t_lemin *new);
int					lm_check_dash(char *str, t_lemin *new);
int					lm_dash_len(char *str, int len);
int					lm_new_link(t_lemin *new, int j, int k);

/*
** lm_resolve.c
*/
int					lm_resolve_check(t_nlist *path, int x, t_lemin *lemin);
void				lm_resolve_delete(t_nlist *path);
void				lm_link_found(t_nlist *path, int n, t_lemin *lemin);
void				lm_recursive(t_nlist *path, t_lemin *lemin);
int					lm_resolve(t_lemin *lemin);

/*
** lm_path.c
*/
void				lm_clear_paths(t_lemin *lemin);
void				lm_cn_path(t_dnlist *new, t_nlist *ptr, t_lemin *l);
t_dnlist			*lm_make_path(t_nlist *path, t_lemin *lemin);
void				lm_check_multy_path(t_nlist *path, t_lemin *lemin);
void				lm_save_path(t_nlist *path, t_lemin *lemin);

/*
** lm_trace_path.c
*/
char				*lm_get_name(int nbr, t_lemin *lemin);
void				lm_cpath(t_nlist *ptr, t_dlist *tmp_p, t_lemin *lemin);
void				lm_trace_path(t_lemin *lemin);

/*
** lm_print.c
*/
t_nlist				*lm_add_ant(t_nlist *ant, int *c);
void				lm_print_ants(t_lemin *lemin, t_nlist *ant, int f);
t_nlist				*lm_shift_ant(t_nlist *ant, int len, int *f);
void				lm_print_file(t_lemin *lemin);
int					lm_print(t_lemin *lemin);

/*
** lm_util.c
*/
int					lm_pathlen(t_list *path);
int					lm_nlistlen(t_nlist *path);
int					lm_double_nlistlen(t_dnlist *path);
int					ft_strascii(char *str);
t_list				*lm_lst_append(t_list *list, void *data);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 22:31:20 by hdebard           #+#    #+#             */
/*   Updated: 2016/06/09 17:48:54 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(int argc, char **argv)
{
	t_lemin		*new;

	new = NULL;
	if (argc > 1 || argv[0] == NULL)
		ft_putendl("ERROR");
	else
	{
		if ((new = lm_parse_file()) == NULL)
			ft_putendl("ERROR");
		else
		{
			if (lm_resolve(new) == 0)
				ft_putendl("ERROR");
			else
			{
				lm_trace_path(new);
				lm_print(new);
			}
		}
	}
	return (0);
}

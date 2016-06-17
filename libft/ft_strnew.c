/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 22:30:19 by hdebard           #+#    #+#             */
/*   Updated: 2015/12/04 03:55:22 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*n_str;

	n_str = NULL;
	n_str = (char*)malloc(sizeof(char) * (size + 1));
	if (n_str)
	{
		while (size > 0)
		{
			n_str[size] = '\0';
			size--;
		}
		n_str[size] = '\0';
	}
	return (n_str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 08:11:19 by hdebard           #+#    #+#             */
/*   Updated: 2015/12/04 01:41:54 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*str;
	char			*ptr;
	char			d;

	d = c;
	ptr = NULL;
	str = (char *)s;
	while (*str)
	{
		if (*str == d)
			ptr = str;
		str++;
	}
	if (ptr == NULL && d == 0 && *str == 0)
		ptr = str;
	return (ptr);
}

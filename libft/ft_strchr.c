/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 22:16:22 by hdebard           #+#    #+#             */
/*   Updated: 2015/11/27 10:07:40 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*str;
	unsigned char	d;

	str = (char *)s;
	d = c;
	while (*str)
	{
		if (*str == d)
			return (str);
		str++;
	}
	if (*str == d)
		return (str);
	return (NULL);
}

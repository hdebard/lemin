/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 22:58:40 by hdebard           #+#    #+#             */
/*   Updated: 2015/11/27 09:49:06 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	if (!*s2)
		return ((char*)s1);
	while (s1[i])
	{
		j = 0;
		k++;
		while (s2[j] == s1[i] && s1[i])
		{
			j++;
			i++;
			if (!s2[j])
				return ((char*)s1 + (i - j));
		}
		if (j > 0)
			i = k;
		i++;
	}
	return (NULL);
}

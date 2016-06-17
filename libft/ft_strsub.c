/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 23:14:32 by hdebard           #+#    #+#             */
/*   Updated: 2015/12/04 04:34:19 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*n_str;
	size_t	u;

	u = 0;
	n_str = (char*)malloc(sizeof(char) * (len - start + 1));
	if (n_str)
	{
		while (u < len)
		{
			n_str[u] = s[start + u];
			u++;
		}
		n_str[u] = '\0';
	}
	return (n_str);
}

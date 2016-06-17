/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 23:19:10 by hdebard           #+#    #+#             */
/*   Updated: 2015/12/04 04:35:15 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*n_str;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	n_str = (char*)malloc(sizeof(char) * (len + 1));
	if (n_str)
	{
		while (*s1)
		{
			n_str[i] = *s1;
			i++;
			s1++;
		}
		while (*s2)
		{
			n_str[i] = *s2;
			i++;
			s2++;
		}
		n_str[i] = '\0';
	}
	return (n_str);
}

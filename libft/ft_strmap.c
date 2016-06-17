/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 22:46:05 by hdebard           #+#    #+#             */
/*   Updated: 2015/11/28 05:13:18 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		len;
	int		i;
	char	*n_str;

	i = 0;
	len = ft_strlen(s);
	n_str = NULL;
	n_str = (char*)malloc(sizeof(char) * (len + 1));
	if (n_str)
	{
		while (*s)
		{
			n_str[i] = (*f)(*s);
			s++;
			i++;
		}
		n_str[i] = '\0';
	}
	return (n_str);
}

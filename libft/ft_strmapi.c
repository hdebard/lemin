/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 22:51:01 by hdebard           #+#    #+#             */
/*   Updated: 2015/11/28 08:10:15 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*n_str;
	int				len;

	i = 0;
	len = ft_strlen(s);
	n_str = NULL;
	n_str = (char*)malloc(sizeof(char) * (len + 1));
	if (n_str)
	{
		while (*s)
		{
			n_str[i] = (*f)(i, *s);
			i++;
			s++;
		}
		n_str[i] = '\0';
	}
	return (n_str);
}

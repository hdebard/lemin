/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:57:53 by hdebard           #+#    #+#             */
/*   Updated: 2015/11/28 08:05:33 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*n_str;
	int		len;

	len = ft_strlen(s1) + 1;
	n_str = (char*)malloc(sizeof(char) * len);
	if (n_str != NULL)
	{
		ft_memmove(n_str, s1, len);
		n_str[len - 1] = '\0';
		return (n_str);
	}
	else
		return (NULL);
}

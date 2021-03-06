/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 08:11:49 by hdebard           #+#    #+#             */
/*   Updated: 2015/12/04 04:37:44 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	k;

	j = ft_strlen(s);
	i = 0;
	k = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i++;
	if (i == j)
		return (ft_strdup(""));
	j--;
	while (s[j] && (s[j] == ' ' || s[j] == '\t' || s[j] == '\n'))
		j--;
	if ((str = (char *)malloc((j - i) * sizeof(char) + 1)) == NULL)
		return (NULL);
	while (s[i] && i <= j)
		str[k++] = s[i++];
	str[k] = '\0';
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 00:47:37 by hdebard           #+#    #+#             */
/*   Updated: 2015/12/04 01:37:31 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_word(char const *s, char c)
{
	int		count;
	int		token;

	token = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && token == 0)
		{
			count++;
			token = 1;
		}
		else if (*s == c)
		{
			token = 0;
		}
		s++;
	}
	return (count);
}

static int		ft_word_length(char const *s, char c)
{
	int		len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static char		*ft_append_word(const char *s, char c)
{
	char	*word;
	int		n;
	int		size;

	n = 0;
	size = ft_word_length(s, c);
	word = NULL;
	word = (char*)malloc(sizeof(char) * size + 1);
	if (!word)
		return (NULL);
	while (n < size)
	{
		word[n] = *s;
		s++;
		n++;
	}
	word[n] = '\0';
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**array;
	int		size;
	int		i;
	int		k;

	i = 0;
	k = 0;
	size = ft_count_word(s, c);
	array = NULL;
	array = (char**)malloc(sizeof(char*) * (size + 1));
	if (!array)
		return (NULL);
	while (i < size)
	{
		while (s[k] && s[k] == c)
			k++;
		array[i] = ft_append_word(&s[k], c);
		k += ft_strlen(array[i]);
		i++;
	}
	array[i] = NULL;
	return (array);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 08:00:52 by hdebard           #+#    #+#             */
/*   Updated: 2015/12/04 06:45:22 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int		len;

	len = 0;
	if (n < 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	int		sign;
	size_t	i;
	char	*str;

	i = ft_intlen(n);
	sign = (n < 0) ? -1 : 1;
	str = (char *)malloc(sizeof(char*) * (i + 1));
	if (str)
	{
		str[i] = '\0';
		if (n < 0)
			str[0] = '-';
		if (n == 0)
			ft_strcpy(str, "0");
		while (n != 0)
		{
			str[i - 1] = (n % 10 * sign) + '0';
			n = n / 10;
			i--;
		}
	}
	return (str);
}

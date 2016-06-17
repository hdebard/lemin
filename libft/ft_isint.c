/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 20:15:13 by hdebard           #+#    #+#             */
/*   Updated: 2016/06/08 20:15:52 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_isint(char *str)
{
	long			sign;
	long			nbr;

	nbr = 0;
	sign = 0;
	while (ft_isspace(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + (long)(*str - '0');
		str++;
	}
	nbr = sign * nbr;
	if (nbr > 2147483647 || nbr < -2147483648)
		return (0);
	return (1);
}

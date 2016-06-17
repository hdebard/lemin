/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 02:51:56 by hdebard           #+#    #+#             */
/*   Updated: 2015/11/28 07:50:22 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	void	*ptr;

	ptr = dst;
	while (*src)
		*dst++ = *src++;
	*dst++ = *src++;
	dst = ptr;
	return (dst);
}

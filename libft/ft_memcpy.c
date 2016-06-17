/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 07:58:03 by hdebard           #+#    #+#             */
/*   Updated: 2015/11/28 07:58:05 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*n_dst;
	unsigned char	*n_src;

	n_src = (unsigned char*)src;
	n_dst = (unsigned char*)dst;
	while (n--)
	{
		*n_dst++ = *n_src++;
	}
	return (dst);
}

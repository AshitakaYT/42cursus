/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:19:24 by aucousin          #+#    #+#             */
/*   Updated: 2021/11/09 17:06:35 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove( void *dst, const void *src, size_t size )
{
	const unsigned char	*s;
	unsigned char		*d;

	s = src;
	if (dst <= src)
		return (ft_memcpy(dst, src, size));
	else
	{
		d = dst;
		while (size--)
			d[size] = s[size];
	}
	return (d);
}

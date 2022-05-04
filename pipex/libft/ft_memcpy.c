/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:33:54 by aucousin          #+#    #+#             */
/*   Updated: 2021/11/09 15:07:23 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t			n;
	unsigned char	*s;

	n = 0;
	if (!dest && !src)
		return (NULL);
	s = dest;
	while (n < size)
	{
		*(unsigned char *)dest = *(unsigned char *)src;
		dest++;
		src++;
		n++;
	}
	return (s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:18:51 by aucousin          #+#    #+#             */
/*   Updated: 2021/11/10 15:48:13 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *p1, const void *p2, size_t size)
{
	const unsigned char	*a;
	const unsigned char	*b;

	a = p1;
	b = p2;
	while (size--)
	{
		if (*a != *b)
			return (*a - *b);
		++a;
		++b;
	}
	return (0);
}

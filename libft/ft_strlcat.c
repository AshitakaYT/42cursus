/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 12:29:24 by aucousin          #+#    #+#             */
/*   Updated: 2021/11/10 17:46:49 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char const *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = ft_strlen((const char *)dest);
	j = 0;
	if (size < (unsigned int)ft_strlen((const char *)dest))
		return (size + ft_strlen((const char *)src));
	while (src[j] && i + 1 < size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = 0;
	return (ft_strlen((const char *)dest) + ft_strlen((const char *)&src[j]));
}

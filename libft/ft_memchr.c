/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:12:46 by aucousin          #+#    #+#             */
/*   Updated: 2021/11/09 15:45:47 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memBloc, int searchedChar, size_t size)
{
	while (size)
	{
		if (*(unsigned char *)memBloc == (unsigned char)searchedChar)
			return ((unsigned char *)memBloc);
		memBloc++;
		size--;
	}
	return (NULL);
}

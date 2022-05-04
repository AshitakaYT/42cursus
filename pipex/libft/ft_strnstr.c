/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 00:12:59 by aucousin          #+#    #+#             */
/*   Updated: 2021/11/10 18:24:46 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *str, char const *to_find, size_t n)
{
	size_t	i;
	size_t	j;
	int		k;

	if (!to_find[0])
		return ((char *)str);
	i = 0;
	while (str[i] && i < n)
	{
		j = i;
		k = 0;
		while (to_find[k] && str[j] && str[j] == to_find[k] && j < n)
		{
			j++;
			k++;
			if (!to_find[k])
				return ((char *)&str[i]);
		}
		i++;
	}
	return (0);
}

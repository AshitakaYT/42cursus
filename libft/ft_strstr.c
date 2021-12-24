/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 08:34:40 by aucousin          #+#    #+#             */
/*   Updated: 2021/11/08 15:04:53 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;
	int		k;

	if (!to_find[0])
		return (str);
	i = 0;
	while (str[i])
	{
		j = i;
		k = 0;
		while (to_find[k] && str[j] && str[j] == to_find[k])
		{
			j++;
			k++;
			if (to_find[k] == '\0')
				return (&str[i]);
		}
		i++;
	}
	return (0);
}

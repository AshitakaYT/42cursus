/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 09:16:59 by aucousin          #+#    #+#             */
/*   Updated: 2021/11/10 15:02:09 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		len;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	join = malloc(sizeof(char) * (len + 1));
	if (!join)
		return (NULL);
	while (*s1)
	{
		join[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		join[i] = *s2;
		s2++;
		i++;
	}
	join[i] = '\0';
	return (join);
}

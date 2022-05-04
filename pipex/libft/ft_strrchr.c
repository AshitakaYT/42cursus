/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:39:25 by aucousin          #+#    #+#             */
/*   Updated: 2021/11/10 21:13:47 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
		i++;
	if ((char)c == '\0')
		return (&s[i]);
	j = i - 1;
	while (j >= 0)
	{
		if (s[j] == (char)c)
			return (&s[j]);
		j--;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 20:39:42 by aucousin          #+#    #+#             */
/*   Updated: 2021/11/10 19:36:03 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	size_t			j;

	if (!s)
		return (NULL);
	j = 0;
	if (start >= (unsigned int)ft_strlen(s))
		ret = malloc(sizeof(char));
	else if (len > ft_strlen(s) - start)
		ret = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
		ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	while (start + j < (unsigned int)ft_strlen(s) && j < len)
	{
		ret[j] = s[start + j];
		j++;
	}
	ret[j] = '\0';
	return (ret);
}

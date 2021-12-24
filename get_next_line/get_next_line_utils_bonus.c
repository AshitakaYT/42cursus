/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:16:37 by aucousin          #+#    #+#             */
/*   Updated: 2021/11/18 21:36:53 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&s[i]);
	return (NULL);
}

int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

char	*ft_strjoin(char *s1, char *s2)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 22:49:02 by aucousin          #+#    #+#             */
/*   Updated: 2021/11/10 20:47:04 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char s1, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s1)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_len(char const *s1, char const *set)
{
	int	j;
	int	i;
	int	totallen;

	i = 0;
	j = 0;
	while (s1[i] && ft_isset(s1[i], set))
		i++;
	if (s1[i])
	{
		while (ft_strlen(s1) - j > i
			&& ft_isset(s1[ft_strlen(s1) - j - 1], set))
			j++;
	}
	totallen = ft_strlen(s1) - i - j;
	return (totallen);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*trim;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = 0;
	trim = malloc(sizeof(char) * (ft_len(s1, set) + 1));
	if (!trim)
		return (NULL);
	while (ft_isset(s1[i], set))
		i++;
	while (j < ft_len(s1, set))
	{
		trim[j] = s1[i];
		i++;
		j++;
	}
	trim[j] = '\0';
	return (trim);
}

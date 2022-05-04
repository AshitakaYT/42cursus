/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:17:09 by aucousin          #+#    #+#             */
/*   Updated: 2021/11/10 20:46:12 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free_fct(char **split, int i)
{
	while (i >= 0)
	{
		free(split[i]);
		i--;
	}
	free(split);
	return (NULL);
}

static char	*ft_strndup(char const *src, int n)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (src[j])
		j++;
	if (n < j)
		j = n;
	dest = malloc((j + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (i < j)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	ft_len_word(char const *str, char charset)
{
	int	i;

	i = 0;
	while (str[i] && !(str[i] == charset))
		i++;
	return (i);
}

static int	ft_count_words(char const *str, char charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == charset)
			i++;
		if (str[i] && !(str[i] == charset))
		{
			count++;
			i += ft_len_word(&str[i], charset);
		}
	}
	return (count);
}

char	**ft_split(char const *str, char charset)
{
	char	**split;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	split = malloc(sizeof (char *) * (ft_count_words(str, charset) + 1));
	if (!split)
		return (NULL);
	while (i < ft_count_words(str, charset))
	{
		while (str[j] && str[j] == charset)
			j++;
		split[i] = ft_strndup(&str[j], ft_len_word(&str[j], charset));
		if (!split[i++])
			return (ft_free_fct(split, --i));
		j += ft_len_word(&str[j], charset);
	}
	split[i] = 0;
	return (split);
}

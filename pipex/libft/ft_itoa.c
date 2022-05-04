/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 00:16:42 by aucousin          #+#    #+#             */
/*   Updated: 2021/11/10 20:45:05 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_len(int long nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
	{
		i++;
		nb *= -1;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*newnbr;
	int			j;
	long int	nb2;

	j = 0;
	nb2 = n;
	len = ft_get_len(n);
	newnbr = (char *)malloc((len + 1) * sizeof(char));
	if (!newnbr)
		return (NULL);
	newnbr[len] = '\0';
	if (nb2 < 0)
	{
		nb2 *= -1;
		j = 1;
	}
	while (len--)
	{
		newnbr[len] = (nb2 % 10) + '0';
		nb2 = nb2 / 10;
	}
	if (j == 1)
		newnbr[0] = '-';
	return (newnbr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 10:16:20 by aucousin          #+#    #+#             */
/*   Updated: 2021/11/26 10:35:35 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_base(unsigned long long nbr, char *base, int bytes)
{
	unsigned int	len;

	len = 0;
	bytes++;
	while (base[len])
		len++;
	if (nbr >= len)
		bytes = ft_convert_base(nbr / len, base, bytes);
	ft_putchar_printf(base[nbr % len]);
	return (bytes);
}

int	ft_pnb_printf(int nbr, char *base, int bytes)
{
	long long int	nbr2;
	int				lenbase;

	lenbase = 0;
	while (base[lenbase])
		lenbase++;
	nbr2 = nbr;
	if (ft_check_base(base))
	{
		if (nbr2 < 0)
		{
			ft_putchar_printf('-');
			nbr2 *= -1;
			bytes++;
		}
		bytes = ft_convert_base(nbr2, base, bytes);
	}
	return (bytes);
}

int	ft_pnbu(unsigned int nbr, char *base, int bytes)
{
	long long int	nbr2;
	int				lenbase;

	lenbase = 0;
	while (base[lenbase])
		lenbase++;
	nbr2 = nbr;
	if (ft_check_base(base))
	{
		if (nbr2 < 0)
		{
			nbr2 = 4294967296 + nbr;
			bytes++;
		}
		bytes = ft_convert_base(nbr2, base, bytes);
	}
	return (bytes);
}

int	ft_putnbrbase_ptr_printf(long long nbr, char *base, int bytes)
{
	unsigned long long int	nbr2;
	int						lenbase;

	lenbase = 0;
	while (base[lenbase])
		lenbase++;
	if (nbr == -9223372036854775807)
	{
		nbr2 = LONG_MAX;
		nbr2++;
	}
	else
	nbr2 = nbr;
	if (ft_check_base(base))
	{
		if (nbr2 < 0)
		{
			nbr2 = LONG_MAX + nbr;
			bytes++;
		}
		bytes = ft_convert_base(nbr2, base, bytes);
	}
	return (bytes);
}

int	ft_putptr_printf(long long p)
{
	int	bite;

	bite = ft_putstr_printf("0x");
	bite += ft_putnbrbase_ptr_printf(p, "0123456789abcdef", 0);
	return (bite);
}

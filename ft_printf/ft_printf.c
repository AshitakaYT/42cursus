/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 21:30:07 by aucousin          #+#    #+#             */
/*   Updated: 2021/11/26 10:35:37 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_call_right_function(char c, va_list ap)
{
	long long	p;

	if (c == 'c')
		return (ft_putchar_printf(va_arg(ap, int)));
	else if (c == 's')
		return (ft_putstr_printf(va_arg(ap, char *)));
	else if (c == 'p')
	{
		p = va_arg(ap, long long);
		return (ft_putptr_printf(p));
	}
	else if (c == 'd')
		return (ft_pnb_printf(va_arg(ap, int), "0123456789", 0));
	else if (c == 'i')
		return (ft_pnb_printf(va_arg(ap, int), "0123456789", 0));
	else if (c == 'u')
		return (ft_pnbu(va_arg(ap, unsigned int), "0123456789", 0));
	else if (c == 'x')
		return (ft_pnbu(va_arg(ap, unsigned int), "0123456789abcdef", 0));
	else if (c == 'X')
		return (ft_pnbu(va_arg(ap, unsigned int), "0123456789ABCDEF", 0));
	else if (c == '%')
		return (ft_putchar_printf(c));
	return (0);
}

int	ft_is_variable(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || \
		c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		bytes;

	i = 0;
	bytes = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] != '%')
		{
			bytes += ft_putchar_printf(str[i]);
			i++;
		}
		else if (str[i + 1] && ft_is_variable(str[i + 1]))
		{
			bytes += ft_call_right_function(str[i + 1], ap);
			i += 2;
		}
	}
	return (bytes);
}

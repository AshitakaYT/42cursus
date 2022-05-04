/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:19:40 by aucousin          #+#    #+#             */
/*   Updated: 2021/11/26 10:35:40 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

int	ft_putchar_printf(char c);
int	ft_putstr_printf(char *str);
int	ft_putchar(char c);
int	ft_is_once_in_base(char *base, char c);
int	ft_check_base(char *base);
int	ft_printf(const char *str, ...);
int	ft_convert_base(unsigned long long nbr, char *base, int bytes);
int	ft_pnb_printf(int nbr, char *base, int bytes);
int	ft_pnbu(unsigned int nbr, char *base, int bytes);
int	ft_putnbrbase_ptr_printf(long long nbr, char *base, int bytes);
int	ft_putptr_printf(long long p);
int	ft_call_right_function(char c, va_list ap);
int	ft_is_variable(char c);
int	ft_printf(const char *str, ...);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 22:04:45 by aucousin          #+#    #+#             */
/*   Updated: 2022/05/27 00:27:24 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./hdrs/philosophers.h"

int	main(int ac, char **av)
{
	t_banquet	banquet;

	if (ac < 5 || ac > 6)
	{
		printf("Error : Please enter the right number of arguments.\n");
		return (0);
	}
	else if (!ft_parsing_chars(ac, av) || !ft_zero(av))
	{
		printf("Error : Please input only non-null digits.\n");
		return (0);
	}
	ft_init_banquet(&banquet, ac, av);
	ft_philosophers(&banquet);
	usleep(10000);
	ft_destroy_banquet(&banquet);
	return (0);
}

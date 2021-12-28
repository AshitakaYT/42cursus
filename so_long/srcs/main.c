/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:01:56 by aucousin          #+#    #+#             */
/*   Updated: 2021/12/19 10:40:43 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/so_long.h"

int	ft_close(t_ptrs *ptr)
{
	mlx_destroy_window(ptr->mlx_ptr, ptr->win_ptr);
	exit(EXIT_SUCCESS);
}

int	main(void)
{
	t_ptrs	ptr;

	ptr.mlx_ptr = mlx_init();
	ptr.win_ptr = mlx_new_window(ptr.mlx_ptr, 1000, 1000, "so long");
	mlx_hook(ptr.win_ptr, 17, 1L << 2, ft_close, &ptr);
	mlx_loop(ptr.mlx_ptr);
}

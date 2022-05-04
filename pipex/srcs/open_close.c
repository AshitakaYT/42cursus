/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:14:46 by acousin           #+#    #+#             */
/*   Updated: 2022/05/03 12:28:35 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pipex.h"

void	exit_perror(char *error, int code)
{
	perror(error);
	exit(code);
}

int	close_files(t_pipex *pipex)
{
	close(pipex->file_in);
	close(pipex->file_out);
	return (0);
}

int	open_files(t_pipex *pipex)
{
	pipex->file_out = open(pipex->av[pipex->ac - 1],
			O_CREAT | O_WRONLY | O_TRUNC, 0777);
	pipex->file_in = open(pipex->av[1], O_RDONLY);
	if (pipex->file_out < 0 && pipex->file_in < 0)
	{
		perror(pipex->av[1]);
		perror(pipex->av[pipex->ac - 1]);
		exit(1);
	}
	if (pipex->file_out < 0)
	{
		exit_perror(pipex->av[pipex->ac - 1], 1);
	}
	if (pipex->file_in < 0)
	{
		ft_putstr_fd("0\n", pipex->file_out);
		exit_perror(pipex->av[1], 127);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:23:09 by acousin           #+#    #+#             */
/*   Updated: 2022/05/04 07:26:24 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs/pipex.h"

int	ft_child_status(int child_status)
{
	int	return_val;

	if (WIFEXITED(child_status) != 0)
		return_val = WEXITSTATUS(child_status);
	else
	{
		if (WIFSIGNALED(child_status) != 0)
			return_val = WTERMSIG(child_status) + 128;
		else
			return (0);
	}
	return (return_val);
}

void	ft_pipe(t_pipex *pipex)
{
	int		status;
	pid_t	child1;
	pid_t	child2;

	pipe(pipex->end);
	child1 = fork();
	if (child1 < 0)
		perror("Fork: ");
	if (!child1)
		child_one(pipex);
	child2 = fork();
	if (child2 < 0)
		perror("Fork: ");
	if (!child2)
		child_two(pipex);
	close(pipex->end[0]);
	close(pipex->end[1]);
	waitpid(child1, &status, 0);
	waitpid(child2, &status, 0);
	if (ft_child_status(status) != 0)
		exit (ft_child_status(status));
}

void	ft_pipex(int ac, char **av, char **envp, t_pipex *pipex)
{
	ft_init(pipex);
	ft_init_pipex(ac, av, envp, pipex);
	if (ft_check_good_init(pipex) == 0)
		return ;
	ft_pipe(pipex);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;

	if (ac != 5)
	{
		printf("error\n");
		exit(EXIT_FAILURE);
	}
	ft_pipex(ac, av, envp, &pipex);
	ft_free_maxi(&pipex);
	return (0);
}

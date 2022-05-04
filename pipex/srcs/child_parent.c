/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_parent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:17:59 by acousin           #+#    #+#             */
/*   Updated: 2022/05/04 07:25:40 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pipex.h"

void	child_one(t_pipex *pipex)
{
	int		i;
	char	*cmd;

	close(pipex->end[0]);
	if (dup2(pipex->file_in, STDIN_FILENO < 0))
		perror("Fork: ");
	if (dup2(pipex->file_in, STDIN_FILENO) < 0)
		perror("Fork: ");
	dup2(pipex->end[1], STDOUT_FILENO);
	close(pipex->file_in);
	i = 0;
	while (pipex->paths[i])
	{
		cmd = ft_strjoin(pipex->paths[i], pipex->cmd1[0]);
		if (!cmd)
			exit(EXIT_FAILURE);
		if (access(cmd, F_OK) == 0)
			execve(cmd, pipex->cmd1, pipex->env);
		free(cmd);
		i++;
	}
	write(2, "pipex: command not found: ", 26);
	write(2, pipex->cmd1[0], ft_strlen(pipex->cmd1[0]));
	write(2, "\n", 1);
	exit (1);
}

void	child_two(t_pipex *pipex)
{
	int		i;
	char	*cmd;

	close(pipex->end[1]);
	if (dup2(pipex->file_out, STDOUT_FILENO) < 0)
		perror("Fork: ");
	if (dup2(pipex->end[0], STDIN_FILENO) < 0)
		perror("Fork: ");
	close(pipex->file_out);
	i = 0;
	while (pipex->paths[i])
	{
		cmd = ft_strjoin(pipex->paths[i], pipex->cmd2[0]);
		if (!cmd)
			exit(EXIT_FAILURE);
		if (access(cmd, F_OK) == 0)
			execve(cmd, pipex->cmd2, pipex->env);
		free(cmd);
		i++;
	}
	write(2, "pipex: command not found: ", 26);
	write(2, pipex->cmd2[0], ft_strlen(pipex->cmd2[0]));
	write(2, "\n", 1);
	exit (127);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:20:18 by aucousin          #+#    #+#             */
/*   Updated: 2022/04/26 11:23:00 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pipex.h"

void	ft_add_slash(t_pipex *pipex)
{
	int		i;
	char	*tmp;

	i = 0;
	while (pipex->paths[i])
	{
		if (pipex->paths[i][ft_strlen(pipex->paths[i]) - 1] != '/')
		{
			tmp = pipex->paths[i];
			pipex->paths[i] = ft_strjoin(tmp, "/");
			free(tmp);
		}
		i++;
	}
}

void	ft_init_pipex(int ac, char **av, char **envp, t_pipex *pipex)
{
	char	*path;
	char	*tmp;
	int		i;

	pipex->ac = ac;
	pipex->av = av;
	pipex->env = envp;
	tmp = ft_tabjoin(ft_tablen(envp), envp, "\n");
	if (!tmp)
		return ;
	i = ft_strlen(ft_strstr(tmp, "PATH="));
	path = ft_substr(tmp, ft_strlen(tmp) - i + 5, i - 5);
	free(tmp);
	if (!path)
		return ;
	pipex->paths = ft_split(path, ':');
	free(path);
	ft_add_slash(pipex);
	pipex->cmd1 = ft_split(av[2], ' ');
	if (!pipex->cmd1)
		return ;
	pipex->cmd2 = ft_split(av[3], ' ');
	if (!pipex->cmd2)
		return ;
	open_files(pipex);
}

void	ft_init(t_pipex *pipex)
{
	pipex->paths = NULL;
	pipex->cmd1 = NULL;
	pipex->cmd2 = NULL;
}

int	ft_check_good_init(t_pipex *pipex)
{
	if (!pipex->paths || !pipex->cmd1 || !pipex->cmd2)
	{
		if (!pipex->paths)
			ft_free_tab(pipex->paths);
		if (!pipex->cmd1)
			ft_free_tab(pipex->cmd1);
		if (!pipex->cmd2)
			ft_free_tab(pipex->cmd2);
		return (0);
	}
	return (1);
}

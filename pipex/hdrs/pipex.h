/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:24:24 by acousin           #+#    #+#             */
/*   Updated: 2022/05/03 13:20:07 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>

typedef struct s_pipex
{
	int		ac;
	char	**av;
	char	**env;
	int		file_in;
	int		file_out;
	char	**paths;
	char	**cmd1;
	char	**cmd2;
	char	*error_str;
	int		end[2];
}				t_pipex;

// files

int		close_files(t_pipex *pipex);
int		open_files(t_pipex *pipex);

// family

void	child_one(t_pipex *pipex);
void	child_two(t_pipex *pipex);

//void	parent_process(int f2, char *cmd2);

// init

void	ft_add_slash(t_pipex *pipex);
void	ft_init_pipex(int ac, char **av, char **envp, t_pipex *pipex);
void	ft_init(t_pipex *pipex);
int		ft_check_good_init(t_pipex *pipex);

// utils

char	*ft_tabjoin(int size, char **strs, char *sep);
int		ft_tablen(char **tab);
void	ft_print_tab(char **tab);
void	ft_free_tab(char **tab);
void	ft_free_maxi(t_pipex *pipex);

#endif
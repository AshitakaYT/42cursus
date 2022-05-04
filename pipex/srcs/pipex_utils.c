/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:47:58 by acousin           #+#    #+#             */
/*   Updated: 2022/05/02 09:43:17 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pipex.h"

void	ft_print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		tab[i] = NULL;
		free(tab[i]);
		i++;
	}
	tab = NULL;
	free(tab);
}

void	ft_free_maxi(t_pipex *pipex)
{
	ft_free_tab(pipex->paths);
	ft_free_tab(pipex->cmd1);
	ft_free_tab(pipex->cmd2);
}

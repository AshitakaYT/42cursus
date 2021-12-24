/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 21:57:06 by aucousin          #+#    #+#             */
/*   Updated: 2021/11/09 22:13:14 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*l;
	t_list	*next;

	l = *lst;
	*lst = NULL;
	while (l)
	{
		if (del)
			del(l->content);
		next = l->next;
		free(l);
		l = next;
	}
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 20:19:19 by aucousin          #+#    #+#             */
/*   Updated: 2021/11/10 18:22:34 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int				ft_atoi(char const *str);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
char			*ft_itoa(int n);
void			*ft_memcpy(void *dest, const void *src, size_t size);
void			*ft_memmove( void *dest, const void *src, size_t size );
void			*ft_memset(void *b, int c, size_t len);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
char			**ft_split(char const *str, char charset);
char			*ft_strchr(char *s, int c);
char			*ft_strdup(char *src);
void			ft_striteri( char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dest, char const *src, unsigned int size);
size_t			ft_strlcpy(char *dest, const char *src, unsigned int size);
int				ft_strlen(char const *str);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strncmp(char const *s1, char const *s2, size_t n);
char			*ft_strnstr(char const *str, char const *to_find, size_t n);
char			*ft_strrchr(char *s, int c);
char			*ft_strstr(char *str, char *to_find);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_tolower(int c);
int				ft_toupper(int c);
void			*ft_memchr(const void *memBloc, int searchedChar, size_t size);
int				ft_memcmp(const void *p1, const void *p2, size_t size);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstadd_front(t_list **begin_list, t_list *data);
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst,
					void *(*f)(void *), void (*del)(void *));
t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);

#endif
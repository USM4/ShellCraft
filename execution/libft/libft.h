/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:13:46 by mohtakra          #+#    #+#             */
/*   Updated: 2023/08/26 19:12:59 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <string.h>
# include <errno.h>
# include <stdbool.h>
/*functions declaration.*/
int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_tolower(int c);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atoi(const char *str);
char	*ft_strdup(const char *s);
/*the part two functions declaration*/
char	*ft_itoa(int nbr);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_freematrix(char **matrix);
char	**ft_split(char const *s, char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
/*Bonus part*/

typedef struct s_list
{
	char			*key;
	char			*value;
	int				pipe[2];
	int				infile;
	int				outfile;
	struct s_list	*cmd;
	struct s_list	*next;
	struct s_list	*previous;
}	t_list;

void	del(char *str);
t_list	*ft_lstnew(char *key, char *value);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(char *));
void	ft_lstclear(t_list **lst, void (*del)(char *));
#endif

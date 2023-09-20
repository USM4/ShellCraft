/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:52:40 by oredoine          #+#    #+#             */
/*   Updated: 2023/09/14 17:08:07 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include "./../../libstatus.h"

extern t_llist		*ft_lstlastp(t_llist *lst);
extern t_llist		*ft_lstnewp(void *content);
extern t_llist		*ft_lstnewp2(void *content);
extern int			ft_lstsizep(t_llist *lst);
extern void			ft_lstadd_backp(t_llist **lst, t_llist *new);
extern char			*ft_substrp(char const *s, unsigned int start, size_t len);
extern int			ft_strlenp(const char *p);
extern void			ft_clean(char **arr);
extern void			ft_lstclearp(t_llist **lst);
extern void			ft_putstr_fd(char *s, int fd);
extern int			ft_strcmp( const char *s1, const char *s2);
extern char			*ft_strjoinp(char const *s1, char const *s2);
extern char			*ft_strdupp(const char *s1);
extern void			ft_lstdelonep(t_llist *lst);
extern char			*check_is_string(char *str);
extern t_llist		*tokenizing(char *cmd_line);
extern int			ft_isalphap(char a);
extern int			is_alphanum_under(char c);
extern t_llist		*preparing_env(char **env);
extern char			*expand(char *str, t_llist *env_list);
extern char			*ft_strcpy(char *dst, char *src);
extern char			*get_next_line(int fd);
extern char			*ft_itoap(int n);
extern int			process_here_doc(t_llist **iterator, t_llist *env_list);
extern int			process_output_token(t_pass *arg, \
t_llist **iterator, int flags);
extern int			process_input_token(t_pass *arg, t_llist **iterator);
extern int			errors_handling(t_llist **head);
extern int			fd_protection(int fd, char *str);
extern char			*remove_single_quotes(char *str);
extern char			*remove_double_quotes(char *str);
extern void			concatinate_strings(t_llist **head);
extern void			remove_space(t_llist **head);
extern t_llist		*parse_data(char *cmd_line, t_llist *env_list);
extern t_llist		*share_with(t_llist *head, t_llist *env_list);
extern t_tools		*initialize_tools(void);
extern int			len_key(char *str, int i);
extern void			handle_dollar_question_mark(t_tools **bridge, int *i);
extern void			variable_value(t_llist *env_list, t_tools **bridge);
extern int			is_key( t_llist *head, char *key);
extern int			is_wspace(char c);
extern int			size_arg(char **arg);
extern char			**generate_cmd_list(char **arg, char *new_arg);
extern char			*single_quotes(char *str);
extern char			*double_quotes(char *str);
extern t_tokenize	*create_token(t_tokens token, char *str);
extern int			is_redirection(char *cmd_line, int i);
extern void			input_append_output(t_llist **head, char *cmd_line, int i);
extern int			is_pipe_heredoc_space(char *cmd_line, int i);
extern int			is_heredoc(char *cmd_line, int i);
extern int			is_pipe(char *cmd_line, int i);
extern int			is_output(char *cmd_line, int i);
extern int			is_input(char *cmd_line, int i);
extern int			is_append(char *cmd_line, int i);
extern int			single_q_utils(t_llist **head, char *cmd_line, int i);
extern int			double_q_utils(t_llist **head, char *cmd_line, int i);
extern void			*my_malloc(size_t size);
extern int			open_file_to_write(char *file);
extern int			here_doc(t_llist **iterator, t_llist *env_list);
extern void			skip_wspaces(t_tokenize *token, t_llist **iterator);
extern void			to_iterate_delimiter_type(t_llist **iterator);
extern void			expand_strings(t_llist *env_list, t_tokenize *token);
extern void			fd_protection_input(int fd, char *filename);

#endif

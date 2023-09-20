/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libminishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:54:42 by mohtakra          #+#    #+#             */
/*   Updated: 2023/09/14 06:29:50 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMINISHELL_H
# define LIBMINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <stdbool.h>
# include <dirent.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <string.h>
# include <sys/stat.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/param.h>

# ifndef LIBFT_H
#  include "./libft/libft.h"
# endif
# ifndef LIBERROR_H_
#  include "./error_handler/liberror.h"
# endif

# include "./../libstatus.h"

t_list	*convert_env_to_list(char **env);
t_list	*convert_matrix_to_list(char **matrix);
char	**convert_list_to_matrix(t_list *lst);
int		execution(t_list *command, t_list *env, t_list **p_ids);
int		execute_list(t_list *lst, t_list **env);
int		is_builtins(t_list *lst);
bool	is_echo(char *command);
bool	is_cd(char *command);
bool	is_pwd(char *command);
bool	is_export(char *command);
bool	is_unset(char *command);
bool	is_env(char *command);
bool	is_exit(char *command);
int		pipe_builtins(t_list *lst, t_list *env, t_list **p_ids);
int		builtins_no_output(t_list *lst, t_list **env);
bool	is_variable_exists(char *key, t_list *env);
char	*get_variable_value(char *key, t_list *env);
char	*get_variable_name(char *str);
int		get_variable_len(char *str);
char	*get_path_of_cmd(t_list *env, char *cmd);
bool	update_env_value(char *key, char *new_key, t_list *env);
int		echo(t_list *cmd_lst);
void	env_(t_list *env);
void	cd(t_list *cmd_lst, t_list **env);
bool	is_valid_identifier(char *str);
void	print_export(t_list *env);
int		export(t_list *cmd_lst, t_list **env);
void	ft_lstswap(t_list *lsta, t_list *lstb);
void	pwd(void);
void	unset(t_list **env, t_list *cmd_lst);
void	exit_(t_list *cmd_lst);
void	update_shlvl(t_list **env);
int		pipe_end(t_list *lst, char **argv, char **envp, t_list **p_ids);
int		pipe_middle(t_list *lst, char **argv, char **envp, t_list **p_ids);
int		pipe_beginning(t_list *lst, char **argv, char **envp, t_list **p_ids);
void	close_pipe(int pipe_fd[2]);
int		read_from_fd(int fd);
void	set_status(int status);
void	kill_child_proccs(t_list *p_ids);
void	fork_failure(t_list *lst);
bool	is_dir(char *str);

#endif

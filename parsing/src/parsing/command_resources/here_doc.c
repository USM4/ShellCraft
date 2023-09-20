/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 05:08:26 by takra             #+#    #+#             */
/*   Updated: 2023/09/14 14:43:17 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	sighandle(int sig)
{
	if (sig == SIGINT)
	{
		ft_putstr_fd("\n", 1);
		exit(1);
	}
}

static void	write_to_heredoc(char *delem, t_llist *env, int fd_out)
{
	char	*here_doc_line;
	char	*tmp;

	signal(SIGINT, &sighandle);
	here_doc_line = readline("->");
	if (!here_doc_line || ft_strcmp(here_doc_line, delem) == 0)
	{
		if (here_doc_line)
			free(here_doc_line);
		else
			ft_putstr_fd("\n", 1);
		exit(0);
	}
	if (t_stats.delimiter_expand)
	{
		tmp = expand(here_doc_line, env);
		free(here_doc_line);
		here_doc_line = tmp;
	}
	ft_putstr_fd(here_doc_line, fd_out);
	ft_putstr_fd("\n", fd_out);
	free(here_doc_line);
}

int	here_doc(t_llist **iterator, t_llist *env_list)
{
	t_tokenize	*token;
	int			fd_pipe[2];
	int			st;
	pid_t		pid;

	pipe(fd_pipe);
	token = (t_tokenize *)(*iterator)->content;
	t_stats.flag_sigint = 1;
	pid = fork();
	if (pid == -1)
		return (ft_putstr_fd(strerror(errno), 2), -1);
	if (pid == 0)
	{
		close(fd_pipe[0]);
		while (1)
			write_to_heredoc(token->value, env_list, fd_pipe[1]);
		close(fd_pipe[1]);
		exit(0);
	}
	close(fd_pipe[1]);
	waitpid(pid, &st, 0);
	t_stats.flag_sigint = 0;
	if (st == 256)
		t_stats.here_doc_stat = 0;
	return (fd_pipe[0]);
}

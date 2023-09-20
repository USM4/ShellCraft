/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:49:39 by takra             #+#    #+#             */
/*   Updated: 2023/09/14 06:26:59 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libminishell.h"

static void	pipe_builtins_infile(t_list *lst)
{
	if (lst->infile > 0)
	{
		dup2(lst->infile, 0);
		close(lst->infile);
	}
	else if (lst->previous != NULL)
	{
		dup2(lst->previous->pipe[0], 0);
		close(lst->previous->pipe[0]);
	}
	close(lst->pipe[0]);
}

static void	pipe_builtins_outfile(t_list *lst)
{
	if (lst->outfile >= 0)
	{
		dup2(lst->outfile, 1);
		close(lst->outfile);
	}
	else if (lst->next != NULL)
	{
		dup2(lst->pipe[1], 1);
	}
	close(lst->pipe[1]);
}

static int	execut_output_builtins(t_list *cmd_lst, t_list *env)
{
	if (is_exit(cmd_lst->value))
	{
		if (ft_lstsize(cmd_lst) == 1)
			t_stats.status = 0;
		else
		{
			cmd_lst = cmd_lst->next;
			t_stats.status = ft_atoi(cmd_lst->value);
		}
		return (t_stats.status);
	}
	if (is_echo(cmd_lst->value))
	{
		return (echo(cmd_lst));
	}
	if (is_env(cmd_lst->value))
		return (env_(env), EXIT_SUCCESS);
	if (is_export(cmd_lst->value) && ft_lstsize(cmd_lst) == 1)
		return (export(cmd_lst, &env));
	if (is_pwd(cmd_lst->value))
		return (pwd(), t_stats.status);
	return (EXIT_FAILURE);
}

static void	ft_lstclearall(t_list *lst)
{
	t_list	*tmp;

	while (lst->previous != NULL)
		lst = lst->previous;
	tmp = lst;
	while (tmp)
	{
		ft_lstclear(&(tmp->cmd), del);
		tmp = tmp->next;
	}
	ft_lstclear(&lst, del);
}

int	pipe_builtins(t_list *lst, t_list *env, t_list **procc_ids)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (fork_failure(lst), EXIT_FAILURE);
	else if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		pipe_builtins_infile(lst);
		pipe_builtins_outfile(lst);
		t_stats.status = execut_output_builtins(lst->cmd, env);
		ft_lstclearall(lst);
		ft_lstclear(&env, del);
		ft_lstclear(procc_ids, del);
		exit (t_stats.status);
	}
	ft_lstadd_back(procc_ids, ft_lstnew(NULL, ft_itoa((int)pid)));
	close(lst->pipe[1]);
	if (lst->next == NULL)
		close(lst->pipe[0]);
	if (lst->previous != NULL)
		close(lst->previous->pipe[0]);
	return (EXIT_SUCCESS);
}

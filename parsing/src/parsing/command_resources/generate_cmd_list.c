/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_cmd_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 22:09:12 by oredoine          #+#    #+#             */
/*   Updated: 2023/09/13 22:36:10 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	process_other_tokens(t_pass *arg, t_llist **iterator)
{
	t_tokenize	*token;

	if ((*iterator))
	{
		token = (t_tokenize *)(*iterator)->content;
		arg->argument_cmd = generate_cmd_list(arg->argument_cmd, token->value);
		*iterator = (*iterator)->next;
	}
}

int	process_input_redirection(t_llist **iterator, t_pass *arg)
{
	if (process_input_token(arg, iterator) == 1)
		return (0);
	(*iterator) = (*iterator)->next;
	return (1);
}

static int	redirection_processes(t_llist **iterator, \
t_tokenize *token, t_pass *arg, t_llist *env_list)
{
	if (token->type == INPUT)
		return (process_input_redirection(iterator, arg));
	else if (token->type == OUTPUT)
	{
		if (process_output_token(arg, iterator, \
		O_CREAT | O_TRUNC | O_RDWR))
			return (0);
		(*iterator) = (*iterator)->next;
	}
	else if (token->type == APPEND)
	{
		if (process_output_token(arg, iterator, O_CREAT | O_APPEND | O_RDWR))
			return (0);
		(*iterator) = (*iterator)->next;
	}
	else if (token->type == HERE_DOC)
	{
		if (arg->infile > 0)
			close(arg->infile);
		arg->infile = process_here_doc(iterator, env_list);
		(*iterator) = (*iterator)->next;
	}
	return (1);
}

static int	process(t_tokenize *token, t_llist **iterator, \
t_pass *arg, t_llist *env_list)
{
	if (token->type >= INPUT && token->type <= APPEND)
	{
		if (!redirection_processes(iterator, token, arg, env_list))
			return (0);
	}
	else
		process_other_tokens(arg, iterator);
	return (1);
}

t_llist	*share_with(t_llist *head, t_llist *env_list)
{
	t_llist		*iterator;
	t_llist		*cmd_list;
	t_tokenize	*token;
	t_pass		*arg;

	iterator = head;
	cmd_list = NULL;
	while (iterator)
	{
		arg = my_malloc(sizeof(t_pass));
		*arg = (t_pass){.argument_cmd = NULL, .infile = -2, .outfile = -2};
		while (iterator)
		{
			token = (t_tokenize *)iterator->content;
			if (token->type == PIPE)
				break ;
			if (!process(token, &iterator, arg, env_list))
				return (NULL);
		}
		ft_lstadd_backp(&cmd_list, ft_lstnewp(arg));
		if (iterator)
			iterator = iterator->next;
	}
	return (cmd_list);
}

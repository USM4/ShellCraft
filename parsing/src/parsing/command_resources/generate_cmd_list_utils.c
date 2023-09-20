/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_cmd_list_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 21:59:26 by oredoine          #+#    #+#             */
/*   Updated: 2023/09/14 17:10:18 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_pipes(t_llist *iterator)
{
	t_tokenize	*token;
	int			counter;

	counter = 0;
	while (iterator)
	{
		token = (t_tokenize *)(iterator)->content;
		if (token->type == PIPE)
			counter++;
		iterator = iterator->next;
	}
	return (counter);
}

int	process_input_token(t_pass *arg, t_llist **iterator)
{
	t_tokenize	*token;
	int			counter;

	*iterator = (*iterator)->next;
	if (arg->infile > 0)
		close(arg->infile);
	token = (t_tokenize *)(*iterator)->content;
	arg->infile = open(token->value, O_RDONLY, 0777);
	counter = count_pipes(*iterator);
	if (counter == 0)
	{
		if (fd_protection(arg->infile, token->value) == 1)
			return (1);
	}
	else if (counter > 0)
		fd_protection_input(arg->infile, token->value);
	return (0);
}

int	process_output_token(t_pass *arg, t_llist **iterator, int flags)
{
	t_tokenize	*token;

	*iterator = (*iterator)->next;
	token = (t_tokenize *)(*iterator)->content;
	if (arg->outfile > 0)
		close(arg->outfile);
	arg->outfile = open(token->value, flags, 0777);
	if (count_pipes(*iterator) == 0)
	{
		if (fd_protection(arg->outfile, token->value) == 1)
			return (1);
	}
	else if (count_pipes(*iterator) > 0)
		fd_protection_input(arg->outfile, token->value);
	return (0);
}

int	process_here_doc(t_llist **iterator, t_llist *env_list)
{
	int		infile;

	(*iterator) = (*iterator)->next;
	infile = here_doc(iterator, env_list);
	if (infile == -1)
		return (-2);
	return (infile);
}

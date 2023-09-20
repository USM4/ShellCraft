/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 22:14:52 by oredoine          #+#    #+#             */
/*   Updated: 2023/09/14 17:09:21 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	redirection_errors_handling(t_llist *iterator)
{
	t_tokenize	*next_token;

	if (!iterator->next)
		return (1);
	next_token = (t_tokenize *)iterator->next->content;
	if (next_token->type != STRING && next_token->type != S_QUOTES)
		return (1);
	return (0);
}

int	pipes_errors_handling(t_llist *iterator, int i)
{
	t_tokenize	*token;
	t_tokenize	*next_token;

	token = (t_tokenize *)iterator->content;
	if (token->type == PIPE && i == 1)
		return (1);
	else if (iterator->next)
	{
		next_token = (t_tokenize *)iterator->next->content;
		if (token->type == PIPE && next_token->type == PIPE)
			return (1);
	}
	else if (token->type == PIPE && !iterator->next)
		return (1);
	return (0);
}

int	errors_handling(t_llist **head)
{
	t_llist		*iterator;
	t_tokenize	*token;
	int			i;

	i = 1;
	iterator = *head;
	while (iterator)
	{
		token = (t_tokenize *)iterator->content;
		if (token->type >= INPUT && token->type <= APPEND)
			if (redirection_errors_handling(iterator))
				return (t_stats.status = 258, \
				ft_putstr_fd(\
				"\033[31mminishell :Syntax error near unexpected token\033[0m\n"\
				, 2), 1);
		if (token->type == PIPE)
			if (pipes_errors_handling(iterator, i))
				return (t_stats.status = 258, ft_putstr_fd(\
				"\033[31mminishell :Syntax error near unexpected token\033[0m\n" \
				, 2), 1);
		iterator = iterator->next;
		i++;
	}
	return (0);
}

int	fd_protection(int fd, char *filename)
{
	if (fd == -1)
	{
		ft_putstr_fd("\033[31mminishell: ", 2);
		ft_putstr_fd(filename, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\033[0m\n", 2);
		t_stats.status = 1;
		return (1);
	}
	return (0);
}

void	fd_protection_input(int fd, char *filename)
{
	if (fd == -1)
	{
		ft_putstr_fd("\033[31mminishell: ", 2);
		ft_putstr_fd(filename, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\033[0m\n", 2);
		t_stats.status = 0;
	}
}

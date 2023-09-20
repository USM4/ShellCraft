/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 21:56:10 by oredoine          #+#    #+#             */
/*   Updated: 2023/09/09 23:09:39 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_llist	*remove_token_node(t_llist **iter, t_tokenize *token, t_tokenize *n_t)
{
	t_llist	*tmp_iterator;
	char	*concatenated_value;
	t_llist	*to_remove;

	concatenated_value = NULL;
	tmp_iterator = *iter;
	concatenated_value = ft_strjoinp(token->value, n_t->value);
	free(token->value);
	token->value = concatenated_value;
	to_remove = tmp_iterator->next;
	tmp_iterator->next = tmp_iterator->next->next;
	ft_lstdelonep(to_remove);
	return (tmp_iterator);
}

void	concatinate_strings(t_llist **head)
{
	t_llist		*iterator;
	t_tokenize	*token;
	t_tokenize	*next_token;

	iterator = *head;
	while (iterator)
	{
		if (iterator->next != NULL)
		{
			token = (t_tokenize *)iterator->content;
			next_token = (t_tokenize *)iterator->next->content;
			if (token->type == STRING && next_token->type == STRING)
				iterator = remove_token_node(&iterator, token, next_token);
			else
				iterator = iterator->next;
		}
		else
			iterator = iterator->next;
	}
}

void	task_for_else(t_llist **prev, t_llist **iterator)
{
	(*prev) = (*iterator);
	(*iterator) = (*iterator)->next;
}

void	remove_space(t_llist **head)
{
	t_llist		*iterator;
	t_llist		*tmp;
	t_llist		*prev;
	t_tokenize	*token;

	iterator = *head;
	prev = NULL;
	while (iterator)
	{
		token = (t_tokenize *)iterator->content;
		if (token->type == WSPACEE)
		{
			tmp = iterator;
			iterator = iterator->next;
			if (prev)
				prev->next = iterator;
			else
				*head = iterator;
			ft_lstdelonep(tmp);
		}
		else
			task_for_else(&prev, &iterator);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:31:35 by oredoine          #+#    #+#             */
/*   Updated: 2023/09/14 15:53:53 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	to_set_delimiter_flag(t_llist **iterator)
{
	while ((*iterator) && ((t_tokenize *)(*iterator)->content)->type != WSPACEE)
	{
		if (((t_tokenize *)(*iterator)->content)->type == STRING)
			t_stats.delimiter_expand = 1;
		else
		{
			t_stats.delimiter_expand = 0;
			break ;
		}
		(*iterator) = (*iterator)->next;
	}
}

void	check_delimiter_to_expand(t_llist **head)
{
	t_llist		*tmp;
	t_tokenize	*token;

	tmp = *head;
	while (tmp)
	{
		token = (t_tokenize *)tmp->content;
		if (token->type == HERE_DOC)
		{
			if (tmp->next)
			{
				tmp = tmp->next;
				token = (t_tokenize *)tmp->content;
				skip_wspaces(token, &tmp);
				token = (t_tokenize *)tmp->content;
				to_set_delimiter_flag(&tmp);
				continue ;
			}
		}
		tmp = tmp->next;
	}
}

void	expand_call(t_llist **head, t_llist *env_list)
{
	t_tokenize	*token;
	t_llist		*iterator;

	iterator = *head;
	check_delimiter_to_expand(head);
	while (iterator)
	{
		token = (t_tokenize *)iterator->content;
		if (token->type == HERE_DOC)
		{
			if (iterator->next)
			{
				iterator = iterator->next;
				token = (t_tokenize *)iterator->content;
				skip_wspaces(token, &iterator);
				token = (t_tokenize *)iterator->content;
				to_iterate_delimiter_type(&iterator);
				continue ;
			}
		}
		else if (token->type == STRING || token->type == D_QUOTES)
			expand_strings(env_list, token);
		iterator = iterator->next;
	}
}

t_llist	*remove_quotes(t_llist **head)
{
	t_tokenize	*token;
	t_llist		*iterator;

	iterator = *head;
	while (iterator)
	{
		token = (t_tokenize *)iterator->content;
		if (token->type == S_QUOTES)
		{
			token->value = remove_single_quotes(token->value);
			token->type = STRING;
		}
		else if (token->type == D_QUOTES)
		{
			token->value = remove_double_quotes(token->value);
			token->type = STRING;
		}
		iterator = iterator->next;
	}
	return (iterator);
}

t_llist	*parse_data(char *cmd_line, t_llist *env_list)
{
	t_llist	*head_tokens;
	t_llist	*iterator;

	iterator = NULL;
	head_tokens = tokenizing(cmd_line);
	if (!head_tokens)
		return (NULL);
	expand_call(&head_tokens, env_list);
	remove_quotes(&head_tokens);
	iterator = head_tokens;
	concatinate_strings(&iterator);
	remove_space(&iterator);
	if (errors_handling(&iterator))
		return (NULL);
	iterator = share_with(iterator, env_list);
	return (iterator);
}

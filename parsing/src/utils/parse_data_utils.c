/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 13:28:02 by oredoine          #+#    #+#             */
/*   Updated: 2023/09/10 19:03:23 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	skip_wspaces(t_tokenize *token, t_llist **iterator)
{
	while (token->type == WSPACEE && (*iterator)->next)
	{
		(*iterator) = (*iterator)->next;
		token = (t_tokenize *)(*iterator)->content;
	}
}

void	to_iterate_delimiter_type(t_llist **iterator)
{
	t_tokenize	*token;

	token = (t_tokenize *)(*iterator)->content;
	while ((*iterator) && token->type != WSPACEE)
	{
		token = (t_tokenize *)(*iterator)->content;
		(*iterator) = (*iterator)->next;
	}
}

void	expand_strings(t_llist *env_list, t_tokenize *token)
{
	if (token->type == D_QUOTES)
		token->value = remove_double_quotes(token->value);
	if (token->value[0])
		token->value = expand(token->value, env_list);
	token->type = STRING;
}

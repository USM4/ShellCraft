/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:01:16 by oredoine          #+#    #+#             */
/*   Updated: 2023/09/05 20:22:48 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipe_heredoc_space(t_llist **head, char *cmd_line, int i)
{
	if (is_pipe(cmd_line, i))
		ft_lstadd_backp(head, ft_lstnewp(create_token(PIPE, "|")));
	else if (is_heredoc(cmd_line, i))
		ft_lstadd_backp(head, ft_lstnewp(create_token(HERE_DOC, "<<")));
	else if (is_wspace (cmd_line[i]))
		ft_lstadd_backp(head, ft_lstnewp(create_token(WSPACEE, " ")));
}

int	is_single_q(char *cmd_line, int i)
{
	if (cmd_line[i] == '\'')
		return (1);
	return (0);
}

int	is_double_q(char *cmd_line, int i)
{
	if (cmd_line[i] == '\"')
		return (1);
	return (0);
}

t_llist	*double_single_q(t_llist **head, char *cmd_line, int i)
{
	if (is_double_q(cmd_line, i) && !double_q_utils(head, cmd_line, i))
		return (NULL);
	if (is_single_q(cmd_line, i) && !single_q_utils(head, cmd_line, i))
		return (NULL);
	return (*head);
}

t_llist	*tokenizing(char *cmd_line)
{
	int			i;
	t_llist		*head;
	t_tokenize	*tmp_token;

	i = 0;
	head = NULL;
	while (cmd_line[i])
	{
		if (is_pipe_heredoc_space(cmd_line, i))
			pipe_heredoc_space(&head, cmd_line, i);
		else if (is_redirection(cmd_line, i))
			input_append_output(&head, cmd_line, i);
		else if (is_single_q(cmd_line, i) || is_double_q(cmd_line, i))
		{
			if (!double_single_q(&head, cmd_line, i))
				return (NULL);
		}
		else
			ft_lstadd_backp(&head, ft_lstnewp(\
			create_token(STRING, check_is_string(cmd_line + i))));
		tmp_token = (t_tokenize *)ft_lstlastp(head)->content;
		i += ft_strlenp(tmp_token->value);
	}
	return (head);
}

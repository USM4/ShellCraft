/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 20:03:56 by oredoine          #+#    #+#             */
/*   Updated: 2023/09/05 20:04:22 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_redirection(char *cmd_line, int i)
{
	if (is_append(cmd_line, i))
		return (1);
	if (is_input(cmd_line, i))
		return (1);
	if (is_output(cmd_line, i))
		return (1);
	return (0);
}

void	input_append_output(t_llist **head, char *cmd_line, int i)
{
	if (is_input(cmd_line, i))
		ft_lstadd_backp(head, ft_lstnewp(create_token(INPUT, "<")));
	else if (is_append(cmd_line, i))
		ft_lstadd_backp(head, ft_lstnewp(create_token(APPEND, ">>")));
	else if (is_output(cmd_line, i))
		ft_lstadd_backp(head, ft_lstnewp(create_token(OUTPUT, ">")));
}

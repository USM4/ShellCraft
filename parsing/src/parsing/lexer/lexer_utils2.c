/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 20:02:35 by oredoine          #+#    #+#             */
/*   Updated: 2023/09/05 20:25:22 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_pipe(char *cmd_line, int i)
{
	if (cmd_line[i] == '|')
		return (1);
	return (0);
}

int	is_heredoc(char *cmd_line, int i)
{
	if (cmd_line[i] == '<' && cmd_line[i + 1] == '<')
		return (1);
	return (0);
}

int	is_pipe_heredoc_space(char *cmd_line, int i)
{
	if (is_pipe(cmd_line, i))
		return (1);
	if (is_heredoc(cmd_line, i))
		return (1);
	if (is_wspace(cmd_line[i]))
		return (1);
	return (0);
}

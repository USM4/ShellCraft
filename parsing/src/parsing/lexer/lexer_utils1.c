/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 20:01:28 by oredoine          #+#    #+#             */
/*   Updated: 2023/09/09 14:33:57 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	double_q_utils(t_llist **head, char *cmd_line, int i)
{
	char	*string;

	string = double_quotes(cmd_line + i);
	if (string)
		ft_lstadd_backp(head, ft_lstnewp(create_token(D_QUOTES, string)));
	else
	{
		ft_putstr_fd("\033[31mminishell :", 2);
		ft_putstr_fd(" Unclosed double Quotes\033[0m\n", 2);
		t_stats.status = 258;
		ft_lstclearp(head);
		return (0);
	}
	return (1);
}

int	single_q_utils(t_llist **head, char *cmd_line, int i)
{
	char	*string;

	string = single_quotes(cmd_line + i);
	if (string)
		ft_lstadd_backp(head, ft_lstnewp(create_token(S_QUOTES, string)));
	else
	{
		ft_putstr_fd("\033[31mminishell :", 2);
		ft_putstr_fd(" Unclosed single Quotes\033[0m\n", 2);
		t_stats.status = 258;
		ft_lstclearp(head);
		return (0);
	}
	return (1);
}

int	is_append(char *cmd_line, int i)
{
	if (cmd_line[i] == '>' && cmd_line[i + 1] == '>')
		return (1);
	return (0);
}

int	is_input(char *cmd_line, int i)
{
	if (cmd_line[i] == '<')
		return (1);
	return (0);
}

int	is_output(char *cmd_line, int i)
{
	if (cmd_line[i] == '>')
		return (1);
	return (0);
}

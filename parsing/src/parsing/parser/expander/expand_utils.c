/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:04:10 by oredoine          #+#    #+#             */
/*   Updated: 2023/09/10 16:19:26 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_alphanum_under(char c)
{
	if (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) || \
	(c >= '0' && c <= '9') || c == '_')
		return (1);
	return (0);
}

int	ft_isalphap(char a)
{
	if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122))
		return (1);
	else
		return (0);
}

t_tools	*initialize_tools(void)
{
	t_tools	*tools;

	tools = my_malloc(sizeof(t_tools));
	if (tools != NULL) 
	{
		tools->tmp = NULL;
		tools->add = NULL;
		tools->cutter = NULL;
		tools->key = NULL;
	}
	return (tools);
}

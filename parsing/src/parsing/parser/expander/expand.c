/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:03:03 by oredoine          #+#    #+#             */
/*   Updated: 2023/09/13 17:57:35 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_default_case(t_tools **bridge, char *str, int *i)
{
	int	j;

	j = *i;
	*i += 1;
	while (str[*i] && str[*i] != '$')
		(*i)++;
	if (!(*bridge)->add)
		(*bridge)->add = ft_substrp(str, j, *i - j);
	else
	{
		(*bridge)->cutter = ft_substrp(str, j, *i - j);
		(*bridge)->add = ft_strjoinp((*bridge)->add, (*bridge)->cutter);
	}
}

static void	handle_primary_cases(t_tools **bridge, int *i, \
char *str, t_llist *env_list)
{
	t_llist	*iterator_env;
	int		len;

	len = len_key(str, *i + 1);
	iterator_env = env_list;
	(*bridge)->key = ft_substrp(str, *i + 1, len);
	if (!ft_strcmp((*bridge)->key, ""))
	{
		if (!(*bridge)->add)
			(*bridge)->add = ft_strdupp("");
		(*bridge)->add = ft_strjoinp((*bridge)->add, "$");
	}
	else if (is_key(iterator_env, (*bridge)->key))
		variable_value(iterator_env, bridge);
	*i += len + 1;
}

void	process_expand(char *str, t_llist *env_list, t_tools **bridge)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1] == '?')
		{
			handle_dollar_question_mark(bridge, &i);
			continue ;
		}
		else
		{
			if (str[i] == '$' && str[i + 1] && str[i + 1] != '$')
				handle_primary_cases(bridge, &i, str, env_list);
			else
				handle_default_case(bridge, str, &i);
		}
	}
}

char	*expand(char *str, t_llist *env_list)
{
	t_tools	*bridge;

	bridge = initialize_tools();
	process_expand(str, env_list, &bridge);
	return (bridge->add);
}

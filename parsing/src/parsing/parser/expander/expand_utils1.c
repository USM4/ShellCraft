/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:34:13 by oredoine          #+#    #+#             */
/*   Updated: 2023/09/13 17:57:14 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_key( t_llist *head, char *key)
{
	t_llist	*iterator_env;
	t_env	*tmp;

	iterator_env = head;
	while (iterator_env)
	{
		tmp = (t_env *)iterator_env->content;
		if (!ft_strcmp(key, tmp->key))
			return (1);
		iterator_env = iterator_env->next;
	}
	return (0);
}

void	variable_value(t_llist *env_list, t_tools **bridge)
{
	t_llist	*iterator_env;

	iterator_env = env_list;
	while (iterator_env)
	{
		(*bridge)->tmp = (t_env *)iterator_env->content;
		if ((!ft_strcmp((*bridge)->key, (*bridge)->tmp->key)))
		{
			if (!(*bridge)->add)
				(*bridge)->add = ft_strdupp("");
			(*bridge)->add = ft_strjoinp((*bridge)->add, \
			(*bridge)->tmp->value);
			break ;
		}
		iterator_env = iterator_env->next;
	}
}

int	len_key(char *str, int i)
{
	int	len;

	len = 0;
	while (str[i] && (is_alphanum_under(str[i])))
	{
		len++;
		i++;
	}
	return (len);
}

void	handle_dollar_question_mark(t_tools **bridge, int *i)
{
	if (!(*bridge)->add)
		(*bridge)->add = ft_strdupp("");
	(*bridge)->add = ft_strjoinp((*bridge)->add, ft_itoap(t_stats.status));
	*i += 2;
}

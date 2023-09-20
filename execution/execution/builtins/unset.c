/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:48:29 by takra             #+#    #+#             */
/*   Updated: 2023/09/10 19:10:02 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../libminishell.h"

void	link_data(t_list **env, t_list **tmp)
{
	if ((*tmp)->previous != NULL && (*tmp)->next != NULL)
	{
		((*tmp)->previous)->next = (*tmp)->next;
		((*tmp)->next)->previous = (*tmp)->previous;
	}
	else if ((*tmp)->next == NULL && (*tmp)->previous != NULL)
		(*tmp)->previous->next = NULL;
	else if ((*tmp)->previous == NULL && (*tmp)->next != NULL)
	{
		*env = (*env)->next;
		(*tmp)->next->previous = NULL;
	}
	else if ((*tmp)->previous == NULL && (*tmp)->next == NULL)
	{
		*env = NULL;
	}
}

static int	check_var(char *var)
{
	if (!is_valid_identifier(var))
	{
		ft_putstr_fd("minishell: export: `", 2);
		ft_putstr_fd(var, 2);
		ft_putstr_fd("\': not a valid identifier\n", 2);
		t_stats.status = 256;
		return (0);
	}
	return (1);
}

/*remove a variable from the envirement's data*/
void	unset(t_list **env, t_list *cmd_lst)
{
	t_list	*tmp;
	t_list	*to_delete;
	char	*variable_name;

	while (cmd_lst)
	{
		tmp = *env;
		variable_name = cmd_lst->value;
		while (check_var(variable_name) && \
		is_variable_exists(variable_name, *env) && env && *env && tmp)
		{
			if (ft_strcmp(tmp->key, variable_name) == 0)
			{
				to_delete = tmp;
				link_data(env, &tmp);
				ft_lstdelone(to_delete, del);
				break ;
			}
			tmp = tmp->next;
		}
		cmd_lst = cmd_lst->next;
	}
	return ;
}

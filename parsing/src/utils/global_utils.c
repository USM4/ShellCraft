/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:38:30 by oredoine          #+#    #+#             */
/*   Updated: 2023/09/09 23:10:21 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_env	*create_env_nodes(char *key, char *value)
{
	t_env	*envirement;

	envirement = my_malloc(sizeof(t_env));
	if (!envirement)
		return (NULL);
	envirement->key = key;
	envirement->value = value;
	return (envirement);
}

t_llist	*preparing_env(char **env)
{
	int		i;
	int		j;
	t_llist	*env_list;

	i = 0;
	env_list = NULL;
	while (env[i])
	{
		j = 0;
		while (env[i][j] != '=')
			j++;
		ft_lstadd_backp(&env_list, ft_lstnewp(\
		create_env_nodes(ft_substrp(env[i], 0, j), \
		ft_substrp(env[i], j + 1, ft_strlenp(env[i])))));
		i++;
	}
	return (env_list);
}

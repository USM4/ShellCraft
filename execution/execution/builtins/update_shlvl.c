/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_shlvl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:48:40 by takra             #+#    #+#             */
/*   Updated: 2023/09/07 00:33:04 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../libminishell.h"

/*increment envirement variable "SHLVL" if exits else create it with value 1*/
void	update_shlvl(t_list **env)
{
	char	*itoa;

	if (*env && is_variable_exists("SHLVL", *env))
	{
		if (ft_atoi(get_variable_value("SHLVL", *env)) >= 999 \
		|| ft_atoi(get_variable_value("SHLVL", *env)) < 0)
		{
			free(get_variable_value("SHLVL", *env));
			update_env_value("SHLVL", "1", *env);
		}
		else
		{
			itoa = ft_itoa(ft_atoi(get_variable_value("SHLVL", *env)) + 1);
			free(get_variable_value("SHLVL", *env));
			update_env_value("SHLVL", itoa, *env);
			free(itoa);
		}
	}
	else if (env && !is_variable_exists("SHLVL", *env))
	{
		ft_lstadd_back(env, ft_lstnew(ft_strdup("SHLVL"), ft_strdup("1")));
	}
}

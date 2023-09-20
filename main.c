/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:45:19 by oredoine          #+#    #+#             */
/*   Updated: 2023/09/14 18:16:04 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libglobalminishell.h"

static void	handler(int sig)
{
	if (sig == SIGINT)
	{
		if (t_stats.flag_sigint == 1)
		{
			ft_putstr_fd("", 1);
		}
		else
		{
			printf("\n");
			rl_on_new_line();
			rl_replace_line("", 1);
			rl_redisplay();
			t_stats.status = 1;
		}
	}
}

int	main(int ac, char **av, char **env)
{
	t_llist	*env_list;
	t_list	*env_lst;

	(void)ac;
	(void)av;
	signal(SIGINT, &handler);
	signal(SIGQUIT, SIG_IGN);
	t_stats.flag_sigint = 0;
	t_stats.delimiter_expand = 0;
	t_stats.status = 0;
	env_list = preparing_env(env);
	env_lst = convert_parsing_env_to_execution(env_list);
	update_shlvl(&env_lst);
	ft_lstclearp(&env_list);
	env_list = convert_execution_env_to_parsing(env_lst);
	while (1)
	{
		ft_lstclear(&env_lst, del);
		env_lst = convert_parsing_env_to_execution(env_list);
		prompt(&env_lst, env_list);
		ft_lstclearp(&env_list);
		env_list = convert_execution_env_to_parsing(env_lst);
	}
}

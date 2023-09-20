/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_child_proccs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:33:25 by mohtakra          #+#    #+#             */
/*   Updated: 2023/09/14 17:48:06 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libminishell.h"

void	kill_child_proccs(t_list *p_ids)
{
	pid_t	pid;

	if (!p_ids)
		return ;
	while (p_ids->next != NULL)
		p_ids = p_ids->next;
	while (p_ids)
	{
		pid = (pid_t)ft_atoi(p_ids->value);
		if (pid != 0 && pid != -1)
		{
			kill(pid, SIGKILL);
		}
		p_ids = p_ids->previous;
	}
	t_stats.status = 1;
}

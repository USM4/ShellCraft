/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_back.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 23:20:40 by oredoine          #+#    #+#             */
/*   Updated: 2023/09/04 14:31:42 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstadd_backp(t_llist **lst, t_llist *new)
{
	if (*lst)
		ft_lstlastp(*lst)->next = new;
	else
		*lst = new;
}

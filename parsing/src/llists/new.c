/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 19:59:31 by oredoine          #+#    #+#             */
/*   Updated: 2023/09/06 17:31:49 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_llist	*ft_lstnewp(void *content)
{
	t_llist	*newnode;

	newnode = my_malloc(sizeof(t_llist));
	if (!newnode)
		return (NULL);
	newnode->content = content;
	newnode->next = NULL;
	return (newnode);
}

t_llist	*ft_lstnewp2(void *content)
{
	t_llist	*newnode;

	newnode = malloc(sizeof(t_llist));
	if (!newnode)
		return (NULL);
	newnode->content = content;
	newnode->next = NULL;
	return (newnode);
}

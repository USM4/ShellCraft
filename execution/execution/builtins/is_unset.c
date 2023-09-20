/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:48:08 by takra             #+#    #+#             */
/*   Updated: 2023/09/05 03:12:02 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../libminishell.h"

bool	is_unset(char *command)
{
	if (!command)
		return (false);
	if (!ft_strcmp(command, "unset"))
		return (true);
	return (false);
}

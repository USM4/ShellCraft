/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:47:57 by takra             #+#    #+#             */
/*   Updated: 2023/09/05 03:11:49 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../libminishell.h"

bool	is_export(char *command)
{
	if (!command)
		return (false);
	if (!ft_strcmp(command, "export"))
		return (true);
	return (false);
}

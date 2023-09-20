/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:47:36 by takra             #+#    #+#             */
/*   Updated: 2023/09/05 03:12:09 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../libminishell.h"

bool	is_cd(char *command)
{
	if (!command)
		return (false);
	if (!ft_strcmp(command, "cd"))
		return (true);
	return (false);
}

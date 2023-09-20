/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:46:40 by oredoine          #+#    #+#             */
/*   Updated: 2023/09/09 23:10:21 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*remove_single_quotes(char *str)
{
	int		i;
	int		start;
	char	*string;

	i = 0;
	start = 0;
	if (str[i] == '\'')
		i++;
	start = i;
	while (str[i] && str[i] != '\'')
		i++;
	string = ft_substrp(str, start, i - 1);
	return (string);
}

char	*remove_double_quotes(char *str)
{
	int		i;
	int		start;
	char	*string;

	start = 0;
	i = 0;
	if (str[i] == '\"')
		i++;
	start = i;
	while (str[i] && str[i] != '\"')
		i++;
	string = ft_substrp(str, start, i - 1);
	return (string);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:00:19 by oredoine          #+#    #+#             */
/*   Updated: 2023/09/09 23:10:21 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_is_token(char c)
{
	if (c == '<' || c == '>' \
	|| c == '\'' || c == '\"' \
	|| c == '|' || c == ' ')
		return (1);
	return (0);
}

char	*check_is_string(char *str)
{
	char	*string;
	int		index;
	int		len;

	len = 0;
	index = 0;
	string = NULL;
	while (str[len])
	{
		if (check_is_token(str[len]) == 0)
			len++;
		else
			break ;
	}
	string = ft_substrp(str, index, len);
	return (string);
}

char	*single_quotes(char *str)
{
	int		i;
	char	*return_value;

	i = 1;
	while (str[i] && str[i] != '\'')
		i++;
	if (!str[i])
		return (NULL);
	return_value = ft_substrp(str, 0, i + 1);
	return (return_value);
}

char	*double_quotes(char *str)
{
	int		i;
	char	*return_value;

	i = 1;
	while (str[i] && str[i] != '\"')
		i++;
	if (!str[i])
		return (NULL);
	return_value = ft_substrp(str, 0, i + 1);
	return (return_value);
}

t_tokenize	*create_token(t_tokens token, char *str)
{
	t_tokenize	*mytoken;

	if (!str)
		return (NULL);
	mytoken = my_malloc(sizeof(t_tokenize));
	if (!mytoken)
		return (NULL);
	mytoken->type = token;
	mytoken->value = str;
	return (mytoken);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:07:27 by oredoine          #+#    #+#             */
/*   Updated: 2023/09/09 23:34:59 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_substrp(char const *s, unsigned int start, size_t len)

{
	char			*str;
	size_t			i;
	unsigned int	ls;

	i = 0;
	if (!s)
		return (NULL);
	ls = ft_strlenp(s);
	if (start >= ls)
	{
		str = my_malloc(1);
		*str = '\0';
		return (str);
	}
	if (len > ls - start)
		len = ls - start;
	str = my_malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s[start] && i < len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

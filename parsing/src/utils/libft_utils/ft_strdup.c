/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 23:34:21 by oredoine          #+#    #+#             */
/*   Updated: 2023/09/09 23:34:28 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (!dst && !src && n)
		return (NULL);
	d = (unsigned char *) dst;
	s = (unsigned char *) src;
	i = 0 ;
	while (i < n)
	{
		*(d + i) = *(s + i);
		i++;
	}
	return (d);
}

char	*ft_strdupp(const char *s1)
{
	int		len;
	char	*s2;

	len = ft_strlenp(s1);
	s2 = my_malloc(len + 1);
	if (s2 == NULL)
		return (NULL);
	ft_memcpy(s2, s1, len + 1);
	return (s2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:51:41 by oredoine          #+#    #+#             */
/*   Updated: 2023/09/10 16:19:00 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	sign_corrector(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	size_to_allocate(int d)
{
	int	len;

	len = 0;
	if (d == 0)
		return (1);
	if (d < 0)
	{
		d *= -1;
		len++;
	}
	while (d > 0)
	{
		d /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoap(int n)
{
	char	*b;
	int		size;

	if (n == -2147483648)
		return (ft_strdupp("-2147483648"));
	size = size_to_allocate(n);
	b = my_malloc(sizeof(char) * (size + 1));
	if (!b)
		return (NULL);
	b[size] = '\0';
	if (n == 0)
	{
		b[0] = '0';
		return (b);
	}
	if (n < 0)
		b[0] = '-';
	while (n != 0)
	{
		b[size - 1] = sign_corrector(n) % 10 + '0';
		n /= 10;
		size--;
	}
	return (b);
}

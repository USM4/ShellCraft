/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_cmd_list_utils1.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:55:08 by oredoine          #+#    #+#             */
/*   Updated: 2023/09/13 19:22:01 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	size_arg(char **arg)
{
	int	i;

	i = 0;
	if (!arg)
		return (0);
	while (arg[i])
		i++;
	return (i);
}

static char	**copy_arg(char **arg, char **tmp, int *i)
{
	int	j;

	(*i) = 0;
	while (arg[(*i)])
	{
		tmp[(*i)] = my_malloc(sizeof(char) * (ft_strlenp(arg[(*i)]) + 1));
		if (!tmp[(*i)])
			return (NULL);
		j = 0;
		while (arg[(*i)][j])
		{
			tmp[(*i)][j] = arg[(*i)][j];
			j++;
		}
		tmp[(*i)][j] = '\0';
		(*i)++;
	}
	return (tmp);
}

static char	**copy_new_arg(char **tmp, int i, char *new_arg)
{
	int	j;

	j = 0;
	tmp[i] = my_malloc(sizeof(char) * (ft_strlenp(new_arg) + 1));
	if (!tmp[i])
		return (NULL);
	if (new_arg)
	{
		while (new_arg[j])
		{
			tmp[i][j] = new_arg[j];
			j++;
		}
	}
	tmp[i][j] = '\0';
	tmp[i + 1] = NULL;
	return (tmp);
}

char	**generate_cmd_list(char **arg, char *new_arg)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = my_malloc(sizeof(char *) * (size_arg(arg) + 2));
	if (!tmp)
		return (NULL);
	if (arg && arg[i])
		tmp = copy_arg(arg, tmp, &i);
	if (new_arg)
		tmp = copy_new_arg(tmp, i, new_arg);
	if (!arg && !new_arg)
		tmp = NULL;
	return (tmp);
}

int	open_file_to_write(char *file)
{
	int	fd;

	fd = open(file, O_CREAT | O_RDWR, 0777);
	if (fd == -1)
	{
		ft_putstr_fd("\033[31mminishell :\
		error openning heredoc file\033[0m\n", 2);
		return (-1);
	}
	return (fd);
}

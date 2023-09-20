/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_env_to_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:48:51 by takra             #+#    #+#             */
/*   Updated: 2023/09/02 18:48:52 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libminishell.h"

// void	print_matrix(char **matrix)
// {
// 	int	i = 0;
// 	int j;

// 	ft_putchar_fd('{', 1);
// 	while (matrix[i])
// 	{
// 		j = 0;
// 		ft_putchar_fd('[', 1);
// 		ft_putstr_fd(matrix[i], 1);
// 		ft_putchar_fd(']', 1);
// 		ft_putchar_fd(',', 1);
// 		ft_putchar_fd('\n', 1);
// 		i++;
// 	}
// 	ft_putchar_fd('}', 1);
// 	ft_putchar_fd('\n', 1);
// }

/*return a list pointer created from the double pointer entered (env)*/
t_list	*convert_env_to_list(char **env)
{
	char	*value;
	char	*key;
	t_list	*new;
	t_list	*lst;

	lst = NULL;
	if (env && *env)
	{
		while (*env)
		{
			key = get_variable_name(*env);
			value = getenv(key);
			new = ft_lstnew(key, ft_strdup(value));
			if (new == NULL)
				return (NULL);
			ft_lstadd_back(&lst, new);
			env++;
		}
	}
	return (lst);
}

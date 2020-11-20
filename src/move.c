/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cotis <cotis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 03:44:27 by cotis             #+#    #+#             */
/*   Updated: 2020/11/03 00:39:07 by cotis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*struct		s_node				*deletehead(t_node *root)
{
	t_node		*temp;

	if (root->next == NULL)
	{
		set_term_type(TERM_CANON);
		free(root);
		free(root->next);
		free(root->back);
		exit(0);
	}
	temp = root->next;
	temp->argc = root->argc - 1;
	temp->num = root->num;
	temp->argv = root->argv;
	temp->back = NULL;
	free(root);
	return (temp);
}

struct		s_node				*print_list(t_node *list, t_node *root)
{
	t_node		*temp;
	int			i;

	if (win_size(root->argc, root->argv) == -1)
		return (0);
	i = 0;
	temp = root;
	while (temp != NULL)
	{
		i++;
		argv_print(list, temp);
		print_space(root, temp);
		if (i == win_size(root->argc, root->argv))
		{
			ft_putstr_fd("\n", STDERR_FILENO);
			i = 0;
		}
		temp = temp->next;
	}
	ft_putstr_fd("\n", STDERR_FILENO);
	return (0);
}

void							argv_print(t_node *list, t_node *temp)
{
	if (temp == list && temp->num == 2)
	{
		ft_putstr_fd("\e[1;21;4;7m", STDERR_FILENO);
		ft_putstr_fd(temp->data, STDERR_FILENO);
		ft_putstr_fd("\e[0m", STDERR_FILENO);
	}
	else if (temp != list && temp->num == 2)
	{
		ft_putstr_fd("\e[7m", STDERR_FILENO);
		ft_putstr_fd(temp->data, STDERR_FILENO);
		ft_putstr_fd("\e[0m", STDERR_FILENO);
	}
	else if (temp == list && temp->num == 0)
	{
		ft_putstr_fd("\e[4m", STDERR_FILENO);
		ft_putstr_fd(temp->data, STDERR_FILENO);
		ft_putstr_fd("\e[0m", STDERR_FILENO);
	}
	else if (temp != list && temp->num == 0)
		ft_putstr_fd(temp->data, STDERR_FILENO);
}

void							print_space(t_node *root, t_node *temp)
{
	int		sum;

	sum = max_argv(root->argv) - ft_strlen(temp->data + 1);
	while (sum != 1)
	{
		ft_putstr_fd(" ", STDERR_FILENO);
		sum--;
	}
}*/

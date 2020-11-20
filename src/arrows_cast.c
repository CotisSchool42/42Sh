/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows_cast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cotis <cotis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 02:56:38 by cotis             #+#    #+#             */
/*   Updated: 2020/11/03 00:34:15 by cotis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*struct		s_node				*ar_del(t_node *list, t_node *root)
{
	clean_window();
	list = deletelem(list);
	root->argc = root->argc - 1;
	list = ar_next(list, root);
	return (list);
}

struct		s_node				*argv_del(t_node *list, t_node *root)
{
	int i;

	i = 0;
	while (root->argv[i] != 0)
	{
		if (list->data == root->argv[i])
			root->argv[i] = "1";
		i++;
	}
	return (root);
}

struct		s_node				*ar_head(t_node *list, t_node *root)
{
	clean_window();
	root = deletehead(root);
	list = root;
	print_list(list, root);
	return (list);
}

struct		s_node				*ar_ent(t_node *list, t_node *root)
{
	clean_window();
	if (list->num == 2)
	{
		list->num = 0;
		list = ar_next(list, root);
		return (list);
	}
	else
		list->num = 2;
	list = ar_next(list, root);
	return (list);
}

struct		s_node				*ar_return(t_node *root)
{
	t_node *temp;

	clean_window();
	temp = root;
	while (temp != NULL)
	{
		if (temp->num == 2)
		{
			ft_putstr_fd(temp->data, STDOUT_FILENO);
			ft_putstr_fd(" ", STDOUT_FILENO);
		}
		temp = temp->next;
	}
	set_term_type(TERM_CANON);
	exit(0);
}*/

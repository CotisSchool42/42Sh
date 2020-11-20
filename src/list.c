/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cotis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 03:44:27 by cotis             #+#    #+#             */
/*   Updated: 2020/10/23 05:55:51 by cotis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

struct		s_node				*init()
{
	t_node *list;
	char buf;
	long c;

	c = 0;
	read(STDOUT_FILENO, &c , 8);
	if (c == DOWN_KEY || c == UP_KEY ||  c == LEFT_KEY || c == RIGHT_KEY)
		return (NULL);
	list = (t_node *)ft_memalloc(sizeof(t_node));

/*	if (c == CHAR_RETURN)
	{
		*//* функция переходящая на другую строку и mi-a3 *//*
	}
	fprintf(stderr, "%ld", c);
 */

	buf = (char)c;
	list->data = buf;
	list->next = NULL;
	list->back = NULL;
	write(STDERR_FILENO, &list->data, 1);
	return (list);
}

struct	s_node					*endpoint(t_node *list, t_node *root)
{
	t_node	*tail;

	list = root;
	while (list != NULL)
	{
		if (list->next == NULL)
			tail = list;
		list = list->next;
	}
	return (tail);
}

struct	s_node					*deletelem(t_node *list)
{
	t_node *back;
	t_node *next;

	back = list->back;
	next = list->next;
	tputs(tgetstr("le", NULL), 1, ft_printnbr);
	tputs(tgetstr("dc", NULL), 1, ft_printnbr);
	if (back != NULL)
		back->next = list->next;
	if (next != NULL)
		next->back = list->back;
	free(list);
	return (back);
}



struct		s_node				*deletehead(t_node *root)
{
	t_node		*temp;

	temp = root;

	return (temp);
}

/* Добавляет элементы в лист и инициализирует root */
struct	s_node					*addelem(t_node *list, t_node *root)
{
	t_node		*temp;
	t_node		*p;
	long 		c;
	char 		buf;

	read(STDOUT_FILENO, &c , 8);
	if()
		list = k_move(list, root, c);
	temp = (t_node *)ft_memalloc(sizeof(t_node));
	p = list->next;
	buf = (char)c;
	list->next = temp;
	temp->data = buf;
	temp->next = p;
	temp->back = list;
	if (p != NULL)
		p->back = temp;
	write(STDERR_FILENO, &temp->data, 1);
	return (temp);
}


#include "sh.h"

void		print_list(t_node *root)
{
	t_node *temp;

	temp = root;
	write(STDIN_FILENO, "LINE:", 30);
	while (temp != NULL)
	{
		write(STDIN_FILENO, &temp->data, 1);
		temp = temp->next;
	}
	exit (0);
}

int		read_line(void)
{
	t_node	*list;
	t_node	*root;
	long	c;

	list = NULL;
	c = 0;
	while (1)
	{
		if (list == NULL)	/* Инициализация и проверка первого элемента */
		{
				root = init();
				list = root;
		}
		else
		{
			list = addelem(list, root);
	//		write(STDIN_FILENO, &list->back->data, 1);
		}
	//	list = k_move(list, root, c);
//		if (c == BSP_KEY)
	//		list = deletelem(list);
		if (c == CHAR_RETURN)
		{
			clean_window();
			print_list(root);
			exit (0);
		}
	}
	return (0);
}

struct s_node 	*escape(t_node *list, t_node *root,  long c)
{
	if (c == DOWN_KEY || c == UP_KEY)
		return (list);
	if (c == LEFT_KEY && list->back != NULL)
	{
		tputs(tgetstr("le", NULL), 1, ft_printnbr);
		list = list->back;
	}
	if (c == RIGHT_KEY)
	{
		if (list->next != NULL) {
			tputs(tgetstr("nd", NULL), 1, ft_printnbr);
			list = list->next;
		}
		if (list->next == root) {
			tputs(tgetstr("nd", NULL), 1, ft_printnbr);
			list = list->next;
		}
	}
	return (list);
}

struct	s_node					*k_move(t_node *list, t_node *root, long c)
{

	if (c == LEFT_KEY || c == RIGHT_KEY)
	{
		list = escape(list, root, c);
		return (list);
	}
	if (c == BSP_KEY)
	{
		list = deletelem(list);
		//	write(STDERR_FILENO, &list->data, 1);
		return (list);
	}
	return (list);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   customization_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cotis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 23:50:56 by cotis             #+#    #+#             */
/*   Updated: 2020/09/23 23:51:18 by cotis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		clean_window(void)
{
	tputs(tgetstr("cl", NULL), 1, ft_printnbr);
}

int			ft_printnbr(int nbr)
{
	return (write(STDERR_FILENO, &nbr, 1));
}

void		get_term_conf(void)
{
	tcgetattr(STDIN_FILENO, &g_newsettings);
	g_oldsettings = g_newsettings;
}

void		set_term_canon(void)
{
	tputs(tgetstr("te", NULL), 1, ft_printnbr);
	tcsetattr(STDIN_FILENO, TCSANOW, &g_oldsettings);
}

void		set_term_non_canon(void)
{
//	g_newsettings.c_iflag &= ~(ICRNL);
//	g_newsettings.c_oflag &= ~(OPOST | ONLCR);
//	g_newsettings.c_lflag &= ~(ECHO | ECHONL | ICANON| IEXTEN);
	g_newsettings.c_lflag &= ~( ECHO | ICANON| IEXTEN);
//	g_newsettings.c_lflag |= ~(ECHOE  );
//	g_newsettings.c_lflag |= ~(ISIG |  ECHOE  | ECHONL |ECHOKE | PENDIN);
//	g_newsettings.c_cflag &= ~(CSIZE | PARENB);
//	g_newsettings.c_cflag |= CS8;
	tputs(tgetstr("cl", NULL), 1, ft_printnbr);
	tputs(tgetstr("ti", NULL), 1, ft_printnbr);
	g_newsettings.c_cc[VMIN] = 1;
	g_newsettings.c_cc[VTIME] = 1;
	g_newsettings.c_cc[VEOF] = _POSIX_VDISABLE;
	tcsetattr(STDIN_FILENO,  TCSAFLUSH, &g_newsettings);
}

void		termtype(void)
{
	char	*termtype;
	int		ok;
	char	buffer[2048];
	int		fd;

	fd = STDOUT_FILENO;
	if (isatty(fd))
		termtype = getenv("TERM");
	else
	{
		printf("fd %d не является терминалом! \n", fd);
		exit(0);
	}
	ok = tgetent(buffer, termtype);
	if (ok != 1)
	{
		printf("Имеются некоторые проблемы с терминалом");
		exit(1);
	}
}

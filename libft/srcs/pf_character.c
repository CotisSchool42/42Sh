/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_character.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cotis <cotis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 01:55:38 by cotis             #+#    #+#             */
/*   Updated: 2020/06/02 01:55:38 by cotis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		percent_char(t_printf *p)
{
	if (!p->flags.min && p->min_length - 1 > 0)
		ft_putnchar(p->min_length - 1, (p->flags.zero) ? '0' : ' ');
	ft_putwchar('%', 4);
	if (p->flags.min)
		ft_putnchar(p->min_length - 1, (p->flags.zero) ? '0' : ' ');
	return (MAX(p->min_length, 1));
}

void	pf_character(va_list ap, t_printf *p)
{
	unsigned	c;
	int			len;

	c = va_arg(ap, unsigned);
	len = (p->lm.llong) ? ft_wcharlen(c) : 1;
	if (!p->flags.min)
		ft_putnchar(p->min_length - MIN(len, p->min_length),
		(p->flags.zero) ? '0' : ' ');
	(p->lm.llong) ? ft_putwchar(c, 4) : ft_putchar(c);
	if (p->flags.min)
		ft_putnchar(p->min_length - MIN(len, p->min_length), ' ');
	p->len += MAX(p->min_length, len);
}

void	pf_putchar(char c, t_printf *p)
{
	write(1, &c, 1);
	++p->len;
}

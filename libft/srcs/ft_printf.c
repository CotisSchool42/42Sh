/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cotis <cotis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 03:19:17 by cotis             #+#    #+#             */
/*   Updated: 2020/06/02 03:19:17 by cotis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *format, ...)
{
	va_list		ap;
	t_printf	p;

	va_start(ap, format);
	p.len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			if (!format[1] || (format[1] == ' ' && (!format[2]
										|| (!format[3] && format[2] == 'h'))))
				break ;
			p.printed = 0;
			format = parse_optionals(++format, ap, &p);
			if (*format == '%')
				p.len += percent_char(&p);
			format = conversion_specifier(format, ap, &p);
		}
		else
			pf_putchar(*format, &p);
		++format;
	}
	va_end(ap);
	return (p.len);
}

char	*conversion_specifier(char *format, va_list ap, t_printf *p)
{
	(ft_strchr("CDSUOB", *format)) ? p->lm.llong = 1 : 0;
	p->cs.upcase = (*format == 'X') ? 1 : 0;
	(*format == 'x' || *format == 'X') ? pf_putnb_base(16, ap, p) : 0;
	(*format == 'u' || *format == 'U') ? pf_putnb_base(10, ap, p) : 0;
	(*format == 'o' || *format == 'O') ? pf_putnb_base(8, ap, p) : 0;
	(*format == 'b' || *format == 'B') ? pf_putnb_base(2, ap, p) : 0;
	(ft_strchr("dDi", *format)) ? pf_putnb(ap, p) : 0;
	(*format == 'c' || *format == 'C') ? pf_character(ap, p) : 0;
	(*format == 's' && !p->lm.llong) ? p->len += pf_string(ap, p) : 0;
	if (*format == 'S' || (*format == 's' && p->lm.llong))
		p->len += pf_wide_string(ap, p);
	(*format == 'p') ? p->len += print_pointer_address(ap, p) : 0;
	(*format == 'n') ? *va_arg(ap, int *) = p->len : 0;
	(*format == 'm') ? p->len += ft_printf_putstr(strerror(errno), p) : 0;
	(*format == 'f' || *format == 'F') ? pf_putdouble(ap, p) : 0;
	if (*format == '{')
		return (color(format, p));
	if (!ft_strchr("sSpdDibBoOuUxXcC%nmfF", *format))
		cs_not_found(format, p);
	return (format);
}

void	ft_putnchar(int len, char c)
{
	char	*s;

	if (!(s = (char *)malloc(sizeof(char) * len + 1)))
		return ;
	s[len] = '\0';
	while (len--)
		s[len] = c;
	ft_putstr_free(s);
}

int		print_pointer_address(va_list ap, t_printf *p)
{
	int				sp_padding;
	char			*s;
	void			*pointer;

	pointer = va_arg(ap, void *);
	p->flags.sharp = 0;
	p->min_length -= (p->flags.zero ? 2 : 0);
	s = itoa_base_printf((uintmax_t)pointer, 16, p);
	sp_padding = (p->printed > p->min_length - 2) ? 0 :
					p->min_length - 2 - p->printed;
	if (!p->flags.min)
		ft_putnchar(sp_padding, ((p->flags.zero) ? '0' : ' '));
	ft_putstr("0x");
	ft_putstr_free(s);
	if (p->flags.min)
		ft_putnchar(sp_padding, ((p->flags.zero) ? '0' : ' '));
	return (MAX(p->printed + 2, p->min_length));
}

void	cs_not_found(char *format, t_printf *p)
{
	if (!p->flags.min && p->min_length > 1)
		ft_putnchar(p->min_length - 1, p->flags.zero ? '0' : ' ');
	p->min_length > 1 ? p->len += p->min_length - 1 : 0;
	pf_putchar(*format, p);
	if (p->flags.min && p->min_length > 1)
		ft_putnchar(p->min_length - 1, p->flags.zero ? '0' : ' ');
}

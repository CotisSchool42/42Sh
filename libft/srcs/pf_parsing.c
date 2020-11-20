/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cotis <cotis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 01:57:18 by cotis             #+#    #+#             */
/*   Updated: 2020/06/02 01:57:18 by cotis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*parse_optionals(char *format, va_list ap, t_printf *p)
{
	p->flags = (t_flags) {.sharp = 0, .zero = 0, .min = 0, .plus = 0, .sp = 0};
	p->min_length = 0;
	p->precision = 1;
	p->apply_precision = 0;
	p->lm = (t_length_modifier)
		{.sshort = 0, .llong = 0, .intmax = 0, .sizet = 0};
	if (*format == '*' && ++format)
		wildcard_length_modifier(ap, p);
	format = parse_flags(format, &p->flags);
	format = field_width(format, p);
	format = precision(format, p);
	format = length_modifier(format, &p->lm);
	format = parse_flags(format, &p->flags);
	if (*format == '*' && ++format)
		wildcard_length_modifier(ap, p);
	return (format);
}

char	*parse_flags(char *format, t_flags *flags)
{
	while (ft_strchr("#0+- ", *format))
	{
		if (*format == '#')
			flags->sharp = 1;
		else if (*format == '0')
			flags->zero = 1;
		else if (*format == '+')
			flags->plus = 1;
		else if (*format == '-')
			flags->min = 1;
		else if (*format == ' ')
			flags->sp = 1;
		++format;
	}
	if (flags->min)
		flags->zero = 0;
	if (flags->plus)
		flags->sp = 0;
	return (format);
}

char	*field_width(char *format, t_printf *p)
{
	if (ft_strchr("123456789", *format))
	{
		p->min_length = MAX(1, ft_atoi(format));
		while (ft_strchr("0123456789", *format))
			++format;
	}
	return (format);
}

char	*precision(char *format, t_printf *p)
{
	int value;

	if (ft_strchr(".", *format))
	{
		value = ft_atoi(++format);
		p->precision = MAX(value, 0);
		while (ft_strchr("0123456789", *format))
			++format;
		p->apply_precision = 1;
	}
	return (format);
}

char	*length_modifier(char *format, t_length_modifier *lm)
{
	while (ft_strchr("hljzL", *format))
	{
		if (*format == 'h')
		{
			lm->sshort = 1;
			if (*(format + 1) == 'h' && (lm->sshort = 2))
				++format;
		}
		if (*format == 'l')
		{
			lm->llong = 1;
			if (*(format + 1) == 'l' && (lm->llong = 2))
				++format;
		}
		if (*format == 'L')
			lm->llong = 2;
		if (*format == 'j')
			lm->intmax = 1;
		if (*format == 'z')
			lm->sizet = 1;
		++format;
	}
	return (format);
}

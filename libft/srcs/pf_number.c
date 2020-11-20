/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cotis <cotis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 01:56:36 by cotis             #+#    #+#             */
/*   Updated: 2020/06/02 01:56:36 by cotis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_putnb(va_list ap, t_printf *p)
{
	char		*s;
	intmax_t	n;
	int			sp_padding;

	if (p->lm.llong)
		n = (p->lm.llong >> 1) ? ((intmax_t)va_arg(ap, long long)) :
			((intmax_t)va_arg(ap, long));
	else if (p->lm.sshort)
		n = (p->lm.sshort >> 1) ? (intmax_t)((char)va_arg(ap, int)) :
			(intmax_t)((short)va_arg(ap, int));
	else if (p->lm.intmax)
		n = (va_arg(ap, intmax_t));
	else if (p->lm.sizet)
		n = ((intmax_t)va_arg(ap, ssize_t));
	else
		n = ((intmax_t)va_arg(ap, int));
	(p->flags.zero) ? p->precision = p->min_length : 0;
	s = itoa_printf(n, p);
	sp_padding = (p->printed > p->min_length) ? 0 : p->min_length - p->printed;
	(!p->flags.zero && !p->flags.min) ? ft_putnchar(sp_padding, ' ') : 0;
	ft_putstr_free(s);
	p->flags.min ? ft_putnchar(sp_padding, ' ') : 0;
	p->len += MAX(p->printed, p->min_length);
}

void	pf_putnb_base(int base, va_list ap, t_printf *p)
{
	char		*s;
	uintmax_t	n;
	int			sp_padding;

	if (p->lm.llong)
		n = (p->lm.llong >> 1) ? ((intmax_t)va_arg(ap, unsigned long long)) :
			((intmax_t)va_arg(ap, unsigned long));
	else if (p->lm.sshort)
		n = (p->lm.sshort >> 1) ? (uintmax_t)((unsigned char)va_arg(ap, int)) :
			(uintmax_t)((unsigned short)va_arg(ap, int));
	else if (p->lm.intmax)
		n = (va_arg(ap, uintmax_t));
	else if (p->lm.sizet)
		n = ((uintmax_t)va_arg(ap, size_t));
	else
		n = (uintmax_t)va_arg(ap, unsigned int);
	s = itoa_base_printf(n, base, p);
	sp_padding = MAX(0, (p->min_length - p->printed));
	(!p->flags.zero && !p->flags.min) ? ft_putnchar(sp_padding, ' ') : 0;
	ft_putstr_free(s);
	p->flags.min ? ft_putnchar(sp_padding, ' ') : 0;
	p->len += MAX(p->printed, p->min_length);
}

char	*itoa_printf(intmax_t n, t_printf *p)
{
	char		*s;
	int			len;
	uintmax_t	tmp;

	len = 0;
	tmp = ABS(n);
	while (tmp)
	{
		tmp /= 10;
		++len;
	}
	if ((n < 0 || p->flags.plus || p->flags.sp) && p->flags.zero)
		--p->precision;
	p->printed = MAX(len, p->precision);
	if (n < 0 || p->flags.plus || p->flags.sp)
		++p->printed;
	if (!(s = (char*)malloc(sizeof(char) * (p->printed + 1))))
		return (NULL);
	tmp = ABS(n);
	itoa_base_fill(tmp, 10, s, p);
	(p->flags.sp) ? s[0] = ' ' : 0;
	(n < 0) ? s[0] = '-' : 0;
	(p->flags.plus && n >= 0) ? s[0] = '+' : 0;
	return (s);
}

char	*itoa_base_printf(uintmax_t n, int b, t_printf *p)
{
	uintmax_t	tmp;
	char		*s;
	int			len;
	int			ext;

	len = 0;
	tmp = n;
	while (tmp)
	{
		tmp /= b;
		++len;
	}
	if (p->flags.zero)
		p->precision = p->min_length;
	ext = (len >= p->precision) ? 0 : 1;
	p->printed = MAX(p->precision, len);
	(p->flags.sharp && b == 8 && !ext) ? p->printed += 1 : 0;
	(p->flags.sharp && b == 16 && n && !p->flags.zero) ? p->printed += 2 : 0;
	if (!(s = (char*)malloc(sizeof(char) * (p->printed + 1))))
		return (NULL);
	itoa_base_fill(n, b, s, p);
	(p->flags.sharp && ((b == 8 && !ext) || (b == 16 && n))) ? s[0] = '0' : 0;
	(p->flags.sharp && b == 16 && n) ? s[1] = 'x' - p->cs.upcase * 32 : 0;
	return (s);
}

void	itoa_base_fill(uintmax_t tmp, int b, char *s, t_printf *p)
{
	int		letter;
	int		len;

	len = p->printed;
	letter = 'a' - 10 - (p->cs.upcase * 32);
	s[len] = '\0';
	while (len--)
	{
		s[len] = tmp % b + ((tmp % b < 10) ? '0' : letter);
		tmp /= b;
	}
	(p->apply_precision && p->flags.zero) ? s[0] = ' ' : 0;
}

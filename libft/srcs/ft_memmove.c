/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cotis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 18:35:18 by cotis             #+#    #+#             */
/*   Updated: 2019/09/26 18:46:02 by cotis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	if (str1 == NULL && str2 == NULL)
		return (NULL);
	i = 0;
	s1 = (unsigned char*)str1;
	s2 = (unsigned char*)str2;
	if (s2 < s1)
		while (++i <= n)
			s1[n - i] = s2[n - i];
	else
		while (n-- > 0)
			*(s1++) = *(s2++);
	return (str1);
}

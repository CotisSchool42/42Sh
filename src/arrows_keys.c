#include "sh.h"

void	*ft_realloc(void *ptr, size_t newsize)
{
	char	*newptr;
	size_t	cursize;

	if (ptr == 0)
		return (malloc(newsize));
	cursize = sizeof(ptr);
	if (newsize <= cursize)
		return (ptr);
	newptr = malloc(newsize);
	ft_memcpy(ptr, newptr, cursize);
	free(ptr);
	return (newptr);
}

int		left_key(long c)
{
	(void)c;
	tputs(tgetstr("le", NULL), 1, ft_printnbr);
	return (0);
}

int		right_key(long c)
{
	(void)c;
	tputs(tgetstr("nd", NULL), 1, ft_printnbr);
	return (0);
}

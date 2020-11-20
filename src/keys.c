#include "sh.h"

int		esc_key(long c)
{
	(void)c;
	set_term_canon();
	exit(0);
}
int		spc_key(long c)
{
	(void)c;
	return (0);
}

/*
struct s_node		*k_actions(long c)
{

}*/

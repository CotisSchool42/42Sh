#include "sh.h"

static void	suspend_signal_handler(void)
{
	set_term_canon();
	signal(SIGTSTP, SIG_DFL);
	ioctl(STDERR_FILENO, TIOCSTI, "\x1A");
}

void		init_signal_handlers(void)
{
	signal(SIGABRT, signal_handler);
	signal(SIGINT, signal_handler);
	signal(SIGSTOP, signal_handler);
	signal(SIGCONT, signal_handler);
	signal(SIGTSTP, signal_handler);
	signal(SIGKILL, signal_handler);
	signal(SIGQUIT, signal_handler);
}

static void			kill_signal(void)
{
	set_term_canon();
	signal(SIGKILL, SIG_DFL);
	exit(0);
}

static void 		stop_signal_handler(void)
{
	set_term_canon();
	signal(SIGABRT, SIG_DFL);
	exit(0);
	ioctl(STDERR_FILENO, TIOCSTI, "\x1A");
}

void		signal_handler(int signo)
{
	if (signo == SIGTSTP)
		suspend_signal_handler();
	else if (signo == SIGINT || signo == SIGABRT || signo == SIGQUIT)
		stop_signal_handler();
	else if (signo == SIGCONT)
	{
		set_term_non_canon();
		init_signal_handlers();
	}
	else if (signo == SIGKILL)
	{
		kill_signal();
	}
}

int     main(int argc, char **argv, char **env)
{
    termtype();
	get_term_conf();
	set_term_non_canon();
	init_signal_handlers();
    read_line();
	set_term_canon();
	(void)argc;
	(void)argv;
	(void)env;
    return (0);
}
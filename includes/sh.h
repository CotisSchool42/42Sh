#ifndef SH_H
# define SH_H
# include "../libft/includes/libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <stdio.h>
# include <termios.h>
# include <stdlib.h>
# include <termcap.h>
# include <string.h>
# include <math.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <sys/ioctl.h>
# include <stdarg.h>
# include <signal.h>
# define CHAR_RETURN			10
# define ESC_KEY				27
# define SPC_KEY				32
# define STAR_KEY				42
# define MINUS_KEY				45
# define O_KEY					111
# define B_KEY					98
# define  BSP_KEY				127
# define LEFT_KEY				4479771
# define UP_KEY					4283163
# define RIGHT_KEY				4414235
# define DOWN_KEY				4348699
# define DEL_KEY				0x7E335B1B

typedef struct termios	t_term;
void		clean_window(void);
int			ft_printnbr(int nbr);
void		set_term_type(int term_type);
void		get_term_conf(void);
void		set_term_non_canon(void);
void		set_term_canon(void);
void		termtype(void);
char		key_process(long c);
int			win_size(void);
int			read_line(void);

/* Struct of read */

typedef struct			s_node
{
	struct s_node	*next;
	struct s_node	*back;
	char 			data;
//	char			**argv;
//	int				fd;
//	int				argc;
//	int				num;
}						t_node;

/* Functions of read struct */

struct		s_node				*init();
struct	s_node					*addelem(t_node *list, t_node *root);
struct		s_node				*deletelem(t_node *list);
struct		s_node				*deletehead(t_node *root);
struct	s_node					*k_move(t_node *list, t_node *root, long c);
struct	s_node				*endpoint(t_node *list, t_node *root);

/* Old && New!!! Term cap settings */
t_term		g_newsettings;
t_term		g_oldsettings;


/* Keys */
int			left_key(long c);
int			right_key(long c);
int			esc_key(long c);
int			spc_key(long c);
struct s_node		*k_delete(t_node *list, t_node *root, char *buffer);
int			ret_key(long c);

/* NEW FUNC!!! */
void		*ft_realloc(void *ptr, size_t newsize);
void		print_line(char *buf);

/* signal.h */
void		signal_handler(int signo);
void		init_signal_handlers(void);
void		print_list(t_node *root);

/* Read line */
char 	char_read_line(long c);
long 	long_read_line(void);






struct s_node 	*escape(t_node *list,  t_node *root, long c);

#endif

/*
 *
** Struct termios in header termios.h have some members
** struct termios {
**       tcflag_t        c_iflag;         input flags
**       tcflag_t        c_oflag;         output flags
**       tcflag_t        c_cflag;         control flags
**       tcflag_t        c_lflag;         local flags
**       cc_t            c_cc[NCCS];      control chars
**       speed_t         c_ispeed;        input speed
**       speed_t         c_ospeed;        output speed
** };
**  The termios functions describe a general terminal interface that is
**	provided to control asynchronous communications ports.
**
**	<< - оператор побитового сдвига. сдвигает биты на 2 влево у числа 1.
**	(1 << 2) == 4.
**	~ - побитовое НЕ. грубоговоря - инвертирует биты.
**	| - это побитовое ИЛИ
**	& - это побитовое И
**
** 2^0 = 0x1
** 2^1 = 0x2
** 2^2 = 0x4
** 2^3 = 0x8
** 2^4 = 0x10
** 2^5 = 0x20
** 2^6 = 0x40
** 2^7 = 0x80
** 2^8 = 0x100
*/


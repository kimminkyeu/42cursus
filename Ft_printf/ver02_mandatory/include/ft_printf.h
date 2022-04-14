#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include "libft.h"

/*-------------------------------------------------
 | add description |
 -------------------------------------------------*/

#define PRINTF_NORMAL		(0)
#define PRINTF_FLAG			(1)
#define PRINTF_WIDTH		(2)
#define PRINTF_PRECISION	(3)
#define PRINTF_LENGTH		(4)
#define PRINTF_SPEC			(5)
#define PRINTF_DONE			(6)
#define PRINTF_ERROR		(7)

#define STDOUT				(1)

/*-------------------------------------------------
 | add description |
 -------------------------------------------------*/

typedef struct s_print {

	/* TODO : WHAT IF RETURN VALUE IS LARGER THEN SIZE_T? */
	size_t	print_cnt;
	int		state;

	/* Add every parsed data here...  */

}	t_print;


/*-------------------------------------------------
 | add description |
 -------------------------------------------------*/

extern int		ft_printf(const char *fmt, ...);

extern void		parse_format(const char **fmt, va_list argp, t_print *INFO);

/* functions for t_print (INFO) */
extern t_print*	init_info_malloc();

extern void		reset_state(t_print *INFO);

/* print string until specifier appears. Returns length of printed characters */
extern size_t	print_string_until(const char *str, char stopper, t_print *INFO);


/*-------------------------------------------------
 | add description |
 -------------------------------------------------*/

void	handle_flag(const char *fmt, va_list argp, t_print *INFO);

void	handle_precision(const char *fmt, va_list argp, t_print *INFO);

void	handle_width(const char *fmt, va_list argp, t_print *INFO);

void	handle_length(const char *fmt, va_list argp, t_print *INFO);

void	handle_specifier(const char *fmt, va_list argp, t_print *INFO);


/*-------------------------------------------------
 | Hex functions |
 -------------------------------------------------*/

/* Print nb to full 16 characters of hex.
 * if mode is 0, hex is Lowercase. else, hex is Uppercase */
void	print_to_hex_16(size_t nb, int mode);

/* Print nb to hex, return length of printed characters.
 * if mode is 0, hex is Lowercase. else, hex is Uppercase */
size_t	print_to_hex_fit(size_t nb, int mode);



















#endif

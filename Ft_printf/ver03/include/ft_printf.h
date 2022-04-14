#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include "libft.h"

/*-------------------------------------------------
 |              Constants for state               |
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
 |              INFO State handler                |
 -------------------------------------------------*/
typedef struct s_print {
	/* TODO : WHAT IF RETURN VALUE IS LARGER THEN SIZE_T? */
	size_t	print_cnt;
	int		state;
	/* Add every parsed data here...  */
}	t_print; 

extern t_print*	init_info_malloc();
extern void		reset_state(t_print *INFO);

/*-------------------------------------------------
 |				Main Function                     |
 -------------------------------------------------*/
extern int		ft_printf(const char *fmt, ...);

/*-------------------------------------------------
 |				Internal Function				  |
 -------------------------------------------------*/
extern int		ft_vprintf(const char *fmt, va_list argp);
/* print string until specifier appears. Returns length of printed characters */
extern size_t	ft_putstr_until(const char *str, char stopper, t_print *INFO);

/*-------------------------------------------------
 |				Parser Function                   |
 -------------------------------------------------*/
extern void		parse_format(const char **fmt, va_list argp, t_print *INFO);

/*-------------------------------------------------
 |              Flag handler functiom             |
 -------------------------------------------------*/
extern void		handle_flag(const char *fmt, va_list argp, t_print *INFO);

extern void		handle_precision(const char *fmt, va_list argp, t_print *INFO);

extern void		handle_width(const char *fmt, va_list argp, t_print *INFO);

extern void		handle_length(const char *fmt, va_list argp, t_print *INFO);

extern void		handle_specifier(const char *fmt, va_list argp, t_print *INFO);

/*-------------------------------------------------
 |				Specifier handler function        |
 -------------------------------------------------*/
extern void		handle_spec_char(va_list argp, t_print *INFO);

extern void		handle_spec_percent(va_list argp, t_print *INFO);

extern void		handle_spec_str(va_list argp, t_print *INFO);

extern void		handle_spec_addr(va_list argp, t_print *INFO);

extern void		handle_spec_int(va_list argp, t_print *INFO);

extern void		handle_spec_uint(va_list argp, t_print *INFO);

extern void		handle_spec_lower_hex(va_list argp, t_print *INFO);

extern void		handle_spec_upper_hex(va_list argp, t_print *INFO);

extern int		get_spec_func_idx(const char *fmt);

extern void		set_spec_func_table(void (*spec_func_table[])(va_list, t_print *));

/*-------------------------------------------------
 |               Hex functions                    |
 -------------------------------------------------*/

/* Print nb to full 16 characters of hex.
 * if mode is 0, hex is Lowercase. else, hex is Uppercase */
extern void		print_to_hex_16(size_t nb, int mode);

/* Print nb to hex, return length of printed characters.
 * if mode is 0, hex is Lowercase. else, hex is Uppercase */
extern size_t	print_to_hex_fit(size_t nb, int mode);

/* Print nb to n characters of hex.
 * if mode is 0, hex is Lowercase. else, hex is Uppercase */
extern size_t	print_to_hex_len(size_t nb, size_t n, int mode);

#endif

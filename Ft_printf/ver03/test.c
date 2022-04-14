#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include "include/libft.h"
#include "include/ft_printf.h"

int main(void)
{

	int a;
	/** a = ft_printf("hello, world!\t\t"); */
	/** ft_putnbr_fd(a, STDOUT); */
	/** printf("  answer --> %s\n", "hello, world!"); */

	/** ft_printf("\n"); */

	/** a = ft_printf("%%c : %c\t\t\t", 'A'); */
	/** ft_putnbr_fd(a, STDOUT); */
	/** printf("  answer --> %c\n", 'A'); */

	/** ft_printf("\n"); */

	/** a = ft_printf("%%%% : %%\t\t\t"); */
	/** ft_putnbr_fd(a, STDOUT); */
	/** printf("  answer --> %%\n"); */
	/** ft_printf("\n"); */

	a = ft_printf("%%s : %s\t\t", "kyeu");
	ft_putnbr_fd(a, STDOUT);
	printf("  answer --> %s\n", "kyeu");

	ft_printf("\n");
    /**  */

	/** int num = -1; */
	/** a = ft_printf("%%p : %p\t", &num); */
	/** ft_putnbr_fd(a, STDOUT); */
	/** printf("  answer --> %p\n", &num); */
    /**  */
	/** ft_printf("\n"); */
    /**  */
	/** a = ft_printf("%d", INT_MIN); */
	/** ft_printf("\n"); */
	/** ft_putnbr_fd(a, STDOUT); */
	/** ft_printf("\n"); */
	/** int b = printf("%d", INT_MIN); */
	/** printf("\n"); */
	/** printf("%d\n", b); */
	/** ft_printf("\n"); */
    /**  */
	/** a = ft_printf("%%i : %i\t\t\t", num); */
	/** ft_putnbr_fd(a, STDOUT); */
	/** printf("  answer --> %i\n", num); */
    /**  */
	/** ft_printf("\n"); */
    /**  */
	/** a = ft_printf("%%u : %u\t\t", -1); */
	/** ft_putnbr_fd(a, STDOUT); */
	/** printf("  answer --> %u\n", -1); */
    /**  */
	/** ft_printf("\n"); */
    /**  */
	/** a = ft_printf("%x", -1); */
	/** ft_printf("\n"); */
	/** ft_putnbr_fd(a, STDOUT); */
	/** ft_printf("\n"); */
	/** int b = printf("%x", -1); */
	/** printf("\n"); */
	/** ft_printf("%d", b); */
	/** printf("\n"); */
    /**  */
	/** ft_printf("\n"); */
    /**  */
	/** a = ft_printf("%%X : %X\t\t", 12345678); */
	/** ft_putnbr_fd(a, STDOUT); */
	/** printf("  answer --> %X\n", 12345678); */
    /**  */
	/** ft_printf("\n"); */
}

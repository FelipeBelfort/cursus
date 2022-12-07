#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#define TESTE "0 %u", LONG_MIN
// #define TESTE " int_max %u int_min %u long_max %u long_min %u ulong_max %u 0 %u -42 %u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42


int	main()
{
	int minha;
	int original;

	printf("\n");
	minha = ft_printf(TESTE);
	printf("\n");
	original = printf(TESTE);
	printf("\n");
	printf("ft_printf --> %d\nprintf --> %d", minha, original);
	printf("\n");
	return 1;
}
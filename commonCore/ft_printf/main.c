#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#define TESTE "%"
// #define TESTE "int_max %u int_min %u long_max %u long_min %u %                  y ulong_max %u 0 %u -42 %u%", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42


int	main()
{
	// int minha;
	// int original;

	// printf("\n");
	// minha = ft_printf(TESTE);
	ft_printf("-->%i\n", ft_printf(TESTE));
	printf("-->%i\n", printf(TESTE));
	// printf("\n");
	// original = printf(TESTE);
	// printf("\nft_printf --> %i\nprintf --> %i", minha, original);
	// printf("\n");
	return 1;
}
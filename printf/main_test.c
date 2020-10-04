#include "ft_printf.h"
#include <stdio.h>

int main()
{
	printf("pf : %+x\n", -42);
	printf("pf : %+X\n", -42);
	printf("pf : %+12p\n", (void*)-42);
	ft_printf("ft : %+x\n", -42);
	ft_printf("ft : %+X\n", -42);
	ft_printf("ft : %+12p\n", (void*)-42);
}

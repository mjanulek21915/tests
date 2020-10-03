#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int rst_test;
	int rst_ref;
	char str[110]="cesi";
	printf("pf : %.5d\n", -2372);
	ft_printf("ft : %.5d\n", -2372);
}

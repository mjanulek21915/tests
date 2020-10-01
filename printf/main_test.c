#include <stdio.h>

int main()
{
	int rst_test;
	int rst_ref;
	char str[110]="cesi";
	printf("test\n");
	rst_test = ft_printf("|%012s|", "cesi");
	printf("\n");
	rst_ref = printf("|%-12.1p|", 42);
	printf("\n");

	printf("rst_test = %d\n", rst_test);
	printf("rst_ref = %d\n", rst_ref);
}
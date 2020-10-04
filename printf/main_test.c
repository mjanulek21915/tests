#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int rst_test;
	int rst_ref;
	char str[110]="cesi";
    ftprintf("ret = %d\n", printf("%%pf p:1:[%010d]\n", -8473));
    printf("ret = %d\n", printf("%%ft p:2:[%10d]\n", -8473));
}

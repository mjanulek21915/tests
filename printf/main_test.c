#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int rst_test;
	int rst_ref;
	char str[110]="cesi";
    printf("ret = %d\n", printf("%%pf:1:[%010d]\n", -8473));
    printf("ret = %d\n", ft_printf("%%ft:2:[%010d]\n", -8473));
	printf("ret = %d\n", printf("%%pf:1:[%10d]\n", -8473));
    printf("ret = %d\n", ft_printf("%%ft:2:[%10d]\n", -8473));
	printf("pf: .5d: %.5d\n", -2372);
	ft_printf("ft: .5d: %.5d\n", -2372);
    printf("ret = %d\n", printf("pf : %.5d :[%.5d]\n", -8473));
    printf("ret = %d\n", ft_printf("ft : %.5d :[%.5d]\n", -8473));

}

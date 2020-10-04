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
    printf("ret = %d\n", printf("pf : .5d :[%.5d]\n", -8473));
    printf("ret = %d\n", ft_printf("ft : .5d :[%.5d]\n", -8473));
	printf("%d\n", printf("pf : chiffre 1 %012d chiffre 2 %012d\n", 42, -42));
	printf("%d\n", ft_printf("ft : chiffre 1 %012d chiffre 2 %012d\n", 42, -42));
	printf("ret = %d\n", printf("pf : 01.50d:[%01.50d]\n", -8473));
	printf("ret = %d\n", ft_printf("ft : 01.50d:[%01.50d]\n", -8473));
    printf("ret = %d\n", printf("pf : 1.50d:[%1.50d]\n", -8473));
    printf("ret = %d\n", ft_printf("ft : 1.50d:[%1.50d]\n", -8473));
}

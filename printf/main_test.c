#include <stdio.h>
#include <wchar.h>
#include "ft_printf/ft_printf.h"
#include <limits.h>

int get_len(char *path)
{
	int rst = 0;
	int buff_size = 10000;
	int temp_int = buff_size;
	char temp_char[100000];
	int fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		fprintf(stderr, "fd error\n");
		exit(0);
	}
	while ((temp_int == buff_size))
	{
		temp_int = read(fd, temp_char, buff_size);
		rst = rst + temp_int;
	}
	close(fd);
	return (rst);
}

char * ft_open(char *path)
{
	char *rst;
	int fd = open(path, O_RDONLY);
	int size = get_len(path);
	fprintf(stderr, "size = %d\n", size);
	rst = malloc(sizeof(char) * (size + 1));
	read(fd, rst, size);
	rst[size] = 0;
	close(fd);
	return (rst);
}

int main()
{
	// char str2[100] = "aaa";
	// char *str;
	// str = ft_open("aaa");

	// long long pf = 0;
	// long long ft = 0;
	// printf(fmt, str, &pf);
	// ft_printf(fmt, str, &ft);
	// printf("pf : %llu\nft : %llu\n", pf, ft);
	// free(str);
	// printf("%d\n", ft_printf("aaaa"));



	char fmt[100] = "%#8.12X\n";
	printf(fmt, 42);
	ft_printf(fmt, 42);



// long long i = -10-256-(256 * 16);
// printf("%u\n", (int)i);
// ft_printf("%u\n", (int)i);
// printf("\n");
// printf("%lu\n", (unsigned long)i);
// ft_printf("%lu\n", (unsigned long)i);
// printf("\n");
// printf("%llu\n", (unsigned long long)i);
// ft_printf("%llu\n", (unsigned long long)i);
// printf("\n");
// printf("%hu\n", (short)i);
// ft_printf("%hu\n", (short)i);
// printf("\n");
// printf("%hhu\n", (char)i);
// ft_printf("%hhu\n", (char)i);
// printf("\n");



// int a = 2;
// printf("%d\n", (a == 1 ? 1 : 0));



	// int i = -10;
	// long long l;
	// l = ~i + 1;
	// printf("%lld\n", l);
// 	wchar_t str[100] = {'a', 'a', 'a', 0};
// 	printf("%ls\n", str);
// 	char happy[] = { 0ie2, 0i98, 0iba };  /* U+263A */
//    write(1, happy, 3);
}

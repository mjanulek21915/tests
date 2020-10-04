#include "ft_printf.h"
#include "stdio.h"

void nullify(char *a, char *b, char n_char)
{
	int i = 100;
	while (i--)
		*(b + i) = 0;
	while (*a)
	{
		if (*a != n_char)
			*b++ = *a;
		a++;
	}
	*b = 0;

}

void init_list(char *fmt, void **list, void **types, char *padding)
{
	int i = 24;
	while (i--)
		list[i] = (void *)padding;
	i = 0;
	while (fmt && i < 24)
	{
		if (types[*fmt])
			list[i++] = types[*fmt];
		fmt++;
	}
}

void init_types(void **types)
{
	int i = 128;
	while (i--)
		types[i] = 0;
}

int main(int ac, char **av)
{

	char *orig = av[2];
	char n_char = av[3][0];
	int iteration;
	char padding[100] = "wronk strink";
	void *arg_list[24];

	char fmt[100];
	char *temp = (char*)fmt;
	void *arg_types[128];

	char c = 'a';
	char s[100] = "cesi";
	void *p = (void *)-42;
	int d = -42;
	int i = d;
	int u = -42;
	int x = u;
	int X = u;

	init_types(arg_types); 
	arg_types['c'] = (void *)c;
	arg_types['s'] = (void *)s;
	arg_types['p'] = p;
	arg_types['d'] = (void *)d;
	arg_types['i'] = (void *)i;
	arg_types['u'] = (void *)u;
	arg_types['x'] = (void *)x;
	arg_types['X'] = (void *)X;
	arg_types['*'] = (void *)12;

	nullify(av[1], fmt, n_char);
	init_list(fmt, arg_list, arg_types, padding);

	int (*pf) (void *, ...);
	int rst;

	if (*orig == '1')
		pf = &printf;
	else
		pf = &ft_printf;

	rst = pf(fmt, arg_list[0], arg_list[1], arg_list[2], arg_list[3], arg_list[4], arg_list[5],
	arg_list[6], arg_list[7], arg_list[8], arg_list[9], arg_list[10], arg_list[11],
	arg_list[12], arg_list[13], arg_list[14], arg_list[15], arg_list[16], arg_list[17],
	arg_list[18], arg_list[19], arg_list[20], arg_list[21], arg_list[22], arg_list[23]);
	printf("\nrst = %d\n", rst);
}
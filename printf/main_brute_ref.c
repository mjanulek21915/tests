#include "ft_printf.h"
#include "stdio.h"

int mini_atoi(char *str)
{
	int rst = 0;
	int sign = 1;

	if (!*str || !str)
		return (0);
	if (*str == '.')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		rst = rst * 10;
		rst = rst + *str - '0';
		str++;
	}
	return rst * sign;
}

void nullify(char *a, char *b, char n_char)
{
	while (*a)
	{
		if (*a != n_char)
			*b++ = *a;
		a++;
	}
	*b = 0;

}

int main(int ac, char **av)
{
	char *width = av[2];
	char *prec = av[3];
	char *conv = av[4];
	char *orig = av[5];
	char n_char = av[6][0];
	int numbers[2] = {0, 0};
	int n = 7;
	int m = 0;

	char fmt[100];
	int z = 100;

	int num = 0;


	void *list[128];
	char c = 'a';
	list['c'] = (void *)c;
	char s[100] = "cesi";
	list['s'] = (void *)s;
	void *p = (void *)num;
	list['p'] = num;
	int d = num;
	list['d'] = (void *)d;
	int i = d;
	list['i'] = (void *)i;
	int u = num;
	list['u'] = (void *)u;
	int x = u;
	list['x'] = (void *)x;
	int X = u;
	list['X'] = (void *)X;
	
	int count = 0;

	int rst;

	int (*pf) (void *, ...);


	if (*width == '*')
		numbers[count++] = mini_atoi(av[n++]);
	if (*(prec + 1) == '*')
		numbers[count++] = mini_atoi(av[n]);
	while (z--)
		fmt[z] = 0;

	nullify(av[1], fmt, n_char);

// fprintf(stderr, "main ref fmt : |%s|\n", fmt);
// fprintf(stderr, "main ref nchar : |%c|\n", n_char);
// fprintf(stderr, "main ref count : %d\n", count);

	if (*orig == '1')
		pf = &printf;
	else
		pf = &ft_printf;

	if (count == 0)
		rst = pf(fmt, list[*conv]);
	else if (count == 1)
		rst = pf(fmt, numbers[0], list[*conv]);
	else
		rst = pf(fmt, numbers[0], numbers[1], list[*conv]);
	printf("\nrst = %d\n", rst);
}
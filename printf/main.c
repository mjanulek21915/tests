#include <stdio.h>
#include "ft_printf.h"

int main()
{
	int status;
	int reference;
	char c = 'a';
	char s[100] = "cesi";
	void *p = (void *)1250;
	int d = -42;
	int i = -42;
	unsigned int u = 42;
	int x = 42;
	int X = 42;

//	int (*ft_printf)(const char * restrict, ...) = &printf;


	status = ft_printf("c = |%c| - t\n", c);
	reference = printf("c = |%c| - r\n", c);
	if (status != reference)
		printf("diff status: test = %d, reference = %d\n", status, reference);
	printf("\n");
	status = ft_printf("s = |%s| - t\n", s);
	reference = printf("s = |%s| - r\n", s);
	if (status != reference)
		printf("diff status: test = %d, reference = %d\n", status, reference);
	printf("\n");
	status = ft_printf("p = |%p| - t\n", p);
	reference = printf("p = |%p| - r\n", p);
	if (status != reference)
		printf("diff status: test = %d, reference = %d\n", status, reference);
	printf("\n");
	status = ft_printf("d = |%d| - t\n", d);
	reference = printf("d = |%d| - r\n", d);
	if (status != reference)
		printf("diff status: test = %d, reference = %d\n", status, reference);
	printf("\n");
	status = ft_printf("i = |%i| - t\n", i);
	reference = printf("i = |%i| - r\n", i);
	if (status != reference)
		printf("diff status: test = %d, reference = %d\n", status, reference);
	printf("\n");
	status = ft_printf("u = |%u| - t\n", u);
	reference = printf("u = |%u| - r\n", u);
	if (status != reference)
		printf("diff status: test = %d, reference = %d\n", status, reference);
	printf("\n");
	status = ft_printf("x = |%x| - t\n", x);
	reference = printf("x = |%x| - r\n", x);
	if (status != reference)
		printf("diff status: test = %d, reference = %d\n", status, reference);
	printf("\n");
	status = ft_printf("X = |%x| - t\n", X);
	reference = printf("X = |%x| - r\n", X);


	status = ft_printf("4s = |%4s| - t\n", s);
	reference = printf("4s = |%4s| - r\n", s);
	if (status != reference)
		printf("diff status: test = %d, reference = %d\n", status, reference);
	printf("\n");
	status = ft_printf("5s = |%5s| - t\n", s);
	reference = printf("5s = |%5s| - r\n", s);
	if (status != reference)
		printf("diff status: test = %d, reference = %d\n", status, reference);
	printf("\n");
	status = ft_printf("6s = |%6s| - t\n", s);
	reference = printf("6s = |%6s| - r\n", s);
	if (status != reference)
		printf("diff status: test = %d, reference = %d\n", status, reference);
	printf("\n");

	status = ft_printf("-4s = |%-4s| - t\n", s);
	reference = printf("-4s = |%-4s| - r\n", s);
	if (status != reference)
		printf("diff status: test = %d, reference = %d\n", status, reference);
	printf("\n");
	status = ft_printf("-5s = |%-5s| - t\n", s);
	reference = printf("-5s = |%-5s| - r\n", s);
	if (status != reference)
		printf("diff status: test = %d, reference = %d\n", status, reference);
	printf("\n");
	status = ft_printf("-6s = |%-6s| - t\n", s);
	reference = printf("-6s = |%-6s| - r\n", s);
	if (status != reference)
		printf("diff status: test = %d, reference = %d\n", status, reference);
	printf("\n");

	status = ft_printf("04s = |%04s| - t\n", s);
	reference = printf("04s = |%04s| - r\n", s);
	if (status != reference)
		printf("diff status: test = %d, reference = %d\n", status, reference);
	printf("\n");
	status = ft_printf("05s = |%05s| - t\n", s);
	reference = printf("05s = |%05s| - r\n", s);
	if (status != reference)
		printf("diff status: test = %d, reference = %d\n", status, reference);
	printf("\n");
	status = ft_printf("06s = |%06s| - t\n", s);
	reference = printf("06s = |%06s| - r\n", s);
	if (status != reference)
		printf("diff status: test = %d, reference = %d\n", status, reference);
	printf("\n");

		status = ft_printf(".4s = |%.4s| - t\n", s);
	reference = printf(".4s = |%.4s| - r\n", s);
	if (status != reference)
		printf("diff status: test = %d, reference = %d\n", status, reference);
	printf("\n");
		status = ft_printf(".5s = |%.5s| - t\n", s);
	reference = printf(".5s = |%.5s| - r\n", s);
	if (status != reference)
		printf("diff status: test = %d, reference = %d\n", status, reference);
	printf("\n");
		status = ft_printf(".6s = |%.6s| - t\n", s);
	reference = printf(".6s = |%.6s| - r\n", s);
	if (status != reference)
		printf("diff status: test = %d, reference = %d\n", status, reference);
	printf("\n");




		status = ft_printf("*4s = |%*s| - t\n", 4, s);
	reference = printf("*4s = |%*s| - r\n", 4, s);
	if (status != reference)
		printf("diff status: test = %d, reference = %d\n", status, reference);
	printf("\n");
		status = ft_printf("*5s = |%*s| - t\n", 5, s);
	reference = printf("*5s = |%*s| - r\n", 5, s);
	if (status != reference)
		printf("diff status: test = %d, reference = %d\n", status, reference);
	printf("\n");
		status = ft_printf("*6s = |%*s| - t\n", 6, s);
	reference = printf("*6s = |%*s| - r\n", 6, s);
	if (status != reference)
		printf("diff status: test = %d, reference = %d\n", status, reference);
	printf("\n");
			status = ft_printf("*6s = |%*s| - t\n", -6, s);
	reference = printf("*6s = |%*s| - r\n", -6, s);
	if (status != reference)
		printf("diff status: test = %d, reference = %d\n", status, reference);
	printf("\n");

		status = ft_printf(".*4s = |%.*s| - t\n", 4, s);
	reference = printf(".*4s = |%.*s| - r\n", 4, s);
	if (status != reference)
		printf("diff status: test = %d, reference = %d\n", status, reference);
	printf("\n");
		status = ft_printf(".*5s = |%.*s| - t\n", 5, s);
	reference = printf(".*5s = |%.*s| - r\n", 5, s);
	if (status != reference)
		printf("diff status: test = %d, reference = %d\n", status, reference);
	printf("\n");
		status = ft_printf(".*6s = |%.*s| - t\n", 6, s);
	reference = printf(".*6s = |%.*s| - r\n", 6, s);
	if (status != reference)
		printf("diff status: test = %d, reference = %d\n", status, reference);
	printf("\n");
	status = ft_printf(".*6s = |%.*s| - t\n", -6, s);
	reference = printf(".*6s = |%.*s| - r\n", -6, s);
	if (status != reference)
		printf("diff status: test = %d, reference = %d\n", status, reference);
	printf("\n");

}

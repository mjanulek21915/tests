#include "get_next_line.h"
#include "limits.h"

int mini_atoi(char *str)
{
	int rst = 0;

	while (*str)
		rst = (rst * 10) + *str++ - 48;
	return rst;
}

int main(int ac, char **av)
{
	char *line;
	int status = 1;
	int i = 1;

	int max = mini_atoi(av[2]);
	printf("nb iterations = %d\n", max);
	printf("nom de fichier = %s\n", av[1]);
	printf("BUFFER_SIZE = %d\n", BUFFER_SIZE);
	printf("OPEN_MAX = %d\n", OPEN_MAX);

	while (i < ac)
	{
		fprintf(stderr, "av %d :%s\n", i, av[i]);
		i++;
	}
	int fd = open(av[1], O_RDONLY);

	printf("\n");

	i = 0;
	while (i < max)
	{
		if (i == max - 1)
			close(fd);
		status = get_next_line(fd, &line);
		if (status > -1)
			printf("line = %s\n", line);
		else
			printf("erreur fd simulée\n");
		printf("status = %d\n", status);
		printf("\n");
		if (status > -1)
		free (line);
		i++;
	}
}

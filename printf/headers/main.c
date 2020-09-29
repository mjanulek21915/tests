/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjanulek <mjanulek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:50:53 by mjanulek          #+#    #+#             */
/*   Updated: 2020/09/28 14:50:53 by mjanulek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjanulek <mjanulek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:49:32 by mjanulek          #+#    #+#             */
/*   Updated: 2020/09/28 14:49:32 by mjanulek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdarg.h>

static int count(char *path)
{
	int fd;
	int count = 0;
	char temp[1];

	fd = open(path, O_RDONLY);
	while (read(fd, temp, 1))
		count++;
	close(fd);
	return (count);
}

static char *ft_read(char *path, int size)
{
	char *rst;
	int fd = open(path, O_RDONLY);
	if ((fd < 0) || !(rst = malloc(sizeof(char) * (size + 1))))
		fprintf(stderr, "replace read error\n");
	read(fd, rst, size);
	rst[size] = 0;
	close(fd);
	return (rst);
}

void replace(char cue, char *str, char **source)
{
	while (**source != cue && **source)
		(*source)++;
	if (**source)
		while (*str)
			*(*source)++ = *str++;
}

int main(int ac, char **av)
{
	char *file;
	char *header;
	char *path_file = av[1];
	int size_file = count(path_file);
	char *path_header = av[2];
	int size_header = count(path_header);
	char *title = av[3];
	char _title = 'T';
	char *user = av[4];
	char _user = 'U';
	char *date = av[5];
	char _date = 'D';
	int fd;

	char * temp;
	if (ac != 6)
	{
		fprintf(stderr, "lol\n");
		return (0);
	}
	fprintf(stderr, "file size : %d\n", size_file);
	fprintf(stderr, "header size : %d\n", size_header);

	header = ft_read(path_header, size_header);
	temp = header;
	file = ft_read(path_file, size_file);
	replace(_title, title, &header);
	replace(_user, user, &header);
	replace(_date, date, &header);
	replace(_date, date, &header);

	printf("%s\n\n", temp);
	printf("%s\n", file);
}








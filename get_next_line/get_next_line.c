#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 100
#endif

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *stash;
    char *readline;
    char *line;
	char *tempstash;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	if (!stash)
        stash = ft_strdup("");
    readline = ft_readline(fd);
    if (readline)
        stash = ft_strjoin(stash, readline);
    line = ft_getline(&stash);
    if (line)
        return (line);
	tempstash = stash;
	free (stash);
	stash = tempstash;
	free (readline);
	return (get_next_line(fd));
}

int main()
{
	int fd = open("/Users/cheelim/Desktop/test.txt", O_RDWR);
	printf("value = %d\n", fd);
	// char buffer[BUFFER_SIZE];
	// char buffer2[BUFFER_SIZE];
	// int bytesread = read(fd, buffer, BUFFER_SIZE);
	char *buffer = get_next_line(fd);
	printf("string = %s\n", buffer);

	buffer = get_next_line(fd);
	printf("string = %p\n", buffer);

	// buffer = get_next_line(fd);
	// printf("string = %s\n", buffer);

	// buffer = get_next_line(fd);
	// printf("string = %s\n", buffer);
	// printf("bytesread = %d\n", bytesread);

	// int bytesread2 = read(fd, buffer2, BUFFER_SIZE);
	// printf("string = %s\n", buffer2);
	// printf("bytesread = %d\n", bytesread2);
}
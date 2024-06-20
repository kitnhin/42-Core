#include "get_next_line.h"

char	*ft_readfile(int fd, char *stash)
{
	char	*buffer;
	int		bytesread;
	char	*tempstash;

	bytesread = 1;
	while (bytesread > 0)
	{
		buffer = (char* )malloc(sizeof(char) * (BUFFER_SIZE + 1));
		bytesread = read(fd, buffer, BUFFER_SIZE);
		buffer[bytesread] = '\0';
		tempstash = ft_strjoin(stash, buffer);
		free(stash);
		free(buffer);
		stash = tempstash;
	}
	return (stash);
}
char *ft_getline(char *stash)
{
    char *line;
    int len;

    len = 0;
	if (!stash || stash[0] == '\0')
		return (NULL);
    while(stash[len]!= '\n' && stash[len]!= '\0')
        len++;
    if(stash[len] == '\n')
		len++;
	line = ft_substr(stash, 0, len);
    return (line);
}

char *process_stash(char *stash)
{
	char *tempstash;
	int i;

	i = 0;
	if (!stash || stash[0] == '\0')
	{
		free (stash);
		return (NULL);
	}
	while(stash[i] != '\0' && stash[i] != '\n')
		i++;
	if(stash[i] == '\n')
		i++;
	tempstash = ft_substr(stash, i, ft_strlen(stash));
	free(stash);
	return (tempstash);
}

char *get_next_line(int fd)
{
    static char *stash;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	if (!stash)
        stash = ft_strdup("");
	stash = ft_readfile(fd, stash);
    line = ft_getline(stash);
	stash = process_stash(stash);
	return (line);
}

// int main()
// {
// 	int fd = open("/Users/cheelim/Desktop/test.txt", O_RDWR);
// 	printf("value = %d\n", fd);
// 	// char buffer[BUFFER_SIZE];
// 	// char buffer2[BUFFER_SIZE];
// 	// int bytesread = read(fd, buffer, BUFFER_SIZE);
// 	char *buffer = get_next_line(fd);
// 	printf("string = %s\n", buffer);

// 	// buffer = get_next_line(fd);
// 	// printf("string = %p\n", buffer);

// 	buffer = get_next_line(fd);
// 	printf("string = %s\n", buffer);

// 	buffer = get_next_line(fd);
// 	printf("string = %s\n", buffer);


// 	buffer = get_next_line(fd);
// 	printf("string = %s\n", buffer);

// 	buffer = get_next_line(fd);
// 	printf("string = %s\n", buffer);

// 	buffer = get_next_line(fd);
// 	printf("string = %s\n", buffer);
// 	// buffer = get_next_line(fd);
// 	// printf("string = %s\n", buffer);
// 	// printf("bytesread = %d\n", bytesread);

// 	// int bytesread2 = read(fd, buffer2, BUFFER_SIZE);
// 	// printf("string = %s\n", buffer2);
// 	// printf("bytesread = %d\n", bytesread2);
// }
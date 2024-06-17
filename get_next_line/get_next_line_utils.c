#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

#include "get_next_line.h"

size_t	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char *ft_strdup(char *s)
{
	char	*str;
	int		i;
	int		len;

	len = ft_strlen(s);
	i = -1;
	str = (char *)malloc(sizeof(char) * (len + 1));
	while (s[++i] != '\0')
		str[i] = s[i];
	str[i] = '\0';
	return (str);
}
int	total_size(char const *s, unsigned int start, size_t len)
{
	int	size;

	if (!s)
		return (0);
	if (ft_strlen((char *)s) - start < len)
		size = ft_strlen((char *)s) - start;
	else
		size = len;
	return (size);
}
char	*ft_substr(char const *s, size_t start, size_t len)
{
	int		size;
	char	*str;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	size = total_size(s, start, len);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	i = start;
	j = 0;
	while (j < len && s[i] != '\0' && start < ft_strlen((char *)s) && len > 0)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}

char	*ft_readline(int fd)
{
	char	*buffer;
	int		bytesread;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	bytesread = read(fd, buffer, BUFFER_SIZE);
	buffer[bytesread] = '\0';
	return (buffer);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int	i;
	int	j;
	char	*str;

	i = -1;
	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	while(str1[++i] != '\0')
		str[i] = str1[i];
	while(str2[j] != '\0')
	{
		str[i] = str2[j];
		i++;
		j++;
	}
	return (str);
}
char *ft_getline(char **stash)
{
    char *line;
    char *leftover;
    int len;

    len = 0;
    while((*stash)[len]!= '\n' && (*stash)[len]!= '\0')
        len++;

    if((*stash)[len] == '\n')
    {
        line = ft_substr(*stash, 0, len);
        leftover = ft_substr(*stash, len + 1, (ft_strlen(*stash) - (len + 1)));
        free(*stash);
        *stash = leftover;
    }
    else
        return 0;
    return (line);
}

char *get_next_line(int fd)
{
    static char *stash;
    char *readline;
    char *line;


    if (!stash)
        stash = ft_strdup("");
    readline = ft_readline(fd);
    if (readline)
        stash = ft_strjoin(stash, readline);
    line = ft_getline(&stash);
    if (line)
        return (line);
    else
        return (ft_strdup(""));
}

int main()
{
	int fd = open("/Users/cheelim/Desktop/test.txt", O_RDONLY);
	printf("value = %d\n", fd);
	// char buffer[BUFFER_SIZE];
	// char buffer2[BUFFER_SIZE];
	// int bytesread = read(fd, buffer, BUFFER_SIZE);
	char *buffer = get_next_line(fd);
	printf("string = %s\n", buffer);

	buffer = get_next_line(fd);
	printf("string = %s\n", buffer);

	// buffer = get_next_line(fd);
	// printf("string = %s\n", buffer);

	// buffer = get_next_line(fd);
	// printf("string = %s\n", buffer);
	// printf("bytesread = %d\n", bytesread);

	// int bytesread2 = read(fd, buffer2, BUFFER_SIZE);
	// printf("string = %s\n", buffer2);
	// printf("bytesread = %d\n", bytesread2);
}




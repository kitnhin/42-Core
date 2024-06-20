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
	if (!str)
		return (NULL);
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_len;
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	dest = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!dest)
		return (NULL);
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		dest[i++] = s2[j++];
	dest[i] = '\0';
	return (dest);
}

// char	*ft_readline(int fd)
// {
// 	char	*buffer;
// 	int		bytesread;

// 	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	bytesread = read(fd, buffer, BUFFER_SIZE);
// 	if (bytesread <= 0)
// 	{
// 		free(buffer);
// 		return (NULL);
// 	}
// 	buffer[bytesread] = '\0';
// 	return (buffer);
// }

// char *get_next_line(int fd)
// {
//     static char *stash;
//     char *readline;
//     char *line;
// 	char *tempstash;

//     if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	if (!stash)
//         stash = ft_strdup("");
//     readline = ft_readline(fd);
//     if (readline)
//         stash = ft_strjoin(stash, readline);
//     line = ft_getline(&stash);
//     if (line)
//         return (line);
// 	tempstash = stash;
// 	free (stash);
// 	stash = tempstash;
// 	free (readline);
// 	return (get_next_line(fd));
// }
// char *get_next_line(int fd)
// {
//     static char *stash;
//     char *readline;
//     char *line;
// 	char	*newstash;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	if (!stash)
//         stash = ft_strdup("");
// 	readline = ft_readline(fd);
// 	if (readline)
// 		stash = ft_strjoin(stash, readline);
//     if (!readline)
// 	{
// 		line = ft_strdup(stash);
// 		free (stash);
// 		stash = NULL;
// 		if (line)
// 			return (line);
// 		free (line);
// 		line = NULL;
// 		return (NULL);
// 	}
// 	line = ft_getline(&stash);
//     if (line)
//         return (line);
// 	free(readline);
// 	return (0);
// }

// int main()
// {
// 	int fd = open("/Users/cheelim/Desktop/test.txt", O_RDONLY);
// 	printf("value = %d\n", fd);
// 	// char buffer[BUFFER_SIZE];
// 	// char buffer2[BUFFER_SIZE];
// 	// int bytesread = read(fd, buffer, BUFFER_SIZE);
// 	char *buffer = get_next_line(fd);
// 	printf("string = %s\n", buffer);

// 	buffer = get_next_line(fd);
// 	printf("string = %s\n", buffer);

// 	// buffer = get_next_line(fd);
// 	// printf("string = %s\n", buffer);

// 	// buffer = get_next_line(fd);
// 	// printf("string = %s\n", buffer);
// 	// // printf("bytesread = %d\n", bytesread);

// 	// buffer = get_next_line(fd);
// 	// printf("string = %s\n", buffer);

// 	// int bytesread2 = read(fd, buffer2, BUFFER_SIZE);
// 	// printf("string = %s\n", buffer2);
// 	// printf("bytesread = %d\n", bytesread2);
// }




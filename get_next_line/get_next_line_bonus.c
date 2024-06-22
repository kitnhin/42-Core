/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethanlim <ethanlim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 02:31:16 by ethanlim          #+#    #+#             */
/*   Updated: 2024/06/22 02:32:52 by ethanlim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_readfile(int fd, char *stash)
{
	char	*buffer;
	int		bytesread;
	char	*tempstash;

	bytesread = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (bytesread > 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		buffer[bytesread] = '\0';
		tempstash = ft_strjoin(stash, buffer);
		free(stash);
		stash = tempstash;
		if (ft_strchr(buffer, '\n') == 1)
			break ;
	}
	free (buffer);
	buffer = NULL;
	return (stash);
}

char	*ft_getline(char *stash)
{
	char	*line;
	int		len;

	len = 0;
	if (!stash || stash[0] == '\0')
		return (NULL);
	while (stash[len] != '\n' && stash[len] != '\0')
		len++;
	if (stash[len] == '\n')
		len++;
	line = ft_substr(stash, 0, len);
	return (line);
}

char	*process_stash(char *stash)
{
	char	*tempstash;
	int		i;

	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (!stash || stash[i] == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	if (stash[i] == '\n')
		i++;
	tempstash = ft_substr(stash, i, ft_strlen(stash));
	free(stash);
	stash = NULL;
	return (tempstash);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	if (!stash[fd])
		stash[fd] = ft_strdup("");
	stash[fd] = ft_readfile(fd, stash[fd]);
	line = ft_getline(stash[fd]);
	stash[fd] = process_stash(stash[fd]);
	return (line);
}

// int main()
// {
// 	// int fd = open("/Users/ethanlim/Documents/42-Core/get_next_line/
//	gnlTester/files/42_with_nl", O_RDWR);
// 	int fd = open("/Users/ethanlim/Desktop/test.txt", O_RDWR);
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
// 	free (buffer);
// 	// buffer = get_next_line(fd);
// 	// printf("string = %s\n", buffer);
// 	// printf("bytesread = %d\n", bytesread);

// 	// int bytesread2 = read(fd, buffer2, BUFFER_SIZE);
// 	// printf("string = %s\n", buffer2);
// 	// printf("bytesread = %d\n", bytesread2);
// }
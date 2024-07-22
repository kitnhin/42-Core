/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethanlim <ethanlim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 01:39:41 by ethanlim          #+#    #+#             */
/*   Updated: 2024/06/25 00:07:58 by ethanlim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_readfile(int fd, char *stash)
{
	char	*buffer;
	int		bytesread;

	bytesread = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (bytesread > 0 && ft_strchr(buffer, '\n') == 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread == -1)
		{
			free(stash);
			free(buffer);
			return (NULL);
		}
		buffer[bytesread] = '\0';
		stash = ft_strjoin_free(stash, buffer);
	}
	free (buffer);
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
	if (!stash || stash[i] == '\0')
	{
		free(stash);
		return (NULL);
	}
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (stash[i] == '\0')
	{
		free(stash);
		return (NULL);
	}
	if (stash[i] == '\n')
		i++;
	tempstash = ft_substr(stash, i, ft_strlen(stash));
	free(stash);
	return (tempstash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

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
// 	//  int fd = open("/Users/ethanlim/Documents/42-Core/
// 	// get_next_line/gnlTester/files/42_with_nl", O_RDWR);
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
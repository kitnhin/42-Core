#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 100
#endif


char *get_next_line(int fd);
size_t	ft_strlen(char const *str);
char *ft_strdup(char *s);
int	total_size(char const *s, unsigned int start, size_t len);
char	*ft_substr(char const *s, size_t start, size_t len);
char	*ft_getline(char **stash);
char	*ft_readline(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
#endif

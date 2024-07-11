#include "so_long.h"

int total_keys(char **map)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	while (map[j])
	{
		while (map[j][i] != '\0')
		{
			if (map[j][i] == 'C')
				count++;
			i++;
		}
		j++;
		i = 0;
	}
	return (count);
}
// char **readmap(int fd)
// {
// 	char **res;
// 	int j = 0;
// 	res = (char **)malloc(sizeof(char *) * 100); 
// 	while ((res[j] = get_next_line(fd)) != NULL)
// 		j++;
// 	if (res[0] == NULL)
// 	{
// 		ft_printf("file contains nth bruh\n");
// 		exit(1);
// 	}
// 	res[j] = NULL; 
// 	return res;
// }

// int main()
// {
// 	int fd = open("./maps/map1.ber", O_RDWR);
// 	char **map = readmap(fd);
//     // for (int i = 0; i < 5; i++) 
// 	// {
//     //     for (int j = 0; j < 13; j++) {
//     //         printf("%c ", map[i][j]);
//     //     }
//     //     printf("\n");
// 	// }
// 	int n = count_keys(map);
// 	ft_printf("num of keys = %d\n", n);
// 	return 0;
// }
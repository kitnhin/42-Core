#include "so_long.h"


char **readmap(int fd)
{
	char **res;
	int j = 0;
	res = (char **)malloc(sizeof(char *) * 100); 
	while ((res[j] = get_next_line(fd)) != NULL)
		j++;
	if (res[0] == NULL)
	{
		ft_printf("file contains nth bruh\n");
		exit(1);
	}
	res[j] = NULL; 
	return res;
}

void locate_e(char **map)
{
	int row;
	int col;

	row = 0;
	col = 0;
	while(map[row])
	{
		if(map[row][col] == 'E')
		{
			printf("row = %d, col = %d\n",row, col);
		}
		if(map[row][col] == '\0')
		{
			row++;
			col = 0;
		}
		col++;
	}
}


int main()
{
	int fd = open("./maps/map1.ber", O_RDWR);
	char **map = readmap(fd);
	locate_e(map);
	return 0;
}
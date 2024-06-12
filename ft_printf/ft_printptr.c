#include "ft_printf.h"

char *string(char *str, int len, uintptr_t tempptr, char *base)
{
	int i;

	i = len;
	while (--i >= 0)
    {
        str[i] = base[tempptr % 16];
        tempptr /= 16;
    }
    str[len] = '\0';
	return (str);
}
int printptr(void *ptr, char *base)
{
    int len;
    uintptr_t tempptr;
    uintptr_t tempptr2;
    char *str;

    len = 0;
    tempptr = (uintptr_t)ptr;
    tempptr2 = (uintptr_t)ptr;
    write(1,"0x",2);
    while(tempptr2 > 0)
    {
        tempptr2 /= 16;
        len++;
    }
    str = (char *)malloc(len + 1);
	str = string(str, len, tempptr, base);
    write(1,str,len);
    len += 2 ;
    free(str);
    return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethanlim <ethanlim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:49:30 by ethanlim          #+#    #+#             */
/*   Updated: 2024/06/06 15:54:13 by ethanlim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	num_len(int n)
{
	int	size;

	size = 0;
	if (n == -2147483648)
		return (11);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		size++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

void	nb_string(char *str, int n, int size)
{
	int	nb;
	int	i;

	i = size - 1;
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
	}
	while (n > 0)
	{
		nb = n % 10;
		str[i--] = nb + '0';
		n /= 10;
	}
	str[size] = '\0';
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;

	size = num_len(n);
	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	if (n == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		nb_string(str, 147483648, 11);
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	nb_string(str, n, size);
	return (str);
}

// int main()
// {
//     char *str;
//     str = ft_itoa(-2147483648);
//     printf("number string = %s\n", str);
//     free(str);
//     int n = num_len(-1234);
//     printf("size = %d",n);
//     return 0;
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethanlim <ethanlim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 12:41:27 by ethanlim          #+#    #+#             */
/*   Updated: 2024/07/30 12:43:04 by ethanlim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void printIntArray(int arr[], int size) {
//     for (int i = 0; i < size; i++) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	bubble_sort(int *array, int size)
{
	int	i;

	i = 0;
	while (i < (size - 1))
	{
		if (array[i] > array[i + 1])
		{
			swap(array + i, array + i + 1);
			i = 0;
		}
		else
			i++;
	}
}

void	put_sorted_index(t_stack_node *node, int *array)
{
	int	i;

	i = 0;
	while (node)
	{
		if (node->nbr == array[i])
		{
			node->sorted_index = i;
			node = node->next;
			i = 0;
		}
		else
			i++;
	}
}

void	init_sorted_index(t_stack_node **stack)
{
	int				*array;
	int				i;
	int				size;
	t_stack_node	*tempstack;

	tempstack = *stack;
	i = 0;
	size = stack_len(*stack);
	array = (int *)malloc(size);
	while (i < size)
	{
		array[i] = tempstack->nbr;
		tempstack = tempstack->next;
		i++;
	}
	bubble_sort(array, size);
	put_sorted_index(*stack, array);
	free(array);
}

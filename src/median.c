/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 15:32:24 by sgardner          #+#    #+#             */
/*   Updated: 2018/02/09 00:07:13 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

static void	max_heapify(int *arr, int node, int size)
{
	int	high;
	int	left;
	int	right;
	int	tmp;

	while (TRUE)
	{
		high = node;
		left = (2 * node) + 1;
		right = (2 * node) + 2;
		if (left < size && arr[left] > arr[high])
			high = left;
		if (right < size && arr[right] > arr[high])
			high = right;
		if (high != node)
		{
			tmp = arr[node];
			arr[node] = arr[high];
			arr[high] = tmp;
			node = high;
		}
		else
			break ;
	}
}

static void	heap_sort(int *arr, int size)
{
	int	tmp;
	int	i;

	i = (size / 2) - 1;
	while (i >= 0)
		max_heapify(arr, i--, size);
	i = size - 1;
	while (i >= 0)
	{
		tmp = arr[0];
		arr[0] = arr[i];
		arr[i] = tmp;
		max_heapify(arr, 0, i--);
	}
}

int			find_median(t_stack *stack)
{
	t_num	*num;
	int		*arr;
	int		i;

	i = 0;
	num = stack->head;
	if (!(arr = ft_memalloc(sizeof(int) * (stack->size + 1))))
		FATAL_ERROR;
	while (i < stack->size)
	{
		arr[i++] = num->n;
		num = num->next;
	}
	heap_sort(arr, i);
	i = arr[(i / 2) - 1];
	free(arr);
	return (i);
}

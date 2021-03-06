/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 15:46:54 by sgardner          #+#    #+#             */
/*   Updated: 2018/01/29 01:48:28 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void	append_num(t_stack *stack, t_num *num)
{
	if (!stack->head)
		stack->head = num;
	else
	{
		num->prev = stack->head->prev;
		num->next = stack->head;
		stack->head->prev->next = num;
		stack->head->prev = num;
	}
	stack->size++;
}

t_num	*create_num(int n)
{
	t_num	*num;

	if (!(num = ft_memalloc(sizeof(t_num))))
		FATAL_ERROR;
	num->n = n;
	num->prev = num;
	num->next = num;
	return (num);
}

void	remove_num(t_stack *stack, t_num *num)
{
	if (stack->head == num && num->next == num)
		stack->head = NULL;
	else
	{
		num->prev->next = num->next;
		num->next->prev = num->prev;
		if (stack->head == num)
			stack->head = num->next;
	}
	stack->size--;
	num->prev = num;
	num->next = num;
}

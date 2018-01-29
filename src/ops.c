/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 00:24:42 by sgardner          #+#    #+#             */
/*   Updated: 2018/01/29 02:03:51 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_push(t_stack *s1, t_stack *s2)
{
	t_num	*num;

	if (!s1->size)
		return ;
	num = s1->head;
	remove_num(s1, num);
	append_num(s2, num);
	s2->head = num;
}

void	op_rotate_up(t_stack *stack)
{
	if (s1->size < 2)
		return ;
	stack->head = stack->head->next;
}

void	op_rotate_down(t_stack *stack)
{
	if (s1->size < 2)
		return ;
	stack->head = stack->head->prev;
}

void	op_swap(t_stack *stack)
{
	t_num	*next;

	if (stack->size < 2)
		return ;
	next = stack->head->next;
	remove_num(stack, next);
	append_num(stack, next);
	stack->head = next;
}

void	perform_op(t_swap *swap, int op)
{
	if (op == SA || op == SS)
		op_swap(swap->a);
	if (op == SB || op == SS)
		op_swap(swap->b);
	if (op == PA)
		op_push(swap->b, swap->a);
	if (op == PB)
		op_push(swap->a, swap->b);
	if (op == RA || op == RR)
		op_rotate_up(swap->a);
	if (op == RB || op == RR)
		op_rotate_up(swap->b);
	if (op == RRA || op == RRR)
		op_rotate_down(swap->a);
	if (op == RRB || op == RRR)
		op_rotate_down(swap->b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 13:29:05 by sgardner          #+#    #+#             */
/*   Updated: 2018/02/08 07:06:20 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_to(t_swap *swap, t_stack *stack, t_num *dest)
{
	t_num	*num;
	int		rot;
	int		rrot;

	rot = 0;
	if (stack->head == dest)
		return ;
	num = stack->head;
	while (num != dest)
	{
		++rot;
		num = num->next;
	}
	rrot = 0;
	num = stack->head;
	while (num != dest)
	{
		++rrot;
		num = num->prev;
	}
	if (rot < rrot)
		confirm_op(swap, (stack == swap->a) ? RA : RB, rot);
	else
		confirm_op(swap, (stack == swap->a) ? RRA : RRB, rrot);
}

t_bool		rotate_sort(t_swap *swap)
{
	t_num	*min;

	if (swap->b->size
		|| !is_sorted((min = find_min(swap->a)), swap->a->size))
		return (FALSE);
	rotate_to(swap, swap->a, min);
	return (TRUE);
}

void		small_sort(t_swap *swap)
{
	t_num	*min;

	while (swap->a->size > 3)
	{
		rotate_to(swap, swap->a, find_min(swap->a));
		confirm_op(swap, PB, 1);
	}
	min = find_min(swap->a);
	if (is_sorted(min, swap->a->size))
		rotate_to(swap, swap->a, min);
	else
	{
		confirm_op(swap, SA, 1);
		rotate_to(swap, swap->a, min);
	}
	confirm_op(swap, PA, swap->b->size);
}

void		sort(t_swap *swap)
{
	int	num;

	if (rotate_sort(swap))
		return ;
	while (!is_sorted(find_min(swap->a), swap->a->size))
	{
		num = optimal_rot(swap, &b_good_push);
		confirm_op(swap, PB, num);
	}
	while (swap->b->size)
	{
		num = optimal_rot(swap, &a_good_push);
		confirm_op(swap, PA, num);
	}
	rotate_sort(swap);
}

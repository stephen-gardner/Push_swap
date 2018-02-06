/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 13:29:05 by sgardner          #+#    #+#             */
/*   Updated: 2018/02/05 16:24:10 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	rotate_sort(t_swap *swap)
{
	t_num	*num;
	t_num	*min;
	int		ra;
	int		rra;

	if (swap->b->size
		|| !is_sorted((min = find_min(swap->a)), swap->a->size))
		return (FALSE);
	ra = 0;
	num = swap->a->head;
	while (num != min && ++ra)
		num = num->next;
	rra = 0;
	num = swap->a->head;
	while (num != min && ++rra)
		num = num->prev;
	if (ra < rra)
		confirm_op(swap, RA, ra);
	else
		confirm_op(swap, RRA, rra);
	return (TRUE);
}

void	sort(t_swap *swap)
{
	rotate_sort(swap);
	while (!is_sorted(find_min(swap->a), swap->a->size))
	{
		optimal_rot(swap, &b_good_push);
		confirm_op(swap, PB, 1);
	}
	while (swap->b->size)
	{
		optimal_rot(swap, &a_good_push);
		confirm_op(swap, PA, 1);
	}
	rotate_sort(swap);
}

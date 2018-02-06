/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 13:29:05 by sgardner          #+#    #+#             */
/*   Updated: 2018/02/06 01:37:28 by sgardner         ###   ########.fr       */
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

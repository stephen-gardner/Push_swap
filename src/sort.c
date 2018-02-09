/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 13:29:05 by sgardner          #+#    #+#             */
/*   Updated: 2018/02/09 00:17:33 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	merge_b(t_swap *swap)
{
	int	num;

	while (swap->b->size)
	{
		num = optimal_rot(swap, &a_good_push);
		confirm_op(swap, PA, num);
	}
	rotate_sort(swap);
}

void		large_sort(t_swap *swap)
{
	t_bool	low;
	int		median;
	int		i;

	low = TRUE;
	while (!is_sorted(find_min(swap->a), swap->a->size))
	{
		i = 0;
		median = find_median(swap->a);
		while (i++ < swap->a->size)
		{
			if (swap->a->head->n < median)
				confirm_op(swap, RRA, 1);
			else
				confirm_op(swap, PB, 1);
		}
	}
	merge_b(swap);
}

void		medium_sort(t_swap *swap)
{
	while (!is_sorted(find_min(swap->a), swap->a->size))
	{
		confirm_op(swap, PB, 2);
		if (swap->b->head->n < swap->b->head->next->n)
		{
			if (swap->a->head->n > swap->a->head->next->n)
				confirm_op(swap, SS, 1);
			else
				confirm_op(swap, SB, 1);
		}
	}
	merge_b(swap);
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

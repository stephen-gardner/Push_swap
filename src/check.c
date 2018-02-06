/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 23:21:26 by sgardner          #+#    #+#             */
/*   Updated: 2018/02/05 15:49:47 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

static t_bool	b_has_order(t_swap *swap)
{
	t_num	*min;
	int		i;

	if (swap->b->size < 3)
		return (TRUE);
	i = 0;
	min = find_min(swap->b);
	while (++i < swap->b->size)
	{
		if (min->n > min->prev->n)
			return (FALSE);
		min = min->prev;
	}
	return (TRUE);
}

t_bool			b_good_push(t_swap *swap)
{
	if (swap->b->size < 1)
		return (TRUE);
	perform_op(swap, PB);
	if (b_has_order(swap))
	{
		perform_op(swap, PA);
		return (TRUE);
	}
	perform_op(swap, PA);
	return (FALSE);
}

t_bool			a_good_push(t_swap *swap)
{
	perform_op(swap, PA);
	if (is_sorted(find_min(swap->a), swap->a->size))
	{
		perform_op(swap, PB);
		return (TRUE);
	}
	perform_op(swap, PB);
	return (FALSE);
}

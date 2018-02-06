/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 23:21:26 by sgardner          #+#    #+#             */
/*   Updated: 2018/02/05 22:29:05 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

static t_bool	b_has_order(t_swap *swap)
{
	t_num	*min;
	int		i;

	if (swap->b->size < 2)
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

int				b_good_push(t_swap *swap)
{
	int	n;
	int	res;

	n = 0;
	res = 0;
	while (swap->a->size)
	{
		perform_op(swap, PB);
		n++;
		if (b_has_order(swap))
			res++;
		else
			break ;
	}
	while (n-- > 0)
		perform_op(swap, PA);
	return (res);
}

int				a_good_push(t_swap *swap)
{
	int	n;
	int	res;

	n = 0;
	res = 0;
	while (swap->b->size)
	{
		perform_op(swap, PA);
		n++;
		if (is_sorted(find_min(swap->a), swap->a->size))
			res++;
		else
			break ;
	}
	while (n-- > 0)
		perform_op(swap, PB);
	return (res);
}

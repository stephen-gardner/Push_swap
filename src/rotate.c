/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 15:25:40 by sgardner          #+#    #+#             */
/*   Updated: 2018/02/06 01:38:50 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_score	score(t_swap *swap, t_bool (*check)(t_swap *), int op, int max)
{
	t_score	res;
	int		count;
	int		pushed;

	count = 0;
	res.count = -1;
	res.pushed = 0;
	while (count <= max)
	{
		if ((pushed = check(swap)))
		{
			if (res.count < 0 || (pushed - count) > res.score)
			{
				res.count = count;
				res.pushed = pushed;
				res.score = pushed - count;
			}
		}
		perform_op(swap, op);
		++count;
	}
	return (res);
}

static t_swap	*dup_swap(t_swap *swap)
{
	static t_swap	dup;
	static t_stack	dup_a;
	static t_stack	dup_b;

	dup.a = &dup_a;
	dup.b = &dup_b;
	ft_memcpy(dup.a, swap->a, sizeof(t_stack));
	ft_memcpy(dup.b, swap->b, sizeof(t_stack));
	return (&dup);
}

static int		get_max_rot(t_swap *swap, int op)
{
	int	max;

	if (op == RA || op == RRA)
		max = swap->a->size;
	else if (op == RB || op == RRB)
		max = swap->b->size;
	else
		max = (swap->a->size > swap->b->size) ? swap->a->size : swap->b->size;
	max = (max % 2) ? (max / 2) + 1 : max / 2;
	return (max);
}

int				optimal_rot(t_swap *swap, t_bool (*check)(t_swap *))
{
	t_score	res[6];
	t_swap	*dup;
	int		op;
	int		i;

	ft_memset(res, 0, sizeof(t_score) * 6);
	i = 0;
	while (i < 6)
	{
		dup = dup_swap(swap);
		res[i] = score(dup, check, i, get_max_rot(dup, i));
		i++;
	}
	op = 0;
	while (--i >= 0)
	{
		if (res[i].count > 0
			&& (res[op].count < 0 || res[i].score > res[op].score))
			op = i;
	}
	if (res[op].count > -1)
		confirm_op(swap, op, res[op].count);
	return (res[op].pushed);
}

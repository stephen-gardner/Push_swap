/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 15:25:40 by sgardner          #+#    #+#             */
/*   Updated: 2018/02/05 16:35:15 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		crot(t_swap *swap, t_bool (*check)(t_swap *), int op, int max)
{
	int		count;

	count = 0;
	while (count <= max)
	{
		if (check(swap))
			return (count);
		perform_op(swap, op);
		++count;
	}
	return (-1);
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
	return (max);
}

void			optimal_rot(t_swap *swap, t_bool (*check)(t_swap *))
{
	t_swap	*dup;
	int		count[6];
	int		max;
	int		rot;
	int		i;

	ft_memset(count, 0, sizeof(int) * 6);
	i = 0;
	while (i < 6)
	{
		dup = dup_swap(swap);
		max = get_max_rot(dup, i);
		count[i] = crot(dup, check, i, max);
		i++;
	}
	rot = 0;
	while (i-- > 0)
	{
		if (count[rot] < 0 || (count[i] > -1 && count[i] < count[rot]))
			rot = i;
	}
	if (count[rot] > 0)
		confirm_op(swap, rot, count[rot]);
}

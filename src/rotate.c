/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 15:25:40 by sgardner          #+#    #+#             */
/*   Updated: 2018/02/04 22:24:50 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		crot(t_swap *swap, t_bool (**checks)(t_swap *), int op, int max)
{
	int		count;
	int		i;

	count = 0;
	while (count < max)
	{
		i = 0;
		while (checks[i])
		{
			if (!checks[i++](swap))
				break ;
		}
		if (!checks[i])
			return (count);
		perform_op(swap, op);
		++count;
	}
	return (0);
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

void			optimal_rot(t_swap *swap, t_bool (**checks)(t_swap *))
{
	t_swap	*dup;
	int		count[6];
	int		max;
	int		rot;
	int		i;

	i = 0;
	rot = 0;
	while (i < 6)
	{
		dup = dup_swap(swap);
		max = get_max_rot(dup, i);
		if ((count[i] = crot(dup, checks, i, max)) < count[rot])
			rot = i;
		i++;
	}
	if (count[rot])
		confirm_op(swap, rot, count[rot]);
}

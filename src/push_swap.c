/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 01:03:51 by sgardner          #+#    #+#             */
/*   Updated: 2018/02/09 00:09:39 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"

void		confirm_op(t_swap *swap, int op, int n)
{
	while (n--)
	{
		perform_op(swap, op);
		if (op == DR)
		{
			append_num(swap->ops, create_num(RA));
			append_num(swap->ops, create_num(RRB));
		}
		else if (op == DRR)
		{
			append_num(swap->ops, create_num(RRA));
			append_num(swap->ops, create_num(RB));
		}
		else
			append_num(swap->ops, create_num(op));
	}
}

static void	report_ops(t_stack *op_stack)
{
	static char	*ops[NOPS] = { OPS };
	char		*out;
	char		*tmp;
	int			len;
	int			i;

	i = 0;
	len = 0;
	while (i++ < op_stack->size)
	{
		len += ft_strlen(ops[op_stack->head->n]) + 1;
		op_stack->head = op_stack->head->next;
	}
	if (!(out = ft_memalloc(len + 1)))
		FATAL_ERROR;
	tmp = out;
	while (--i > 0)
	{
		tmp = ft_stpcpy(tmp, ops[op_stack->head->n]);
		*tmp++ = '\n';
		op_stack->head = op_stack->head->next;
	}
	write(1, out, len);
	free(out);
}

int			main(int ac, char **av)
{
	t_swap	*swap;

	if (ac < 2)
		return (0);
	swap = get_swap(av + 1, FALSE);
	if (!rotate_sort(swap))
	{
		if (swap->a->size < 9)
			small_sort(swap);
		else if (swap->a->size < 101)
			medium_sort(swap);
		else
			large_sort(swap);
	}
	report_ops(swap->ops);
	return (0);
}

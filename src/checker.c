/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:12:12 by sgardner          #+#    #+#             */
/*   Updated: 2018/01/29 22:22:33 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"

static void	parse_op(t_stack *op_stack, char *arg)
{
	static t_opmap	ops[] = {
		{ "sa", SA },
		{ "sb", SB },
		{ "ss", SS },
		{ "pa", PA },
		{ "pb", PB },
		{ "ra", RA },
		{ "rb", RB },
		{ "rr", RR },
		{ "rra", RRA },
		{ "rrb", RRB },
		{ "rrr", RRR }
	};
	static int		size = sizeof(ops) / sizeof(t_opmap);
	int				i;

	i = 0;
	while (i < size)
	{
		if (!ft_strcmp(ops[i].cmd, arg))
			return (append_num(op_stack, create_num(ops[i].op)));
		++i;
	}
	FATAL_ERROR;
}

int			main(int ac, char **av)
{
	t_swap	*swap;
	t_num	*op;
	char	*line;
	int		i;

	if (ac < 2)
		return (0);
	swap = init_stacks(av + 1);
	while ((i = get_next_line(0, &line)) > 0)
	{
		parse_op(swap->ops, line);
		free(line);
	}
	if (i < 0)
		FATAL_ERROR;
	op = swap->ops->head;
	while (i++ < swap->ops->size)
	{
		perform_op(swap, op->n);
		op = op->next;
	}
	write(1, (is_sorted(swap->a->head, swap->a->size)) ? "OK\n" : "KO\n", 3);
	return (0);
}

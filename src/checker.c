/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:12:12 by sgardner          #+#    #+#             */
/*   Updated: 2018/01/31 16:55:42 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "push_swap.h"

static void	parse_op(t_stack *op_stack, char *arg)
{
	static char	*ops[NOPS] = { OPS };
	static int	size = sizeof(ops) / sizeof(char *);
	int			i;

	i = 0;
	while (i < size)
	{
		if (!ft_strcmp(ops[i], arg))
			return (append_num(op_stack, create_num(i)));
		++i;
	}
	FATAL_ERROR;
}

int			main(int ac, char **av)
{
	t_swap	*swap;
	t_bool	sorted;
	t_num	*op;
	char	*line;
	int		i;

	if (ac < 2)
		return (0);
	swap = get_swap(av + 1);
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
	sorted = is_sorted(swap->a->head, swap->a->size);
	write(1, !swap->b->size && sorted ? "OK\n" : "KO\n", 3);
	return (0);
}

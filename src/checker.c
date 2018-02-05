/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:12:12 by sgardner          #+#    #+#             */
/*   Updated: 2018/02/04 22:55:03 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "push_swap.h"

static int	calc_status_len(t_stack *stack)
{
	t_num	*num;
	int		len;
	int		n;
	int		i;

	i = 0;
	len = 0;
	num = stack->head;
	while (i++ < stack->size)
	{
		n = num->n;
		if (n < 1)
			++len;
		while (n)
		{
			++len;
			n /= 10;
		}
		if (i < stack->size)
			len += 2;
		num = num->next;
	}
	return (len);
}

static void	print_status(char *label, t_stack *stack)
{
	t_num	*num;
	char	*out;
	char	*tmp;
	char	*n;
	int		i;

	if (!(out = ft_memalloc(calc_status_len(stack) + 5)))
		FATAL_ERROR;
	i = 0;
	tmp = ft_stpcpy(out, label);
	num = stack->head;
	while (i++ < stack->size)
	{
		n = ps_itoa(num->n);
		tmp = ft_stpcpy(tmp, n);
		if (i < stack->size)
			tmp = ft_stpcpy(tmp, ", ");
		num = num->next;
	}
	*tmp = '\n';
	write(1, out, ft_strlen(out));
	free(out);
}

static void	check(t_swap *swap)
{
	t_bool	sorted;
	t_num	*op;
	int		i;

	i = 0;
	op = swap->ops->head;
	while (i++ < swap->ops->size)
	{
		perform_op(swap, op->n);
		if (swap->verbose)
		{
			print_status("A: ", swap->a);
			print_status("B: ", swap->b);
			write(1, "\n", 1);
		}
		op = op->next;
	}
	sorted = is_sorted(swap->a->head, swap->a->size);
	write(1, !swap->b->size && sorted ? "OK\n" : "KO\n", 3);
}

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
	char	*line;
	int		i;

	if (ac < 2)
		return (0);
	swap = get_swap(av + 1, TRUE);
	while ((i = get_next_line(0, &line)) > 0)
	{
		parse_op(swap->ops, line);
		free(line);
	}
	if (i < 0)
		FATAL_ERROR;
	check(swap);
	return (0);
}

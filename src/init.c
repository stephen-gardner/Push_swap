/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 12:18:19 by sgardner          #+#    #+#             */
/*   Updated: 2018/01/28 21:47:44 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

static void		exit_if_duplicate(t_stack *stack, int n)
{
	t_num	*num;
	int		i;

	i = 0;
	num = stack->head;
	while (i++ < stack->size)
	{
		if (num->n == n)
			FATAL_ERROR;
		num = num->next;
	}
}

static t_swap	*init_stacks(char **tab)
{
	t_swap	*swap;
	char	**args;
	int		n;
	int		i;

	if (!(swap = ft_memalloc(sizeof(t_swap)))
		|| !(swap->a = ft_memalloc(sizeof(t_stack)))
		|| !(swap->b = ft_memalloc(sizeof(t_stack))))
		FATAL_ERROR;
	while (*tab)
	{
		i = 0;
		args = split(*tab++);
		while (args[i])
		{
			n = ps_atoi(args[i++]);
			exit_if_duplicate(swap->a, n);
			append_num(swap->a, create_num(n));
		}
		free(args);
	}
	return (swap);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 12:20:23 by sgardner          #+#    #+#             */
/*   Updated: 2018/01/31 21:50:59 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include "push_swap.h"

static void	exit_if_duplicate(t_stack *stack, int n)
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

t_swap		*get_swap(char **tab, t_bool checker)
{
	t_swap	*swap;
	char	**args;
	int		n;
	int		i;

	if (!(swap = ft_memalloc(sizeof(t_swap)))
		|| !(swap->a = ft_memalloc(sizeof(t_stack)))
		|| !(swap->b = ft_memalloc(sizeof(t_stack)))
		|| !(swap->ops = ft_memalloc(sizeof(t_stack))))
		FATAL_ERROR;
	parse_flags(swap, tab, checker);
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

int			ps_atoi(char *str)
{
	long	n;
	int		sign;

	if (!*str)
		FATAL_ERROR;
	n = 0;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '+' || *str == '-')
		str++;
	if (!*str)
		FATAL_ERROR;
	while (*str)
	{
		if (((unsigned int)(*str - '0') > 9)
			|| (n = (n * 10) + ((*str++ - '0') * sign)) > INT_MAX
			|| n < INT_MIN)
			FATAL_ERROR;
	}
	return ((int)n);
}

static int	count_args(char *arg)
{
	int	count;

	count = 0;
	while (*arg)
	{
		if (*arg != ' ' && (*(arg + 1) == ' ' || *(arg + 1) == '\0'))
			count++;
		arg++;
	}
	return (count);
}

char		**split(char *arg)
{
	char	**arr;
	int		size;
	int		i;

	size = count_args(arg);
	if (!(arr = ft_memalloc(sizeof(char *) * (size + 1))))
		FATAL_ERROR;
	i = 0;
	while (*arg)
	{
		while (*arg == ' ')
			*arg++ = '\0';
		if (*arg)
			arr[i++] = arg;
		while (*arg && *arg != ' ')
			arg++;
	}
	return (arr);
}

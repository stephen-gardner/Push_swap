/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 12:20:23 by sgardner          #+#    #+#             */
/*   Updated: 2018/01/29 22:49:08 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"

void		fatal_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
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

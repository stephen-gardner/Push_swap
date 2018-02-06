/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 22:49:31 by sgardner          #+#    #+#             */
/*   Updated: 2018/02/05 22:15:32 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"

void		fatal_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

t_num		*find_min(t_stack *stack)
{
	t_num	*min;
	t_num	*num;
	int		i;

	i = 0;
	min = NULL;
	num = stack->head;
	while (i++ < stack->size)
	{
		if (!min || min->n > num->n)
			min = num;
		num = num->next;
	}
	return (min);
}

t_bool		is_sorted(t_num *num, int size)
{
	int		i;

	if (size < 2)
		return (TRUE);
	i = 0;
	while (++i < size)
	{
		if (num->n > num->next->n)
			return (FALSE);
		num = num->next;
	}
	return (TRUE);
}

void		parse_flags(t_swap *swap, char **av, t_bool checker)
{
	int	len;
	int	i;

	if (!checker)
		return ;
	len = 0;
	while (av[len])
		len++;
	i = 0;
	while (av[i])
	{
		if (*av[i] == '-')
		{
			if (*(av[i] + 1) == 'v' && !swap->verbose)
			{
				swap->verbose = TRUE;
				ft_memmove(av + i, av + i + 1, sizeof(char *) * (len - i + 1));
			}
		}
		i++;
	}
}

char		*ps_itoa(int n)
{
	static char	num[12];
	int			digit;
	int			sign;

	digit = 10;
	sign = (n < 0) ? -1 : 1;
	ft_memset(num, '\0', 11);
	if (!n)
		num[digit] = '0';
	while (n)
	{
		num[digit] = ((n % 10) * sign) + '0';
		if ((n /= 10) || sign < 0)
			--digit;
	}
	if (sign < 0)
		num[digit] = '-';
	return (&num[digit]);
}

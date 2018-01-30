/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 22:49:31 by sgardner          #+#    #+#             */
/*   Updated: 2018/01/29 23:16:25 by sgardner         ###   ########.fr       */
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

t_bool		is_sorted(t_num	*num, int size)
{
	int		i;

	if (size < 1)
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

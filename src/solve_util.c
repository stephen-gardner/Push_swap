/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 22:49:31 by sgardner          #+#    #+#             */
/*   Updated: 2018/01/29 22:49:41 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

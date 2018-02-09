/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 23:21:26 by sgardner          #+#    #+#             */
/*   Updated: 2018/02/09 00:08:45 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				a_good_push(t_swap *swap)
{
	int	n;
	int	res;

	n = 0;
	res = 0;
	while (swap->b->size)
	{
		perform_op(swap, PA);
		n++;
		if (is_sorted(find_min(swap->a), swap->a->size))
			res++;
		else
			break ;
	}
	while (n-- > 0)
		perform_op(swap, PB);
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 13:53:00 by sgardner          #+#    #+#             */
/*   Updated: 2018/01/29 23:07:08 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ps_structs.h"
# include "libft.h"

#include <stdio.h> // REMOVE BEFORE SUBMITTING

# define FATAL_ERROR fatal_error()

typedef enum	e_psop
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}				t_psop;

/*
** init.c
*/

t_swap			*init_stacks(char **tab);

/*
** list_stack.c
*/

void			append_num(t_stack *stack, t_num *num);
t_num			*create_num(int n);
void			remove_num(t_stack *stack, t_num *num);

/*
** load_util.c
*/

void			fatal_error(void);
int				ps_atoi(char *str);
char			**split(char *arg);

/*
** ops.c
*/

void			op_push(t_stack *s1, t_stack *s2);
void			op_rotate_up(t_stack *stack);
void			op_rotate_down(t_stack *stack);
void			op_swap(t_stack *stack);
void			perform_op(t_swap *swap, int op);

/*
** solve_util.c
*/

t_bool			is_sorted(t_num *num, int size);
#endif

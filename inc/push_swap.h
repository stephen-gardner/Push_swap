/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 13:53:00 by sgardner          #+#    #+#             */
/*   Updated: 2018/02/04 22:37:07 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ps_structs.h"
# include "libft.h"

#include <stdio.h> // REMOVE BEFORE SUBMITTING

# define FATAL_ERROR fatal_error()
# define OPS "rr", "rrr", "ra", "rb", "rra", "rrb", "sa", "sb", "ss", "pa", "pb"

typedef enum	e_psop
{
	RR,
	RRR,
	RA,
	RB,
	RRA,
	RRB,
	SA,
	SB,
	SS,
	PA,
	PB,
	NOPS
}				t_psop;

/*
** list_stack.c
*/

void			append_num(t_stack *stack, t_num *num);
t_num			*create_num(int n);
void			remove_num(t_stack *stack, t_num *num);

/*
** load.c
*/

t_swap			*get_swap(char **tab, t_bool checker);
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
** push_swap.c
*/

void			confirm_op(t_swap *swap, int op, int n);

/*
** rotate.c
*/

void			optimal_rot(t_swap *swap, t_bool (**checks)(t_swap *));

/*
** sort.c
*/

t_bool			rotate_sort(t_swap *swap);

/*
** util.c
*/

void			fatal_error(void);
t_num			*find_min(t_stack *stack);
t_bool			is_sorted(t_num *num, int size);
void			parse_flags(t_swap *swap, char **av, t_bool checker);
char			*ps_itoa(int n);
#endif

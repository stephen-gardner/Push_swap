/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 13:53:00 by sgardner          #+#    #+#             */
/*   Updated: 2018/01/28 21:03:31 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

#include <stdio.h> // REMOVE BEFORE SUBMITTING

# define FATAL_ERROR fatal_error()

typedef struct	s_num
{
	int				n;
	struct s_num	*prev;
	struct s_num	*next;
}				t_num;

typedef struct	s_stack
{
	t_num	*head;
	int		size;
}				t_stack;

typedef struct	s_swap
{
	t_stack	*a;
	t_stack	*b;
}				t_swap;

/*
** list_stack.c
*/

void			append_num(t_stack *stack, t_num *num);
t_num			*create_num(int n);
void			push_num(t_stack *stack, t_num *num);
void			remove_num(t_stack *stack, t_num *num);

/*
** util.c
*/

void			fatal_error(void);
int				ps_atoi(char *str);
char			**split(char *arg);
#endif

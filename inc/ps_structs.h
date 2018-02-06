/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 23:05:29 by sgardner          #+#    #+#             */
/*   Updated: 2018/02/06 01:41:07 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STRUCTS_H
# define PS_STRUCTS_H

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
	t_stack	*ops;
	int		verbose;
}				t_swap;

typedef struct	s_score
{
	int	score;
	int	count;
	int	pushed;
}				t_score;
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas-s <slucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 13:16:52 by slucas-s          #+#    #+#             */
/*   Updated: 2021/09/24 12:01:02 by slucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "stack/stack.h"
# include <unistd.h>

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;
# define INT_MAX 2147483647
# define INT_MIN -2147483648

/* Struct with two stacks.
*	And the amunt of numbers to sort. */
typedef struct s_data
{
	int		count;
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_data;

int		error(char *message);
void	*null_error(char *message);

void	write_op(char *text);
void	repeat_op(void (*op)(t_data *), int x, t_data *data);

void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);

void	pa(t_data *data);
void	pb(t_data *data);

void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);

void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);

#endif
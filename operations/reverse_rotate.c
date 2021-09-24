/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas-s <slucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:41:22 by slucas-s          #+#    #+#             */
/*   Updated: 2021/09/08 16:51:31 by slucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	r_rotate(t_stack **stack)
{
	t_stack	*first;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = stack_last(*stack);
	(*stack)->next = first;
	stack_prev(*stack, *stack)->next = NULL;
}

/* Shift down all elements of stack A by 1.
The last element becomes the first one. */
void	rra(t_data *data)
{
	r_rotate(&data->stack_a);
	write_op("rra\n");
}

/* Shift down all elements of stack B by 1.
The last element becomes the first one. */
void	rrb(t_data *data)
{
	r_rotate(&data->stack_b);
	write_op("rrb\n");
}

/* 	Shift down all elements of the two stacks. */
void	rrr(t_data *data)
{
	r_rotate(&data->stack_a);
	r_rotate(&data->stack_b);
	write_op("rrr\n");
}

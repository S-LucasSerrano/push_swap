/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas-s <slucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:41:22 by slucas-s          #+#    #+#             */
/*   Updated: 2021/09/27 13:01:36 by slucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	r_rotate_op(t_stack **stack)
{
	t_stack	*first;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = stack_last(*stack);
	(*stack)->next = first;
	stack_prev(*stack, *stack)->next = NULL;
}

/* Shift down all elements of a stack by 1.
The last element becomes the first one. */
void	r_rotate(t_stack_id stack_id, t_data *data)
{
	if (stack_id == STACK_A)
	{
		r_rotate_op(&data->stack_a);
		write_op("rra\n");
	}
	else if (stack_id == STACK_B)
	{
		r_rotate_op(&data->stack_b);
		write_op("rrb\n");
	}
	else if (stack_id == BOTH)
	{
		r_rotate_op(&data->stack_a);
		r_rotate_op(&data->stack_b);
		write_op("rrr\n");
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas-s <slucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:41:22 by slucas-s          #+#    #+#             */
/*   Updated: 2021/09/29 14:01:34 by slucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	r_rotate_op(t_stack **stack)
{
	t_stack	*first;

	first = *stack;
	*stack = stack_last(*stack);
	(*stack)->next = first;
	first->prev = *stack;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/* Shift down all elements of a stack by 1.
The last element becomes the first one. */
void	r_rotate(t_stack_id stack_id, t_data *data)
{
	if (stack_id == A_STACK)
	{
		if (!data->stack_a || !data->stack_a->next)
			return ;
		r_rotate_op(&data->stack_a);
		write_op("rra\n");
	}
	else if (stack_id == B_STACK)
	{
		if (!data->stack_b || !data->stack_b->next)
			return ;
		r_rotate_op(&data->stack_b);
		write_op("rrb\n");
	}
	else if (stack_id == BOTH)
	{
		if ((!data->stack_a || !data->stack_a->next)
			&& (!data->stack_b || !data->stack_b->next))
			return ;
		r_rotate_op(&data->stack_a);
		r_rotate_op(&data->stack_b);
		write_op("rrr\n");
	}
}

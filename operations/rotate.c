/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas-s <slucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:25:21 by slucas-s          #+#    #+#             */
/*   Updated: 2021/09/29 14:54:46 by slucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate_op(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	first = *stack;
	last = stack_last(*stack);
	*stack = first->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	(*stack)->prev = NULL;
}

/*	Shift up all elements of a stack by 1.
*	The first element becomes the last one. */
void	rotate(t_stack_id stack_id, t_data *data)
{
	if (stack_id == A_STACK)
	{
		if (!data->stack_a || !data->stack_a->next)
			return ;
		rotate_op(&data->stack_a);
		write_op("ra\n");
	}
	else if (stack_id == B_STACK)
	{
		if (!data->stack_b || !data->stack_b->next)
			return ;
		rotate_op(&data->stack_b);
		write_op("rb\n");
	}
	else if (stack_id == BOTH)
	{
		if ((!data->stack_a || !data->stack_a->next)
			&& (!data->stack_b || !data->stack_b->next))
			return ;
		rotate_op(&data->stack_a);
		rotate_op(&data->stack_b);
		write_op("rr\n");
	}
}

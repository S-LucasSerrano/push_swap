/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas-s <slucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:25:21 by slucas-s          #+#    #+#             */
/*   Updated: 2021/09/27 13:01:44 by slucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate_op(t_stack **stack)
{
	t_stack	*first;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	stack_last(*stack)->next = first;
	first->next = NULL;
}

/*	Shift up all elements of a stack by 1.
*	The first element becomes the last one. */
void	rotate(t_stack_id stack_id, t_data *data)
{
	if (stack_id == STACK_A)
	{
		rotate_op(&data->stack_a);
		write_op("ra\n");
	}
	else if (stack_id == STACK_B)
	{
		rotate_op(&data->stack_b);
		write_op("rb\n");
	}
	else if (stack_id == BOTH)
	{
		rotate_op(&data->stack_a);
		rotate_op(&data->stack_b);
		write_op("rr\n");
	}
}

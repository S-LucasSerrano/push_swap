/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas-s <slucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:25:21 by slucas-s          #+#    #+#             */
/*   Updated: 2021/09/06 14:47:40 by slucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*first;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	stack_last(*stack)->next = first;
	first->next = NULL;
}

/*	Shift up all elements of stack A by 1.
*	The first element becomes the last one. */
void	ra(t_data *data)
{
	rotate(&data->stack_a);
	write_op("ra\n");
}

/*	Shift up all elements of stack B by 1.
*	The first element becomes the last one. */
void	rb(t_data *data)
{
	rotate(&data->stack_b);
	write_op("rb\n");
}

/* 	Shift up all elements of the two stacks. */
void	rr(t_data *data)
{
	rotate(&data->stack_a);
	rotate(&data->stack_b);
	write_op("rr\n");
}

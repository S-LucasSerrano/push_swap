/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas-s <slucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 13:08:29 by slucas-s          #+#    #+#             */
/*   Updated: 2021/09/29 14:57:31 by slucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap_op(t_stack **stack)
{
	t_stack	*first;

	first = *stack;
	*stack = (*stack)->next;
	first->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = first;
	(*stack)->next = first;
	first->prev = *stack;
	(*stack)->prev = NULL;
}

void	swap(t_stack_id stack_id, t_data *data)
{
	if (stack_id == A_STACK)
	{
		if (!data->stack_a || !data->stack_a->next)
			return ;
		swap_op(&data->stack_a);
		write_op("sa\n");
	}
	else if (stack_id == B_STACK)
	{
		if (!data->stack_b || !data->stack_b->next)
			return ;
		swap_op(&data->stack_b);
		write_op("sb\n");
	}
	else if (stack_id == BOTH)
	{
		if ((!data->stack_a || !data->stack_a->next)
			&& (!data->stack_b || !data->stack_b->next))
			return ;
		swap_op(&data->stack_a);
		swap_op(&data->stack_b);
		write_op("ss\n");
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas-s <slucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 13:08:29 by slucas-s          #+#    #+#             */
/*   Updated: 2021/09/27 15:21:15 by slucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap_op(t_stack **stack)
{
	t_stack	*first;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	first->next = (*stack)->next;
	(*stack)->next = first;
}

void	swap(t_stack_id stack_id, t_data *data)
{
	if (stack_id == A_STACK)
	{
		swap_op(&data->stack_a);
		write_op("sa\n");
	}
	else if (stack_id == B_STACK)
	{
		swap_op(&data->stack_b);
		write_op("sb\n");
	}
	else if (stack_id == BOTH)
	{
		swap_op(&data->stack_a);
		swap_op(&data->stack_b);
		write_op("ss\n");
	}
}

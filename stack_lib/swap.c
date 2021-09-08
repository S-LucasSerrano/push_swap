/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas-s <slucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 13:08:29 by slucas-s          #+#    #+#             */
/*   Updated: 2021/09/06 14:06:13 by slucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*first;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	first->next = (*stack)->next;
	(*stack)->next = first;
}

/* Swap the first 2 elements at the top of stack A. */
void	sa(t_data *data)
{
	swap(&data->stack_a);
	write_op("sa\n");
}

/* Swap the first 2 elements at the top of stack B. */
void	sb(t_data *data)
{
	swap(&data->stack_b);
	write_op("sb\n");
}

/* Swap the first 2 elements at the top of the two stacks. */
void	ss(t_data *data)
{
	swap(&data->stack_a);
	swap(&data->stack_b);
	write_op("ss\n");
}

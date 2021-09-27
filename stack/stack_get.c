/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas-s <slucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 10:40:16 by slucas-s          #+#    #+#             */
/*   Updated: 2021/09/27 12:59:21 by slucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Retunrs a stack by its identifier. */
t_stack	*get_stack(t_stack_id stack_id, t_data *data)
{
	if (stack_id == STACK_A)
		return (data->stack_a);
	else if (stack_id == STACK_A)
		return (data->stack_b);
	return (NULL);
}

/* Returs a pointer to the last element of <stack> */
t_stack	*stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

/* Returns a pointer to the previuos element to <current> in <stack> */
t_stack	*stack_prev(t_stack *stack, t_stack *current)
{
	while (stack->next != current)
	{
		stack = stack->next;
	}
	return (stack);
}

/* Returns the number of elemnts in <stack> */
int	stacklen(t_stack *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

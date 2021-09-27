/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas-s <slucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 14:58:11 by slucas-s          #+#    #+#             */
/*   Updated: 2021/09/27 15:31:39 by slucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

/* Returns the node of <stack> with the bigger num. */
t_stack	*stack_bigger(t_stack *stack)
{
	t_stack	*bigger;

	bigger = stack;
	while (stack)
	{
		if (stack->num > bigger->num)
			bigger = stack;
		stack = stack->next;
	}
	return (bigger);
}

/* Returns the node of <stack> with the smaller num. */
t_stack	*stack_smaller(t_stack *stack)
{
	t_stack	*smaller;

	smaller = stack;
	while (stack)
	{
		if (stack->num < smaller->num)
			smaller = stack;
		stack = stack->next;
	}
	return (smaller);
}

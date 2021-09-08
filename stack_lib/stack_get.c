/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas-s <slucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 10:40:16 by slucas-s          #+#    #+#             */
/*   Updated: 2021/09/07 16:29:01 by slucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/* Returs a pointer to the last element of <stack> */
t_stack	*stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*stack_prev(t_stack *stack, t_stack *current)
{
	while (stack->next != current)
	{
		stack = stack->next;
	}
	return (stack);
}

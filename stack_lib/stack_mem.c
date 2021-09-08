/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas-s <slucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 10:40:19 by slucas-s          #+#    #+#             */
/*   Updated: 2021/09/06 12:18:43 by slucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/* Creates -with malloc- a new element of the
stack with the <num> and next = NULL */
t_stack	*stack_new(int num)
{
	t_stack	*output;

	output = (t_stack *)malloc(sizeof(t_stack));
	if (!output)
		return (NULL);
	output->num = num;
	output->next = NULL;
	return (output);
}

/* Adds <new> at the end of <stack> */
void	stack_addback(t_stack **stack, t_stack *new)
{
	if (*stack)
		(stack_last(*stack))->next = new;
	else
		*stack = new;
}

/* Frees <stack> */
void	free_stack(t_stack **stack)
{
	if (stack == NULL)
		return ;
	while (*stack)
	{
		free(*stack);
		*stack = (*stack)->next;
	}
}

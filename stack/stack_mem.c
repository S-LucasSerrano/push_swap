/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas-s <slucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 10:40:19 by slucas-s          #+#    #+#             */
/*   Updated: 2021/09/29 15:27:14 by slucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Creates -with malloc- a new element of the
stack with the passed num, index -1 and next = NULL */
t_stack	*stack_new(int num)
{
	t_stack	*output;

	output = (t_stack *)malloc(sizeof(t_stack));
	if (!output)
		return (NULL);
	output->num = num;
	output->index = -1;
	output->next = NULL;
	output->prev = NULL;
	return (output);
}

/* 	Adds <new> at the end of <stack>.
 *	Returning FALSE if the new number is already in the stack. */
t_bool	stack_addback(t_stack **stack, t_stack *new)
{
	t_stack	*current;	

	if (!*stack)
	{
		*stack = new;
		return (TRUE);
	}	
	current = *stack;
	while (TRUE)
	{
		if (current->num == new->num)
			return (FALSE);
		if (!current->next)
			break ;
		current = current->next;
	}
	current->next = new;
	new->prev = current;
	return (TRUE);
}

/* Frees <stack> and returns 0. */
int	free_stack(t_stack **stack)
{
	if (stack == NULL)
		return (0);
	while (*stack)
	{
		free(*stack);
		*stack = (*stack)->next;
	}
	return (0);
}

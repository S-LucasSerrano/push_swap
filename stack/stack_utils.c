/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas-s <slucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 10:40:16 by slucas-s          #+#    #+#             */
/*   Updated: 2021/09/30 13:28:45 by slucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Retunrs a stack by its identifier. */
t_stack	*get_stack(t_stack_id stack_id, t_data *data)
{
	if (stack_id == A_STACK)
		return (data->stack_a);
	else if (stack_id == B_STACK)
		return (data->stack_b);
	return (NULL);
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

/* Returns TRUE if <stack> is sorted. */
t_bool	is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (FALSE);
		stack = stack->next;
	}
	return (TRUE);
}

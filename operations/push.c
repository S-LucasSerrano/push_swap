/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas-s <slucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 13:50:14 by slucas-s          #+#    #+#             */
/*   Updated: 2021/09/29 13:11:36 by slucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_op(t_stack **from, t_stack **to)
{
	t_stack	*first;

	first = *from;
	if (first->next)
		first->next->prev = NULL;
	*from = first->next;
	first->next = *to;
	if (first->next)
		first->next->prev = first;
	*to = first;
}

/* Push the first element of one stack on top of the other. */
void	push(t_stack_id stack_id, t_data *data)
{
	if (stack_id == A_STACK)
	{
		if (!data->stack_b)
			return ;
		push_op(&data->stack_b, &data->stack_a);
		write_op("pa\n");
	}
	else if (stack_id == B_STACK)
	{
		if (!data->stack_a)
			return ;
		push_op(&data->stack_a, &data->stack_b);
		write_op("pb\n");
	}
}

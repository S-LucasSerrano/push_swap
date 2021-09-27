/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_on.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas-s <slucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:22:19 by slucas-s          #+#    #+#             */
/*   Updated: 2021/09/27 13:29:24 by slucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* 	Brings <node> to the bottom of <stack>. */
void	put_on_bottom(t_stack *node, t_stack_id stack_id, t_data *data)
{
	t_stack	*stack;
	int		pos;
	int		len;

	stack = get_stack(stack_id, data);
	pos = 0;
	len = stacklen(stack);
	while (stack)
	{
		if (node == stack)
		{
			if (pos < len / 2)
				repeat_op(rotate, pos + 1, stack_id, data);
			else
				repeat_op(r_rotate, len - pos - 1, stack_id, data);
		}
		pos++;
		stack = stack->next;
	}
}

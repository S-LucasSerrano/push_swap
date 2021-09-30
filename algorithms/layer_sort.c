/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layer_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas-s <slucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 15:45:13 by slucas-s          #+#    #+#             */
/*   Updated: 2021/09/30 16:37:19 by slucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Find the first node of <stack> with an index smaller than <chunk>.
 * Returning the amount of steps needed to put it on top with rotate. */
int	find_top_node(t_stack *stack, int chunk)
{
	int	steps;

	steps = 0;
	while (stack)
	{
		if (stack->index <= chunk)
			return (steps);
		steps += 1;
		stack = stack->next;
	}
	return (0);
}

/* Find the last node of <stack> with an index smaller than <chunk>.
 * Returning the amount of steps needed to put it on top with r_rotate. */
int	find_bot_node(t_stack *stack, int chunk)
{
	int	steps;

	stack = stack_last(stack);
	steps = 1;
	while (stack)
	{
		if (stack->index <= chunk)
			return (steps);
		steps += 1;
		stack = stack->prev;
	}
	return (0);
}

/* Return the numbers to stack A from big to small. */
void	return_to_a(t_data *data)
{
	while (data->stack_b)
	{
		put_on_top(stack_bigger(data->stack_b), B_STACK, data);
		push(A_STACK, data);
	}
}

/* Sort the numbers using the layer sort algorithm. */
void	layer_sort(t_data *data, int chunk_size)
{
	int		steps[2];
	int		current_chuck;
	int		count;

	current_chuck = chunk_size;
	count = 0;
	while (data->stack_a)
	{
		steps[0] = find_top_node(data->stack_a, current_chuck);
		steps[1] = find_bot_node(data->stack_a, current_chuck);
		if (steps[0] <= steps[1])
			repeat_op(rotate, steps[0], A_STACK, data);
		else
			repeat_op(r_rotate, steps[1], A_STACK, data);
		push(B_STACK, data);
		put_on_top(stack_bigger(data->stack_b), B_STACK, data);
		count++;
		if (count > current_chuck)
			current_chuck += chunk_size;
	}
	return_to_a(data);
}

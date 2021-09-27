/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas-s <slucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 15:44:59 by slucas-s          #+#    #+#             */
/*   Updated: 2021/09/27 16:17:48 by slucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Sort a stack of two numbers */
void	sort_two(t_stack_id stack_id, t_data *data)
{
	t_stack	*stack;

	stack = get_stack(stack_id, data);
	if (stack->num > stack->next->num)
		swap(stack_id, data);
}

/* Sort a stack of three numbers. */
void	sort_three(t_stack_id stack_id, t_data *data)
{
	t_stack	*stack;

	stack = get_stack(stack_id, data);
	put_on_bottom(stack_bigger(stack), stack_id, data);
	sort_two(stack_id, data);
}

/* Use the insertion sort algorithm to sort the stack A. */
void	insertion_sort(t_data *data)
{
	int	count;

	count = 0;
	while (count < data->count - 3)
	{
		put_on_top(stack_smaller(data->stack_a), A_STACK, data);
		count++;
		if (is_sorted(data->stack_a))
			break ;
		push(B_STACK, data);
	}
	sort_three(A_STACK, data);
	while (count-- > 0)
		push(A_STACK, data);
}

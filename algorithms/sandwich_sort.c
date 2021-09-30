/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sandwich_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas-s <slucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:13:36 by slucas-s          #+#    #+#             */
/*   Updated: 2021/09/30 16:38:06 by slucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Sort the numbers using Kevin's Sandwich® sort algorithm. */
void	sandwich_sort(t_data *data, int chunk_size)
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
		if (data->stack_b->index > current_chuck - chunk_size / 2)
			rotate(B_STACK, data);
		count++;
		if (count > current_chuck)
			current_chuck += chunk_size;
	}
	return_to_a(data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas-s <slucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 15:44:59 by slucas-s          #+#    #+#             */
/*   Updated: 2021/09/27 13:28:43 by slucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Sort the A stack of two numbers */
void	sort_two(t_stack_id stack_id, t_data *data)
{
	t_stack	*stack;

	stack = get_stack(stack_id, data);
	if (stack->num > stack->next->num)
		swap(stack_id, data);
}

/* Sort the A stack of three numbers. */
void	sort_three(t_stack_id stack_id, t_data *data)
{

}

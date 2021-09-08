/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas-s <slucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 13:50:14 by slucas-s          #+#    #+#             */
/*   Updated: 2021/09/06 14:47:31 by slucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_stack **from, t_stack **to)
{
	t_stack	*first;

	if (!(*from))
		return ;
	first = *from;
	*from = first->next;
	first->next = *to;
	*to = first;
}

/* Take the first element at the top of B and put it at the top of A */
void	pa(t_data *data)
{
	push(&data->stack_b, &data->stack_a);
	write_op("pa\n");
}

/* Take the first element at the top of A and put it at the top of B */
void	pb(t_data *data)
{
	push(&data->stack_a, &data->stack_b);
	write_op("pb\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas-s <slucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 15:44:59 by slucas-s          #+#    #+#             */
/*   Updated: 2021/09/24 16:49:15 by slucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Sort a stack of two numbers */
void	sort_two(t_data *data)
{
	if (data->stack_a->num > data->stack_a->next->num)
		sa(data);
}

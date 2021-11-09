/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas-s <slucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 13:16:48 by slucas-s          #+#    #+#             */
/*   Updated: 2021/11/09 13:32:24 by slucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ---------- */
int	main(int argc, char **argv)
{
	t_data	data;

	data.stack_a = init_stack(argc, argv + 1);
	if (!data.stack_a || !asign_indexes(&data))
		return (0);
	if (data.count == 0 || data.count == 1)
		free_stack(&data.stack_a);
	else if (data.count == 2)
		sort_two(A_STACK, &data);
	else if (data.count == 3)
		sort_three(A_STACK, &data);
	else if (data.count <= HUN_CHUNCK)
		insertion_sort(&data);
	else if (data.count <= 250)
		sandwich_sort(&data, HUN_CHUNCK);
	else
		sandwich_sort(&data, FIVEHUN_CHUNCK);
	free_stack(&data.stack_a);
	return (0);
}

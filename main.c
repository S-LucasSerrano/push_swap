/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas-s <slucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 13:16:48 by slucas-s          #+#    #+#             */
/*   Updated: 2021/09/29 15:17:38 by slucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_data data)
{
	printf("\n ----------------- \n");
	printf(" --  A  ---  B  -- \n");
	while (data.stack_a || data.stack_b)
	{
		if (data.stack_a && data.stack_b)
			printf(" -- %3d --- %3d -- \n",
				data.stack_a->num, data.stack_b->num);
		else
		{
			if (!data.stack_b)
				printf(" -- %3d ---   . -- \n", data.stack_a->num);
			if (!data.stack_a)
				printf(" --   . --- %3d -- \n", data.stack_b->num);
		}
		if (data.stack_a)
			data.stack_a = data.stack_a->next;
		if (data.stack_b)
			data.stack_b = data.stack_b->next;
	}
	printf(" ----------------- \n");
}

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
	else
		insertion_sort(&data);
}

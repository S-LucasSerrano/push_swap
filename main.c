/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas-s <slucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 13:16:48 by slucas-s          #+#    #+#             */
/*   Updated: 2021/09/24 15:06:55 by slucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_bool	asign_indexes(t_data *data);

void	print_stacks(t_data data)
{
	printf("\n ----------------- \n");
	printf(" --  A  ---  B  -- \n");
	while (data.stack_a || data.stack_b)
	{
		if (data.stack_a && data.stack_b)
			printf(" -- %3d --- %3d -- \n",
				data.stack_a->index, data.stack_b->index);
		else
		{
			if (!data.stack_b)
				printf(" -- %3d ---   . -- \n", data.stack_a->index);
			if (!data.stack_a)
				printf(" --   . --- %3d -- \n", data.stack_b->index);
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
	print_stacks(data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas-s <slucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 13:16:48 by slucas-s          #+#    #+#             */
/*   Updated: 2021/09/08 13:32:24 by slucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_data data)
{
	printf("\033[0m");
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
	printf(" ----------------- \033[33m\n\n");
}

/* Returns FALSE if the <num> is bigger or smaller than an int */
static t_bool	valid_int(long num)
{
	if (num > INT_MAX || num < INT_MIN)
		return (FALSE);
	return (TRUE);
}

/* Free <stack> and print <message> in red. Returning NULL. */
static void	*stack_error(t_stack **stack, char *message)
{
	free_stack(stack);
	return (null_error("Error\n"));
}

/*	Returns a t_stack of all nums in <argv>
*	if the program arguments are valid:
*		- There is at leats 1 param.
*		- All of them are valid numeric charcters */
static t_stack	*init_stack(int argc, char **argv)
{
	t_stack	*stack;
	int		i;

	if (argc < 2)
		return (null_error("Error\n"));
	argv += 1;
	stack = NULL;
	while (*argv)
	{				
		i = 0;
		if (!valid_int(ft_atoi(*argv)))
			return (stack_error(&stack, "Error\n"));
		while (argv[0][i] != '\0')
		{
			if ((!ft_isdigit(argv[0][i]) && argv[0][i] != '-')
				|| (argv[0][i] == '-' && i > 0))
				return (stack_error(&stack, "Error\n"));
			i++;
		}
		stack_addback(&stack, stack_new(ft_atoi(*argv)));
		argv += 1;
	}
	return (stack);
}

/* ---------- */
int	main(int argc, char **argv)
{
	t_data	data;

	//printf("%s \n", argv[1]);

	data.stack_a = init_stack(argc, argv);
	if (!data.stack_a)
		return (0);
	print_stack(data);
	pb(&data);
	print_stack(data);
	printf("\033[33m      - Succesesfull end of main - \033[0m\n");
}

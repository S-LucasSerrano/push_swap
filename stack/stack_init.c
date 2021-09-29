/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas-s <slucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:56:42 by slucas-s          #+#    #+#             */
/*   Updated: 2021/09/29 15:12:33 by slucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

/* Returns a stack of the numbers in argv (char **). */
static t_stack	*multi_param_stack(char **argv)
{
	t_stack	*stack;
	int		i;

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
		if (!stack_addback(&stack, stack_new(ft_atoi(*argv))))
			return (stack_error(&stack, "Error\n"));
		argv += 1;
	}
	return (stack);
}

/* Returns a stack of the numbers in argv[0] (char *). */
static t_stack	*one_param_stack(char **argv)
{
	t_stack	*stack;

	argv = ft_split(*argv, ' ');
	stack = multi_param_stack(argv);
	ft_free_table((void ***)&argv);
	return (stack);
}

/*	Returns a t_stack of all nums in <argv>
	or all nums in argv[0] if there is only one parameter. */
t_stack	*init_stack(int argc, char **argv)
{
	if (argc < 2)
		return (null_error("Error\n"));
	else if (argc == 2)
		return (one_param_stack(argv));
	return (multi_param_stack(argv));
}

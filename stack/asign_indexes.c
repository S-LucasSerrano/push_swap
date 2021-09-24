/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asign_indexes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas-s <slucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 11:25:20 by slucas-s          #+#    #+#             */
/*   Updated: 2021/09/24 15:27:17 by slucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Makes <list> have the same numbers as <stack>.
*	List is consider to already be able to fit all the numbers. */
static void	fill_list(int *list, t_stack *stack)
{
	t_stack	*current;
	int		i;

	current = stack;
	i = 0;
	while (current)
	{
		list[i++] = current->num;
		current = current->next;
	}
}

/* Orders the numbers of <list>, that has <len> size. */
static void	sort_list(int *list, int len)
{
	int	total_i;
	int	parcial_i;
	int	num;
	int	shorter_i;			

	total_i = 0;
	while (total_i < len)
	{
		shorter_i = total_i;
		parcial_i = total_i + 1;
		num = list[total_i];
		while (parcial_i < len)
		{
			if (list[parcial_i] < num)
			{
				num = list[parcial_i];
				shorter_i = parcial_i;
			}
			parcial_i++;
		}
		num = list[total_i];
		list[total_i] = list[shorter_i];
		list[shorter_i] = num;
		total_i++;
	}
}

static void	get_indexes(int *list, t_data *data)
{
	t_stack	*current;
	int		i;

	current = data->stack_a;
	while (current)
	{
		i = 0;
		while (i < data->count)
		{
			if (list[i] == current->num)
			{
				current->index = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
}

/* Asign the indexes to the elements of stack a.
*	Returning -1 if there was a problem during the process. */
t_bool	asign_indexes(t_data *data)
{
	int		*list;

	list = ft_calloc(data->count, sizeof(int));
	if (!list)
		return (FALSE);
	fill_list(list, data->stack_a);
	data->count = stacklen(data->stack_a);
	sort_list(list, data->count);
	get_indexes(list, data);
	free(list);
	return (TRUE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas-s <slucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 10:16:25 by slucas-s          #+#    #+#             */
/*   Updated: 2021/09/24 12:10:53 by slucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>

/*	Struct for the nodes of the list.
*	With the number, and the index that this node
*	will ocupy when the list is shorted. */
typedef struct s_node
{
	int				num;
	int				index;
	struct s_node	*next;
}	t_stack;

t_stack	*init_stack(int argc, char **argv);

t_stack	*stack_new(int num);
void	stack_addback(t_stack **stack, t_stack *new);
void	free_stack(t_stack **stack);

t_stack	*stack_last(t_stack *stack);
t_stack	*stack_prev(t_stack *stack, t_stack *current);
int		stacklen(t_stack *stack);

#endif

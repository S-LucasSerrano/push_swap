/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas-s <slucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 10:16:25 by slucas-s          #+#    #+#             */
/*   Updated: 2021/09/07 17:15:28 by slucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>

typedef struct s_node
{
	int				num;
	struct s_node	*next;
}	t_stack;

t_stack	*stack_new(int num);
void	stack_addback(t_stack **stack, t_stack *new);
void	free_stack(t_stack **stack);

t_stack	*stack_last(t_stack *stack);
t_stack	*stack_prev(t_stack *stack, t_stack *current);

#endif

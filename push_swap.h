/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas-s <slucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 13:16:52 by slucas-s          #+#    #+#             */
/*   Updated: 2021/09/27 13:24:57 by slucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

/* Boolean value than can be TRUE or FALSE. */
typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

/*	Struct for the nodes of the list.
*	With the number, and the index that this node
*	will ocupy when the list is shorted. */
typedef struct s_node
{
	int				num;
	int				index;
	struct s_node	*next;
}	t_stack;

/*	Struct with two stacks and the amunt of numbers to sort. */
typedef struct s_data
{
	int		count;
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_data;

/* Flags identifing the two stacks. */
typedef enum e_stack_id
{
	STACK_A = 'A',
	STACK_B = 'B',
	BOTH = 'A' + 'B'
}	t_stack_id;

// --- ERROR

int		error(char *message);
void	*null_error(char *message);

// --- STACK

t_stack	*init_stack(int argc, char **argv);

t_stack	*get_stack(t_stack_id stack_id, t_data *data);
t_stack	*stack_new(int num);
void	stack_addback(t_stack **stack, t_stack *new);
int		free_stack(t_stack **stack);

t_stack	*stack_last(t_stack *stack);
t_stack	*stack_prev(t_stack *stack, t_stack *current);
int		stacklen(t_stack *stack);

// --- OPERATIONS

void	write_op(char *text);

void	swap(t_stack_id stack_id, t_data *data);
void	push(t_stack_id stack_id, t_data *data);
void	rotate(t_stack_id stack_id, t_data *data);
void	r_rotate(t_stack_id stack_id, t_data *data);

void	repeat_op(void (*op)(t_stack_id, t_data *),
			int x, t_stack_id id, t_data *data);

void	put_on_bottom(t_stack *node, t_stack_id stack_id, t_data *data);

// --- ALGORITHMS

void	sort_two(t_stack_id stack_id, t_data *data);

#endif
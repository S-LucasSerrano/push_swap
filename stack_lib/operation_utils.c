/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas-s <slucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 13:53:49 by slucas-s          #+#    #+#             */
/*   Updated: 2021/09/07 17:32:11 by slucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Writes <text> in yellow. */
void	write_op(char *text)
{
	write(1, text, ft_strlen(text));
}

/* Repeats a given operation <x> times. */
void	repeat_op(void (*op)(t_data *), int x, t_data *data)
{
	while(x--)
	{
		op(data);
	}
}

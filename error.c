/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas-s <slucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 17:17:31 by slucas-s          #+#    #+#             */
/*   Updated: 2021/08/31 17:17:32 by slucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

/* Prints <message> in red and returns FALSE */
int	error(char *message)
{
	if (1)
	{
		write(0, "\033[31m   ", 8);
		write(0, message, ft_strlen(message));
		write(0, "\033[0m", 4);
	}
	return (FALSE);
}

/* Prints <message> in red and returns NULL */
void	*null_error(char *message)
{
	error(message);
	return (NULL);
}

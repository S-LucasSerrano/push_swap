/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas-s <slucas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 10:40:26 by slucas-s          #+#    #+#             */
/*   Updated: 2021/09/06 10:40:26 by slucas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_lst.h"
#include <stdlib.h>

/* Creates -with malloc- a new element of the list
with content = <con> and next = NULL */
t_list	*ft_lstnew(void *con)
{
	t_list	*output;

	output = (t_list *)malloc(sizeof(t_list));
	if (!output)
		return (NULL);
	output->content = con;
	output->next = NULL;
	return (output);
}

/* Adds <new> at the end of <lst> */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst)
		(ft_lstlast(*lst))->next = new;
	else
		*lst = new;
}

/* Sets the element pointed by <new> as the 
first element of the list pointed by <lst> */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

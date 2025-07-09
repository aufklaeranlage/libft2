/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listnew.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronner <abronner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:15:48 by abronner          #+#    #+#             */
/*   Updated: 2025/07/09 12:32:47 by abronner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

#include <stdlib.h>

//	Allocates memory using malloc(3) and returns a new node. The ’content’
//	member variable is initialized with the given parameter ’content’. The
//	variable ’next’ is initialized to NULL.
//	Returns the new node on success and NULL if the allocation fails.

t_list	*ft_lstnew(void *content)
{
	t_list	*ret;

	ret = malloc(sizeof(*ret));
	if (!ret)
		return (NULL);
	ret->content = content;
	ret->next = NULL;
	return (ret);
}

//	Adds the node ’new’ at the beginning of the list pointed to by 'lst'.

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
	return ;
}

//	Adds the node 'new' to the end of the list pointed to by 'lst'.

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	last = ft_lstlast(*lst);
	if (!last)
		*lst = new;
	else
		last->next = new;
	return ;
}

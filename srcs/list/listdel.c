/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listdel.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronner <abronner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:33:59 by abronner          #+#    #+#             */
/*   Updated: 2025/07/09 12:40:33 by abronner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

#include <stdlib.h>

//	Takes a node as parameter 'lst' and frees its content using the function
//	'del'. Then frees the node itself but not the next node. does not connect
//	nodes.
//	Protects against a NULL node but not against a NULL del function.

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	(*del)(lst->content);
	free(lst);
	return ;
}

//	Deletes and frees the given node and all its successors, using the function
//	’del’ and free(3). Finally, set the pointer to the list to NULL.

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*next;

	if (!lst || !*lst)
		return ;
	node = *lst;
	while (node)
	{
		next = node->next;
		ft_lstdelone(node, del);
		node = next;
	}
	*lst = NULL;
	return ;
}

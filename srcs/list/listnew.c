/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listnew.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronner <abronner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:15:48 by abronner          #+#    #+#             */
/*   Updated: 2025/07/09 12:19:17 by abronner         ###   ########.fr       */
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

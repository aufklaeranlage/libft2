/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronner <abronner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:13:20 by abronner          #+#    #+#             */
/*   Updated: 2025/07/09 12:41:26 by abronner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

//	content:	Data in the node.
//	next:		Pointer to the next node, if this is the last node is NULL.

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

//	LIST NEW & ADD

t_list	*ft_lstnew(void *content);

void	ft_lstadd_front(t_list **lst, t_list *new);

void	ft_lstadd_back(t_list **lst, t_list *new);

//	LIST UTILS

int		ft_lstsize(t_list *lst);

t_list	*ft_lstlast(t_list *lst);

//	LIST DELETE

void	ft_lstdelone(t_list *lst, void (*del)(void *));

void	ft_lstclear(t_list **lst, void (*del)(void *));

#endif

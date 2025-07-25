/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronner <abronner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 19:57:24 by abronner          #+#    #+#             */
/*   Updated: 2025/07/25 20:08:24 by abronner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "stack.h"

static t_stack_node	*new_stack_node(void *data)
{
	t_stack_node	*ret;
	
	ret = malloc(sizeof(*ret));
	if (ret)
		ret->data = data;
	return (ret);
}

static int	push(t_stack *stack, void *data)
{
	t_stack_node	*new;

	new = new_stack_node(data);
	if (!new)
		return (-1);
	if (stack->top)
		new->next = stack->top;
	stack->top = new;
	++stack->size;
	return (0);
}

static void	*pop(t_stack *stack)
{
	void			*ret;
	t_stack_node	*del;

	if (stack->size == 0)
		return (NULL);
	del = stack->top;
	ret = del->data;
	stack->top = del->next;
	free(del);
	--stack->size;
	return (ret);
}

void	init_stack(t_stack *stack)
{
	if (!stack)
		return ;
	stack->top = NULL;
	stack->size = 0;
	stack->push = &push;
	stack->pop = &pop;
}

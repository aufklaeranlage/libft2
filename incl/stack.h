/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronner <abronner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 19:53:33 by abronner          #+#    #+#             */
/*   Updated: 2025/07/25 20:05:26 by abronner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct s_stack_node	t_stack_node;

struct	s_stack_node
{
	void			*data;
	t_stack_node	*next;
};

typedef struct s_stack	t_stack;

struct s_stack
{
	t_stack_node	*top;
	int				size;

	int		(*push)(t_stack *, void *);
	void	*(*pop)(t_stack *);
};

void	init_stack(t_stack *stack);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronner <abronner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 09:36:34 by abronner          #+#    #+#             */
/*   Updated: 2025/09/17 09:42:32 by abronner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GNL_H
# define FT_GNL_H

# include <stddef.h>

# ifndef MAXFDS
#  define MAXFDS 64
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

typedef struct s_gnlstr
{
	char	*str;
	size_t	size;
}	t_gnlstr;

char	*get_next_line(int fd);

#endif

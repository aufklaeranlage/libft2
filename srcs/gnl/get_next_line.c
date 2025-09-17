/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronner <abronner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 09:37:27 by abronner          #+#    #+#             */
/*   Updated: 2025/09/17 09:44:12 by abronner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gnl.h"
#include "ft_list.h"
#include "ft_string.h"

#include <unistd.h>

static char	*read_to_out(t_queue *q, int fd, size_t tsize);

static char	*init_out(size_t size, size_t tsize);

static int	store_remainder(t_queue *q, char *str, size_t size);

char	*get_next_line(int fd)
{
	static t_queue	remain[MAXFDS];
	char			testbuf;
	char			*out;
	size_t			size;

	if (fd < 0 || fd >= MAXFDS)
		return (NULL);
	if (read(fd, &testbuf, 0) == -1)
		return (queue_clear(remain + fd, free), NULL);
	size = 0;
	if (remain[fd].front)
		size = ((t_gnlstr *)remain[fd].front->content)->size;
	if (size && ((t_gnlstr *)remain[fd].front->content)->str[size - 1] == '\n')
		out = init_out(size + 1, 0);
	else
		out = read_to_out(remain + fd, fd, size);
	if ((remain + fd)->front)
		ft_strncpy(out, ((t_gnlstr *)remain[fd].front->content)->str, size);
	if (size)
		free(((t_gnlstr *)dequeue(remain + fd))->str);
	return (out);
}

static char	*read_to_out(t_queue *q, int fd, size_t tsize)
{
	char	*out;
	char	buf[BUFFER_SIZE + 1];
	ssize_t	size;
	char	*tmp;

	size = read(fd, buf, BUFFER_SIZE);
	if (size <= 0)
		return (init_out(size, tsize));
	buf[size] = '\0';
	tmp = ft_strchr(buf, '\n');
	if (tmp)
	{
		if (store_remainder(q, tmp + 1, size - (tmp - buf) - 1))
			return (NULL);
		size = tmp - buf + 1;
		out = init_out(size, tsize);
	}
	else
		out = read_to_out(q, fd, tsize + size);
	if (!out)
		return (queue_clear(q, free), NULL);
	ft_strncpy(out + tsize, buf, size);
	return (out);
}

static char	*init_out(size_t size, size_t tsize)
{
	char	*out;

	if (tsize + size == 0)
		return (NULL);
	out = malloc((tsize + size + 1) * sizeof(*out));
	if (!out)
		return (NULL);
	out[tsize + size] = '\0';
	return (out);
}

static int	store_remainder(t_queue *q, char *str, size_t size)
{
	t_gnlstr	content;
	t_node		*node;
	char		*check;

	if (size == 0)
		return (0);
	check = ft_strchr(str, '\n');
	if (!check)
		check = str + size;
	else
		++check;
	content.str = ft_substr(str, 0, check - str);
	if (!content.str)
		return (queue_clear(q, free), 1);
	content.size = check - str;
	node = ft_nodenew(&content);
	if (!node)
		return (queue_clear(q, free), free(content.str), 2);
	enqueue(q, node);
	if (*(check - 1) == '\n' && size - (check - str))
		return (store_remainder(q, check, size - (check - str)));
	return (0);
}

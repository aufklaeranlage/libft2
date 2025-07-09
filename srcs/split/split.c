/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronner <abronner@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:05:40 by abronner          #+#    #+#             */
/*   Updated: 2025/07/08 19:35:55 by abronner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_split.h"
#include "ft_string.h"

static char	**ft_splitrec(const char *s, char c, size_t depth);

static char	**ft_splitinit(size_t depth);

//	Allocates memory using malloc(3) and returns an array of strings obtained by
//	splitting 's' using the character 'c' as a delimiter. The array ends with a
//	NULL pointer.
//	Returns the array of strings on success and NULL if the allocation fails.

char	**ft_split(const char *s, char c)
{
	if (!s)
		return (NULL);
	return (ft_splitrec(s, c, 0));
}

static char	**ft_splitrec(const char *s, char c, size_t depth)
{
	char	**ret;
	char	*substr;
	size_t	start;
	size_t	len;

	start = 0;
	while (s[start] && s[start] == c)
		++start;
	len = 0;
	while (s[start + len] && s[start + len] != c)
		++len;
	if (!len)
		return (ft_splitinit(depth));
	substr = ft_strndup(s + start, len);
	if (!substr)
		return (NULL);
	ret = ft_splitrec(s + start + len, c, depth + 1);
	if (!ret)
		return (free(substr), NULL);
	ret[depth] = substr;
	return (ret);
}

static char	**ft_splitinit(size_t depth)
{
	char	**ret;

	ret = malloc((depth + 1) * sizeof(*ret));
	if (ret)
		ret[depth] = NULL;
	return (ret);
}

//	Frees the with malloc(3) allocated strings inside an array of strings but
//	leaves the pointer to the string array intact.

void	ft_splitclear(char **split)
{
	size_t	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
		free(split[i++]);
}

//	Frees the with malloc(3) allocated strings inside an array of strings and
//	the pointer to the string array.

void	ft_splitfree(char **split)
{
	size_t	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
		free(split[i++]);
}

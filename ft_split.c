/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 23:09:52 by zech-chi          #+#    #+#             */
/*   Updated: 2023/12/18 23:23:59 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char const *s, char c)
{
	size_t	i;
	int		counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			counter++;
		i++;
	}
	return (counter);
}

static void	free_ptr(char **ptr, size_t size)
{
	size_t	col;

	col = 0;
	while (col < size)
		free(ptr[col++]);
	free(ptr);
}

static int	get_left_right(size_t *left, size_t *right, char const *s, char c)
{
	while (s[*left] && s[*left] == c)
		*left = *left + 1;
	if (s[*left] == 0)
		return (0);
	*right = *left;
	while (s[*right] && s[*right] != c)
		*right = *right + 1;
	return (1);
}

static char	**fill_ptr(char **ptr, char const *s, char c)
{
	size_t	left;
	size_t	right;
	size_t	row;
	size_t	col;

	left = 0;
	row = 0;
	while (s[left])
	{
		if (get_left_right(&left, &right, s, c) == 0)
			break ;
		ptr[row] = malloc(right - left + 1);
		if (ptr[row] == NULL)
		{
			free_ptr(ptr, row);
			return (NULL);
		}
		col = 0;
		while (left < right)
			ptr[row][col++] = s[left++];
		ptr[row][col] = 0;
		row++;
	}
	ptr[row] = 0;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	size_t	size;
	char	**ptr;

	if (!s)
		return (NULL);
	size = count_words(s, c);
	ptr = malloc((size + 1) * sizeof(char *));
	if (ptr == NULL)
		return (NULL);
	return (fill_ptr(ptr, s, c));
}

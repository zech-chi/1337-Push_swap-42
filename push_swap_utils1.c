/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 10:37:49 by zech-chi          #+#    #+#             */
/*   Updated: 2023/12/29 23:35:37 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstrnl_fd(char *s, int fd)
{
	int	i;

	if (!s || fd < 0)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int	ft_atoi_plus(char *str, int *something_wrong)
{
	long long	res;
	int			signe;
	int			i;

	i = 0;
	signe = 1 - 2 * (str[i] == '-');
	i = i + 1 * (str[i] == '-' || str[i] == '+');
	if (!str[i])
		return (*something_wrong = 1, 0);
	res = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		res = res * 10 + str[i++] - '0';
		if (signe * res < -2147483648 || res * signe > 2147483647)
			return (*something_wrong = 1, 0);
	}
	return (*something_wrong = 1 * (str[i] != '\0'), signe * res);
}

int	ft_is_valid_input(int ac, char **av, t_stack *stack_a)
{
	char	**res;
	int		something_wrong;
	int	row;
	int	size;
	int		val;

	while (--ac > 0)
	{
		res = ft_split(av[ac], ' ');
		if (!res || !(*res))
			return (0);
		row = 0;
		while (res[row])
			row++;
		size = row;
		while (--row >= 0)
		{
			val = ft_atoi_plus(res[row], &something_wrong);
			if (something_wrong || ft_is_already_in_stack(*stack_a, val)
				|| !ft_push(stack_a, val))
				return (free_ptr(res, size), 0);
		}
		free_ptr(res, size);
	}
	return (1);
}

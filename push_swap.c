/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:02:38 by zech-chi          #+#    #+#             */
/*   Updated: 2023/12/19 22:29:45 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_plus(char *str, int *something_wrong)
{
	long long	res;
	int	signe;
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	signe = 1 - 2 * (str[i] == '-');
	i = i + 1 * (str[i] == '-' || str[i] == '+');
	if (!str[i])
		return (*something_wrong = 1, 0);
	res = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		res = res * 10 + str[i++] - '0';
		if (res < -2147483648 || res > 2147483647)
			return (*something_wrong = 1, 0);
	}
	return (*something_wrong = 1 * (str[i] != '\0'), signe * res);
}

void	ft_applay(char *str, t_stack **top_a, t_stack **tail_a, t_stack **top_b, t_stack **tail_b)
{
	if (!ft_strcmp(str, "sa"))
		ft_swap_rule(top_a, tail_a);
	else if (!ft_strcmp(str, "sb"))
		ft_swap_rule(top_b, tail_b);
	else if (!ft_strcmp(str, "ra"))
		ft_rotate_rule(top_a, tail_a);
	else if (!ft_strcmp(str, "rb"))
		ft_rotate_rule(top_b, tail_b);
	else if (!ft_strcmp(str, "rra"))
		ft_reverse_rotate_rule(top_a, tail_a);
	else if (!ft_strcmp(str, "rrb"))
		ft_reverse_rotate_rule(top_b, tail_b);
	else if (!ft_strcmp(str, "pa"))
		ft_push_rule(top_b, tail_b, top_a, tail_a);
	else if (!ft_strcmp(str, "pb"))
		ft_push_rule(top_a, tail_a, top_b, tail_b);
}


int	main(int ac, char **av)
{
	int	somethig_wrong;
	int	i;
	int	r;
	char **res;
	int k;

	ac = 0;
	i = 1;
	while (av[i])
	{
		res = ft_split(av[i], ' ');
		r = 0;
		while (res[r])
		{
			k = ft_atoi_plus(res[r], &somethig_wrong);
			if (somethig_wrong)
				return (ft_putstr_fd("ERROR!\n", 2), 0);
			r++;
		}	
		i++;
	}
	somethig_wrong = 0;
	ft_putstr_fd("Yes\n", 1);
	return (0);
}

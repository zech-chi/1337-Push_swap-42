/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:02:38 by zech-chi          #+#    #+#             */
/*   Updated: 2023/12/18 23:30:26 by zech-chi         ###   ########.fr       */
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

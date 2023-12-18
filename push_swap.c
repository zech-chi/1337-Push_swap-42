/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:02:38 by zech-chi          #+#    #+#             */
/*   Updated: 2023/12/18 09:31:16 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_plus(char *str, int *something_wrong)
{
	long long	res;
	int	signe;
	int	i;

	i = 0;
	signe = 1;
	res = 0;
	while (str[i] == ' ')
		i++;
	signe = 1 - 2 * (str[i] == '-');
	i = i + 1 * (str[i] == '-' || str[i] == '+');
	if (!str[i])
		return (*something_wrong = 1, 0);
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

	somethig_wrong = 0;
	
	
}
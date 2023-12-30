/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:19:04 by zech-chi          #+#    #+#             */
/*   Updated: 2023/12/30 19:19:03 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (ac == 1)
		return (0);
	stack_a = (t_stack){NULL, NULL, 0, 0, -2147483648, 2147483647};
	stack_b = (t_stack){NULL, NULL, 0, 0, -2147483648, 2147483647};
	if (!ft_is_valid_input(ac, av, &stack_a))
	{
		ft_putstrnl_fd("Error", 2);
		return (ft_stack_clear(&stack_a), 0);
	}
	if (!ft_stack_is_sorted(stack_a))
	{
		if (stack_a.len == 3)
			ft_sort_3(&stack_a);
		else if (stack_a.len == 4 || stack_a.len == 5)
			ft_sort_5(&stack_a, &stack_b);
		else
		{
			ft_from_a_to_b(&stack_a, &stack_b);
			ft_from_b_to_a(&stack_a, &stack_b);
		}
	}
	return (ft_stack_clear(&stack_a), 0);
}

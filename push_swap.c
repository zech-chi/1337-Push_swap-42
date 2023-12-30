/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:19:04 by zech-chi          #+#    #+#             */
/*   Updated: 2023/12/30 16:08:58 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_stack_clear(t_stack *stack)
{
	t_node	*cur_node;
	t_node	*nxt_node;

	if (!stack || !(stack->top))
		return ;
	cur_node = stack->top;
	while (cur_node)
	{
		nxt_node = cur_node->down;
		free(cur_node);
		cur_node = nxt_node;
	}
	stack->top = NULL;
}

void	ft_free_res(char **res)
{
	int	i;

	if (!res)
		return ;
	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
}

void	ft_sort_5(t_stack *stack_a, t_stack *stack_b)
{
	int	index_min;

	while (stack_a->len > 3)
	{
		index_min = ft_get_index_min(*stack_a);
		if (index_min < stack_a->len - index_min)
			ft_applay_ra_rb(stack_a, stack_b, index_min, 0);
		else
			ft_applay_rra_rrb(stack_a, stack_b, stack_a->len - index_min, 0);
		ft_push_rule(stack_a, stack_b);
		ft_putstrnl_fd("pb", 1);
	}
	ft_sort_3(stack_a);
	while (stack_b->len > 0)
	{
		ft_push_rule(stack_b, stack_a);
		ft_putstrnl_fd("pa", 1);
	}
	if (stack_a->top->value > stack_a->top->down->value)
	{
		ft_swap_rule(stack_a);
		ft_putstrnl_fd("sa", 1);
	}
}

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

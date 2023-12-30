/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 19:18:17 by zech-chi          #+#    #+#             */
/*   Updated: 2023/12/30 19:18:58 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:46:32 by zech-chi          #+#    #+#             */
/*   Updated: 2023/12/29 23:15:19 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_index_min(t_stack stack_a)
{
	int		min;
	int		index_min;
	int		index;
	t_node	*node_a;

	index_min = -1;
	index = 0;
	node_a = stack_a.top;
	while (node_a)
	{
		if (index_min == -1 || node_a->value < min)
		{
			index_min = index;
			min = node_a->value;
		}
		node_a = node_a->down;
		index++;
	}
	return (index_min);
}

int	ft_get_min_great(t_stack stack_a, int b)
{
	t_node	*cur_node;
	int		min_great;
	int		min_great_index;
	int		index;

	min_great_index = -1;
	index = 0;
	cur_node = stack_a.top;
	while (cur_node)
	{
		if (cur_node->value > b
			&& (min_great_index == -1 || cur_node->value < min_great))
		{
			min_great = cur_node->value;
			min_great_index = index;
		}
		index++;
		cur_node = cur_node->down;
	}
	return (min_great_index);
}

int	ft_get_cost(t_from_b_to_a *info, t_stack stack_a, t_stack stack_b)
{
	int	min_cost;
	int	cost1;
	int	cost2;
	int	cost3;
	int	cost4;

	info->ra = info->cur_a;
	info->rra = stack_a.len - info->cur_a;
	info->rb = info->cur_b;
	info->rrb = stack_b.len - info->cur_b;
	cost1 = max(info->ra, info->rb);
	cost2 = max(info->rra, info->rrb);
	cost3 = info->rra + info->rb;
	cost4 = info->ra + info->rrb;
	min_cost = cost1;
	min_cost = min(min_cost, cost2);
	min_cost = min(min_cost, cost3);
	min_cost = min(min_cost, cost4);
	if (min_cost == cost1)
		return (info->rra = 0, info->rrb = 0, min_cost);
	else if (min_cost == cost2)
		return (info->ra = 0, info->rb = 0, min_cost);
	else if (min_cost == cost3)
		return (info->ra = 0, info->rrb = 0, min_cost);
	return (info->rra = 0, info->rb = 0, min_cost);
}

void	ft_b_to_a_help(t_stack *stack_a, t_stack *stack_b, t_from_b_to_a *info)
{
	t_node	*node_b;

	info->cur_b = 0;
	info->min_cost = -1;
	node_b = stack_b->top;
	while (node_b)
	{
		info->cur_a = ft_get_min_great(*stack_a, node_b->value);
		if (info->cur_a == -1)
			info->cur_a = ft_get_index_min(*stack_a);
		info->cur_cost = ft_get_cost(info, *stack_a, *stack_b);
		if ((info->min_cost == -1) || info->cur_cost < info->min_cost)
		{
			info->best_a = info->cur_a;
			info->best_b = info->cur_b;
			info->min_cost = info->cur_cost;
			info->best_ra = info->ra;
			info->best_rb = info->rb;
			info->best_rra = info->rra;
			info->best_rrb = info->rrb;
		}
		node_b = node_b->down;
		(info->cur_b)++;
	}
}

void	ft_from_b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	t_from_b_to_a	info;
	int				min_index;

	while (stack_b->len > 0)
	{
		ft_b_to_a_help(stack_a, stack_b, &info);
		ft_applay_ra_rb(stack_a, stack_b, info.best_ra, info.best_rb);
		ft_applay_rra_rrb(stack_a, stack_b, info.best_rra, info.best_rrb);
		ft_push_rule(stack_b, stack_a);
		ft_putstrnl_fd("pa", 1);
	}
	min_index = ft_get_index_min(*stack_a);
	if (min_index < stack_a->len - min_index)
		ft_applay_ra_rb(stack_a, stack_b, min_index, 0);
	else
		ft_applay_rra_rrb(stack_a, stack_b, stack_a->len - min_index, 0);
}

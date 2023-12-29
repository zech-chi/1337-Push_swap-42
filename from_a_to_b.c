/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:08:26 by zech-chi          #+#    #+#             */
/*   Updated: 2023/12/29 23:13:58 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_flag_lis_elements(t_stack *stack)
{
	t_node	*cur_node;
	int		maximus;

	cur_node = stack->top;
	maximus = 1;
	while (cur_node)
	{
		maximus = max(maximus, cur_node->lis);
		cur_node = cur_node->down;
	}
	stack->len_lis = maximus;
	cur_node = stack->top;
	while (maximus > 0)
	{
		if (cur_node->lis == maximus)
		{
			cur_node->in_lis = 1;
			maximus--;
		}
		cur_node = cur_node->down;
	}
}

int	ft_get_max_lis(t_stack stack)
{
	t_node	*node;
	int		max_lis;

	max_lis = 0;
	node = stack.top;
	while (node)
	{
		max_lis = max(max_lis, node->lis);
		node = node->down;
	}
	return (max_lis);
}

int	ft_lis(t_stack *stack)
{
	t_node	*node_i;
	t_node	*node_j;

	node_i = stack->top;
	while (node_i)
	{
		node_i->lis = 1;
		node_i = node_i->down;
	}
	node_i = stack->tail->up;
	while (node_i)
	{
		node_j = node_i->down;
		while (node_j)
		{
			if (node_i->value < node_j->value)
				node_i->lis = max(node_i->lis, node_j->lis + 1);
			node_j = node_j->down;
		}
		node_i = node_i->up;
	}
	return (ft_get_max_lis(*stack));
}

void	ft_applay_best_lis(t_stack *stack_a)
{
	int	ra;
	int	max_lis;
	int	best_ra;
	int	cur_lis;

	max_lis = -1;
	ra = -1;
	while (++ra < stack_a->len)
	{
		cur_lis = ft_lis(stack_a);
		if (cur_lis > max_lis)
		{
			max_lis = cur_lis;
			best_ra = ra;
		}
		ft_rotate_rule(stack_a);
	}
	ra = -1;
	while (++ra < best_ra)
		ft_rotate_rule(stack_a);
	ft_lis(stack_a);
	ft_flag_lis_elements(stack_a);
	ra--;
	while (++ra < stack_a->len)
		ft_rotate_rule(stack_a);
}

void	ft_from_a_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	mid;

	ft_applay_best_lis(stack_a);
	mid = (stack_a->maximus + stack_a->minimus) / 2;
	while (stack_a->len_lis < stack_a->len)
	{
		if (stack_a->top->in_lis)
		{
			ft_rotate_rule(stack_a);
			ft_putstrnl_fd("ra", 1);
		}
		else
		{
			ft_push_rule(stack_a, stack_b);
			ft_putstrnl_fd("pb", 1);
			if (stack_b->top->value >= mid)
			{
				ft_rotate_rule(stack_b);
				ft_putstrnl_fd("rb", 1);
			}
		}
	}
}

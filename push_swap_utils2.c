/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 10:45:59 by zech-chi          #+#    #+#             */
/*   Updated: 2023/12/29 22:46:16 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_stack *stack_a)
{
	int	x;
	int	y;
	int	z;

	x = stack_a->top->value;
	y = stack_a->top->down->value;
	z = stack_a->tail->value;
	if ((y < x && x < z) || (z < y && y < x) || (x < z && z < y))
	{
		ft_swap_rule(stack_a);
		ft_putstrnl_fd("sa", 1);
	}
	if ((y < z && z < x) || (x < z && z < y))
	{
		ft_rotate_rule(stack_a);
		ft_putstrnl_fd("ra", 1);
	}
	if ((z < y && y < x) || (z < x && x < y))
	{
		ft_reverse_rotate_rule(stack_a);
		ft_putstrnl_fd("rra", 1);
	}
}

int	ft_stack_is_sorted(t_stack stack_a)
{
	t_node	*cur_node;

	cur_node = stack_a.top;
	if (!(cur_node) || !(cur_node->down))
		return (1);
	cur_node = cur_node->down;
	while (cur_node)
	{
		if (cur_node->up->value > cur_node->value)
			return (0);
		cur_node = cur_node->down;
	}
	return (1);
}

int	ft_is_already_in_stack(t_stack stack_a, int val)
{
	t_node	*node;

	node = stack_a.top;
	while (node)
	{
		if (node->value == val)
			return (1);
		node = node->down;
	}
	return (0);
}

void	ft_applay_ra_rb(t_stack *stack_a, t_stack *stack_b, int ra, int rb)
{
	while (ra > 0 || rb > 0)
	{
		if (ra > 0 && rb > 0)
		{
			ft_rotate_rule(stack_a);
			ft_rotate_rule(stack_b);
			ra--;
			rb--;
			ft_putstrnl_fd("rr", 1);
		}
		else if (ra > 0)
		{
			ft_rotate_rule(stack_a);
			ra--;
			ft_putstrnl_fd("ra", 1);
		}
		else if (rb > 0)
		{
			ft_rotate_rule(stack_b);
			rb--;
			ft_putstrnl_fd("rb", 1);
		}
	}
}

void	ft_applay_rra_rrb(t_stack *stack_a, t_stack *stack_b, int rra, int rrb)
{
	while (rra > 0 || rrb > 0)
	{
		if (rra > 0 && rrb > 0)
		{
			ft_reverse_rotate_rule(stack_a);
			ft_reverse_rotate_rule(stack_b);
			rra--;
			rrb--;
			ft_putstrnl_fd("rrr", 1);
		}
		else if (rra > 0)
		{
			ft_reverse_rotate_rule(stack_a);
			rra--;
			ft_putstrnl_fd("rra", 1);
		}
		else if (rrb > 0)
		{
			ft_reverse_rotate_rule(stack_b);
			rrb--;
			ft_putstrnl_fd("rrb", 1);
		}
	}
}

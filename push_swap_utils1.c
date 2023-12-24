/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:16:19 by zech-chi          #+#    #+#             */
/*   Updated: 2023/12/24 11:59:19 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	write(fd, s, ft_strlen(s));
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	ft_applay_move(char *move, t_stack *stack_a, t_stack *stack_b)
{
	if (!ft_strcmp(move, "sa"))
		return (ft_swap_rule(stack_a), 1);
	else if (!ft_strcmp(move, "sb"))
		return (ft_swap_rule(stack_b), 1);
	else if (!ft_strcmp(move, "ra"))
		return (ft_rotate_rule(stack_a), 1);
	else if (!ft_strcmp(move, "rb"))
		return (ft_rotate_rule(stack_b), 1);
	else if (!ft_strcmp(move, "rr"))
		return (ft_rotate_rule(stack_a), ft_rotate_rule(stack_b), 1);
	else if (!ft_strcmp(move, "rra"))
		return (ft_reverse_rotate_rule(stack_a), 1);
	else if (!ft_strcmp(move, "rrb"))
		return (ft_reverse_rotate_rule(stack_b), 1);
	else if (!ft_strcmp(move, "rrr"))
		return (ft_reverse_rotate_rule(stack_a), ft_reverse_rotate_rule(stack_b), 1);
	else if (!ft_strcmp(move, "pa"))
		return (ft_push_rule(stack_b, stack_a), 1);
	else if (!ft_strcmp(move, "pb"))
		return (ft_push_rule(stack_a, stack_b), 1);
	return (0);
}

void	ft_flagLISelements(t_stack *stack)
{
	t_node	*cur;
	int	max;

	cur = stack->top;
	max = 1;
	while (cur)
	{
		if (cur->lis > max)
			max = cur->lis;
		cur = cur->down;
	}
	stack->len_lis = max;
	cur = stack->top;
	while (max > 0)
	{
		if (cur->lis == max)
		{
			cur->in_lis = 1;
			max--;
		}
		cur = cur->down;
	}
}

void	ft_LIS(t_stack *stack)
{
	t_node	*node_i;
	t_node	*node_j;

	node_i = stack->tail->up;
	while (node_i)
	{
		node_j = node_i->down;
		while (node_j)
		{
			if (node_i->value < node_j->value)
				if (node_i->lis < node_j->lis + 1)
					node_i->lis = node_j->lis + 1;
			node_j = node_j->down;
		}
		node_i = node_i->up;
	}
	ft_flagLISelements(stack);
}

int	max(int	a, int b)
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

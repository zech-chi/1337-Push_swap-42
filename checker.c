/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 21:38:11 by zech-chi          #+#    #+#             */
/*   Updated: 2023/12/31 14:52:44 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	ft_applay_move(char *move, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(move, "sa\n"))
		return (ft_swap_rule(a), 1);
	else if (!ft_strcmp(move, "sb\n"))
		return (ft_swap_rule(b), 1);
	else if (!ft_strcmp(move, "ss\n"))
		return (ft_swap_rule(a), ft_swap_rule(b), 1);
	else if (!ft_strcmp(move, "pa\n"))
		return (ft_push_rule(b, a), 1);
	else if (!ft_strcmp(move, "pb\n"))
		return (ft_push_rule(a, b), 1);
	else if (!ft_strcmp(move, "ra\n"))
		return (ft_rotate_rule(a), 1);
	else if (!ft_strcmp(move, "rb\n"))
		return (ft_rotate_rule(b), 1);
	else if (!ft_strcmp(move, "rr\n"))
		return (ft_rotate_rule(a), ft_rotate_rule(b), 1);
	else if (!ft_strcmp(move, "rra\n"))
		return (ft_reverse_rotate_rule(a), 1);
	else if (!ft_strcmp(move, "rrb\n"))
		return (ft_reverse_rotate_rule(b), 1);
	else if (!ft_strcmp(move, "rrr\n"))
		return (ft_reverse_rotate_rule(a), ft_reverse_rotate_rule(b), 1);
	return (0);
}

int	ft_read_moves(t_stack *stack_a, t_stack *stack_b)
{
	char	*move;

	move = get_next_line(0);
	while (move)
	{
		if (!ft_applay_move(move, stack_a, stack_b))
			return (free(move), 0);
		free(move);
		move = get_next_line(0);
	}
	return (1);
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
		return (ft_putstrnl_fd("Error", 2), ft_stack_clear(&stack_a), 0);
	if (!ft_read_moves(&stack_a, &stack_b))
		ft_putstrnl_fd("Error", 2);
	else if (ft_stack_is_sorted(stack_a) && stack_b.len == 0)
		ft_putstrnl_fd("OK", 1);
	else
		ft_putstrnl_fd("KO", 1);
	return (ft_stack_clear(&stack_a), ft_stack_clear(&stack_b), 0);
}

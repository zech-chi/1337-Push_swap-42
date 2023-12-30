/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:19:04 by zech-chi          #+#    #+#             */
/*   Updated: 2023/12/30 15:25:46 by zech-chi         ###   ########.fr       */
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

void	ft_print_stack2(t_stack stack, char *name)
{
	t_node	*cur_node;

	cur_node = stack.top;
	if (!cur_node)
	{
		printf("stack: %s is empty!!!\n\n", name);
		return ;
	}
	printf("\n");
	while (cur_node)
	{
		printf("\n|  %d  |", cur_node->value);
		if (!(cur_node->up))
			printf(" top");
		cur_node = cur_node->down;
	}
	printf(" tail\n");
	printf("-------\t\n");
	printf("stack: %s (len = %d)\n\n", name, stack.len);
}
/////////////////////

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
	if (stack_a.len == 3)
		ft_sort_3(&stack_a);
	else
	{
		ft_from_a_to_b(&stack_a, &stack_b);
		ft_from_b_to_a(&stack_a, &stack_b);
	}
	return (ft_stack_clear(&stack_a), 0);
}

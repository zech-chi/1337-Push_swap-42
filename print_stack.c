/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 23:16:07 by zech-chi          #+#    #+#             */
/*   Updated: 2023/12/24 10:44:10 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_from_top_to_tail(t_stack stack)
{
	t_node *cur_node;

	cur_node = stack.top;
	printf("top  --> ");
	while (cur_node)
	{
		printf("%d --> ", cur_node->value);
		cur_node = cur_node->down;
	}
	printf("NULL\n");
}

void	ft_print_from_tail_to_top(t_stack stack)
{
	t_node	*cur_node;

	cur_node = stack.tail;
	printf("tail --> ");
	while (cur_node)
	{
		printf("%d --> ", cur_node->value);
		cur_node = cur_node->up;
	}
	printf("NULL\n");
}

void	ft_print_stack(t_stack stack, char *name)
{
	t_node	*cur_node;

	cur_node = stack.top;
	while (cur_node)
	{
		printf("%d\n", cur_node->value);
		cur_node = cur_node->down;
	}
	printf("\n-\n%s\n", name);
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

void	ft_print_stack_with_lis(t_stack stack, char *name)
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
		printf("\n|  %d (%d) (%d) |", cur_node->value, cur_node->lis, cur_node->in_lis);
		if (!(cur_node->up))
			printf(" top");
		cur_node = cur_node->down;
	}
	printf(" tail\n");
	printf("-------\t\n");
	printf("stack: %s\n\n", name);
}
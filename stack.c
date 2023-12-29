/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 19:32:57 by zech-chi          #+#    #+#             */
/*   Updated: 2023/12/29 18:23:10 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//if this function return 1 everything is ok
// 0 if something wrong
// don't forget gaberge collector
int	ft_push(t_stack *stack, int value)
{
	t_node	*new_top;

	new_top = (t_node *)malloc(sizeof(t_node));
	if (!new_top)
		return (0);
	new_top->value = value;
	new_top->lis = 1;
	new_top->in_lis = 0;
	new_top->up = NULL;
	new_top->down = stack->top;
	if (stack->top)
		stack->top->up = new_top;
	if (!(stack->tail))
		stack->tail = new_top;
	stack->top = new_top;
	stack->len += 1;
	stack->maximus = max(stack->maximus, value);
	stack->minimus = min(stack->minimus, value);
	return (1);
}

void	ft_swap_rule(t_stack *stack)
{
	t_node	*new_top;

	if (!(stack->top) || !(stack->top->down))
		return ;
	new_top = stack->top->down;
	stack->top->down = new_top->down;
	stack->top->up = new_top;
	if (new_top->down)
		new_top->down->up = stack->top;
	else
		stack->tail = stack->top;
	new_top->down = stack->top;
	new_top->up = NULL;
	stack->top = new_top;
}

// pop from stack1 and push in stack2
void	ft_push_rule(t_stack *stack_1, t_stack *stack_2)
{
	t_node	*prev_top1;

	if (!(stack_1->top))
		return ;
	prev_top1 = stack_1->top;
	stack_1->top = stack_1->top->down;
	if (stack_2->top)
	{
		prev_top1->down = stack_2->top;
		stack_2->top->up = prev_top1;
	}
	else
	{
		stack_2->tail = prev_top1;
		prev_top1->down = NULL;
	}
	stack_2->top = prev_top1;
	if (stack_1->top)
		stack_1->top->up = NULL;
	else
		stack_1->tail = NULL;
	stack_1->len -= 1;
	stack_2->len += 1;
}

void	ft_rotate_rule(t_stack *stack)
{
	if (!(stack->top) || !(stack->top->down))
		return ;
	stack->top = stack->top->down;
	stack->top->up->up = stack->tail;
	stack->top->up->down = NULL;
	stack->tail = stack->top->up;
	stack->top->up = NULL;
	stack->tail->up->down = stack->tail;
}

void	ft_reverse_rotate_rule(t_stack *stack)
{
	if (!(stack->top) || !(stack->top->down))
		return ;
	stack->top->up = stack->tail;
	stack->tail->down = stack->top;
	stack->top = stack->tail;
	stack->tail = stack->tail->up;
	stack->top->up = NULL;
	stack->tail->down = NULL;
}

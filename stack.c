/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:08:25 by zech-chi          #+#    #+#             */
/*   Updated: 2023/12/24 11:57:54 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//void	ft_push(t_stack *stack->top, t_stack *stack->tail, int value)
//this function add a node into top of the stack
// if everything is ok it return 1 or 0 otherwise
int	ft_push(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (0);
	new_node->value = value;
	new_node->lis = 1;
	new_node->in_lis = 0;
	new_node->up = NULL;
	new_node->down = stack->top;
	if (stack->top)
		stack->top->up = new_node;
	if (!(stack->tail))
		stack->tail = new_node;
	stack->top = new_node;
	stack->len += 1;
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
	stack->tail = (stack->top)->up;
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

//int	main()
//{
//	//stack_a
//	t_stack	stack->top_a = NULL;
//	t_stack	stack->tail_a = NULL;
//	//stack_b
//	t_stack	stack->top_b = NULL;
//	t_stack	stack->tail_b = NULL;
//	//elements
//	int	tab[6] = {8, 5, 6, 3, 1, 2};
//	int	*value;

//	for (int i = 0; i < 6; i++)
//	{
//		value = (int *)malloc(sizeof(int));
//		if (!value)
//			break;
//		*value = tab[i];
//		ft_push(&top_a, &tail_a, value);
//	}
//	ft_print_stack2(top_a, "a");
//	ft_print_stack2(top_b, "b");
//	printf("***************************************************************************\n");
//	//Exec sa:
//	ft_swap_rule(&top_a, &top_b);
//	ft_print_stack2(top_a, "a");
//	ft_print_stack2(top_b, "b");
//	printf("***************************************************************************\n");
//	//Exec pb pb pb:
//	ft_push_rule(&top_a, &tail_a, &top_b, &tail_b);
//	ft_push_rule(&top_a, &tail_a, &top_b, &tail_b);
//	ft_push_rule(&top_a, &tail_a, &top_b, &tail_b);
//	ft_print_stack2(top_a, "a");
//	ft_print_stack2(top_b, "b");
//	printf("***************************************************************************\n");
//	//Exec ra rb (equiv. to rr):
//	ft_rotate_rule(&top_a, &tail_a);
//	ft_rotate_rule(&top_b, &tail_b);
//	ft_print_stack2(top_a, "a");
//	ft_print_stack2(top_b, "b");
//	printf("***************************************************************************\n");
//	//Exec rra rrb (equiv. to rrr):
//	ft_reverse_rotate_rule(&top_a, &tail_a);
//	ft_reverse_rotate_rule(&top_b, &tail_b);
//	ft_print_stack2(top_a, "a");
//	ft_print_stack2(top_b, "b");
//	printf("***************************************************************************\n");
//	//Exec sa:
//	ft_swap_rule(&top_a, &tail_a);
//	ft_print_stack2(top_a, "a");
//	ft_print_stack2(top_b, "b");
//	printf("***************************************************************************\n");
//	//Exec pa pa pa:
//	ft_push_rule(&top_b, &tail_b, &top_a, &tail_a);
//	ft_push_rule(&top_b, &tail_b, &top_a, &tail_a);
//	ft_push_rule(&top_b, &tail_b, &top_a, &tail_a);
//	ft_print_stack2(top_a, "a");
//	ft_print_stack2(top_b, "b");
//	printf("***************************************************************************\n");
//	return (0);
//}

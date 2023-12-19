/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:08:25 by zech-chi          #+#    #+#             */
/*   Updated: 2023/12/19 22:27:15 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **top, t_stack **tail, int *value)
{
	t_stack	*new_node;

	if (!value)
		return ;m 
	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->up = NULL;
	new_node->down = *top;
	if (*top)
		(*top)->up = new_node;
	if (!(*tail))
		*tail = new_node;
	*top = new_node;
}

void	ft_swap_rule(t_stack **top, t_stack **tail)
{
	t_stack	*new_top;

	if (!(*top) || !((*top)->down))
		return ;
	new_top	= (*top)->down;
	(*top)->down = new_top->down;
	(*top)->up = new_top;
	if (new_top->down)
		new_top->down->up = *top;
	else
		*tail = *top;
	new_top->down = *top;
	new_top->up = NULL;
	*top = new_top;
}
// pop from stack1 and push in stack2
void	ft_push_rule(t_stack **top1, t_stack **tail1, t_stack **top2, t_stack **tail2)
{
	t_stack	*prev_top1;

	if (!(*top1))
		return ;
	prev_top1 = *top1;
	*top1 = (*top1)->down;
	if (*top2)
	{
		prev_top1->down = *top2;
		(*top2)->up = prev_top1;
	}
	else
	{
		*tail2 = prev_top1;
		prev_top1->down = NULL;
	}
	*top2 = prev_top1;
	if (*top1)
		(*top1)->up = NULL;
	else
		*tail1 = NULL;
}

void	ft_rotate_rule(t_stack **top, t_stack **tail)
{
	if (!(*top) || !((*top)->down))
		return ;
	*top = (*top)->down;
	(*top)->up->up = *tail;
	(*top)->up->down = NULL;
	*tail = (*top)->up;
	(*top)->up = NULL;
	(*tail)->up->down = *tail;
}

void	ft_reverse_rotate_rule(t_stack **top, t_stack **tail)
{
	if (!(*top) || !((*top)->down))
		return ;
	(*top)->up = *tail;
	(*tail)->down = *top;
	*top = *tail;
	*tail = (*tail)->up;
	(*top)->up = NULL;
	(*tail)->down = NULL;
}

//int	main()
//{
//	//stack_a
//	t_stack	*top_a = NULL;
//	t_stack	*tail_a = NULL;
//	//stack_b
//	t_stack	*top_b = NULL;
//	t_stack	*tail_b = NULL;
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

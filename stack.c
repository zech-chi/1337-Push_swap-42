/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:08:25 by zech-chi          #+#    #+#             */
/*   Updated: 2023/12/13 16:13:00 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_push(t_stack **top, t_stack **tail, int *value)
{
	t_stack	*new_node;

	if (!value)
		return ;
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

int    main()
{
    t_stack    *top;
    t_stack    *tail;
    int *a;

    top = NULL;
    tail = NULL;
    for (int i = 0; i < 2; i++)
    {
      a = malloc(sizeof(int));
      if (!a)
        return (0);
      *a = i;
      ft_push(&top, &tail, a);
    }
	ft_print_from_top_to_tail(top);
	ft_print_from_tail_to_top(tail);
	ft_print_stack2(top, "a");

	printf("###################################\n");
	ft_reverse_rotate_rule(&top, &tail);
	ft_print_from_top_to_tail(top);
	ft_print_from_tail_to_top(tail);
	ft_print_stack2(top, "a");
	return (0);
}

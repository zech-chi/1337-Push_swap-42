/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 23:16:07 by zech-chi          #+#    #+#             */
/*   Updated: 2023/12/17 23:16:08 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_from_top_to_tail(t_stack *top)
{
	printf("top  --> ");
	while (top)
	{
		printf("%d --> ", *(top->value));
		top = top->down;
	}
	printf("NULL\n");
}

void	ft_print_from_tail_to_top(t_stack *tail)
{
	printf("tail --> ");
	while (tail)
	{
		printf("%d --> ", *(tail->value));
		tail = tail->up;
	}
	printf("NULL\n");
}

void	ft_print_stack(t_stack *top, char *name)
{
	while (top)
	{
		printf("%d\n", *(top->value));
		top = top->down;
	}
	printf("\n-\n%s\n", name);
}

void	ft_print_stack2(t_stack *top, char *name)
{
	int	counter;

	if (!top)
	{
		printf("stack: %s is empty!!!\n\n", name);
		return ;
	}
	counter = 0;
	printf("\n");
	while (top)
	{
		printf("\n|  %d  |", *(top->value));
		if (counter == 0)
			printf(" top");
		counter++;
		top = top->down;
	}
	printf(" tail\n");
	printf("-------\t\n");
	printf("stack: %s\n\n", name);
}

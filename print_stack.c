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
		printf("stack %s is empty!!!\n", name);
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
	printf("stack: %s\n", name);
}

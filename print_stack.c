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
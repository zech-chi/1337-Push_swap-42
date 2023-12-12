#include <stdlib.h>
#include <stdio.h>

typedef struct s_stack
{
    int               *value;
    struct s_stack    *up;
    struct s_stack    *down;
}    t_stack;


void    ft_push(t_stack **top, t_stack **tail,int *value)
{
    t_stack    *new_node;

    new_node = (t_stack *)malloc(sizeof(t_stack));
    if (!new_node || !value)
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

void	ft_print_from_top_to_tail(t_stack *top)
{
	printf("top --> ");
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

int    main()
{
    t_stack    *top;
    t_stack    *tail;
    int *a;

    top = NULL;
    tail = NULL;
    for (int i = 0; i < 3; i++)
    {
      a = malloc(sizeof(int));
      if (!a)
        return (0);
      *a = i;
      ft_push(&top, &tail, a);
    }

	ft_print_from_top_to_tail(top);
	ft_print_from_tail_to_top(tail);
	return (0);
}
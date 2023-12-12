#include "push_swap.h"

void    ft_push(t_stack **top, t_stack **tail, int *value)
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

int    main()
{
    t_stack    *top;
    t_stack    *tail;
    int *a;

    top = NULL;
    tail = NULL;
    for (int i = 0; i < 7; i++)
    {
      a = malloc(sizeof(int));
      if (!a)
        return (0);
      *a = i;
      ft_push(&top, &tail, a);
    }

	ft_print_from_top_to_tail(top);
	ft_print_from_tail_to_top(tail);
	ft_print_stack(top, "a");
	return (0);
}
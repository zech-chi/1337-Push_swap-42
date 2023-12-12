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

void	ft_push_rule();

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
    for (int i = 0; i < 5; i++)
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
//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>

//typedef struct s_node
//{
//	int		value;
//	int		lis;
//	int		in_lis;
//	struct s_node	*up;
//	struct s_node	*down;
//}	t_node;

//typedef	struct s_stack
//{
//	t_node	*top;
//	t_node	*tail;
//	int		len;
//}	t_stack;


//int	ft_push(t_stack *stack, int value)
//{
//	t_node	*new_node;

//	new_node = (t_node *)malloc(sizeof(t_node));
//	if (!new_node)
//		return (0);
//	new_node->value = value;
//	new_node->lis = 1;
//	new_node->in_lis = 0;
//	new_node->up = NULL;
//	new_node->down = stack->top;
//	if (stack->top)
//		stack->top->up = new_node;
//	if (!(stack->tail))
//		stack->tail = new_node;
//	stack->top = new_node;
//	stack->len += 1;
//	return (1);
//}

//void	ft_print_from_top_to_tail(t_stack stack)
//{
//	t_node *cur_node;

//	cur_node = stack.top;
//	printf("top  --> ");
//	while (cur_node)
//	{
//		printf("%d --> ", cur_node->value);
//		cur_node = cur_node->down;
//	}
//	printf("NULL\n");
//}

//void	ft_print_from_tail_to_top(t_stack stack)
//{
//	t_node	*cur_node;

//	cur_node = stack.tail;
//	printf("tail --> ");
//	while (cur_node)
//	{
//		printf("%d --> ", cur_node->value);
//		cur_node = cur_node->up;
//	}
//	printf("NULL\n");
//}

//void	ft_print_stack(t_stack stack, char *name)
//{
//	t_node	*cur_node;

//	cur_node = stack.top;
//	while (cur_node)
//	{
//		printf("%d\n", cur_node->value);
//		cur_node = cur_node->down;
//	}
//	printf("\n-\n%s\n", name);
//}

//void	ft_print_stack2(t_stack stack, char *name)
//{
//	t_node	*cur_node;

//	cur_node = stack.top;
//	if (!cur_node)
//	{
//		printf("stack: %s is empty!!!\n\n", name);
//		return ;
//	}
//	printf("\n");
//	while (cur_node)
//	{
//		printf("\n|  %d  |", cur_node->value);
//		if (!(cur_node->up))
//			printf(" top");
//		cur_node = cur_node->down;
//	}
//	printf(" tail\n");
//	printf("-------\t\n");
//	printf("stack: %s\n\n", name);
//}

//void	ft_print_stack_with_lis(t_stack stack, char *name)
//{
//	t_node	*cur_node;

//	cur_node = stack.top;
//	if (!cur_node)
//	{
//		printf("stack: %s is empty!!!\n\n", name);
//		return ;
//	}
//	printf("\n");
//	while (cur_node)
//	{
//		printf("\n|  %d (%d) (%d) |", cur_node->value, cur_node->lis, cur_node->in_lis);
//		if (!(cur_node->up))
//			printf(" top");
//		cur_node = cur_node->down;
//	}
//	printf(" tail\n");
//	printf("-------\t\n");
//	printf("stack: %s\n\n", name);
//}

//void	ft_flagLISelements(t_stack *stack)
//{
//	t_node	*cur;
//	int	max;

//	cur = stack->top;
//	max = 1;
//	while (cur)
//	{
//		if (cur->lis > max)
//			max = cur->lis;
//		cur = cur->down;
//	}
//	cur = stack->top;
//	while (max > 0)
//	{
//		if (cur->lis == max)
//		{
//			cur->in_lis = 1;
//			max--;
//		}
//		cur = cur->down;
//	}
//}

//void	ft_LIS(t_stack *stack)
//{
//	t_node	*node_i;
//	t_node	*node_j;

//	node_i = stack->tail->up;
//	while (node_i)
//	{
//		node_j = node_i->down;
//		while (node_j)
//		{
//			if (node_i->value < node_j->value)
//				if (node_i->lis < node_j->lis + 1)
//					node_i->lis = node_j->lis + 1;
//			node_j = node_j->down;
//		}
//		node_i = node_i->up;
//	}
//	ft_flagLISelements(stack);
//}


//int	main(int ac, char **av)
//{
//	if (ac == 0)
//		return (0);
	
//	t_stack stack_a;
//	stack_a.top = NULL;
//	stack_a.tail = NULL;
//	stack_a.len = 0;
//	int i = ac - 1;
//	while (i > 0)
//	{
//		ft_push(&stack_a, atoi(av[i]));
//		i--;
//	}
//	ft_print_from_top_to_tail(stack_a);
//	ft_print_from_tail_to_top(stack_a);
//	ft_print_stack(stack_a, "a");
//	ft_print_stack2(stack_a, "a");
//	ft_print_stack_with_lis(stack_a, "a");
//	ft_LIS(&stack_a);
//	ft_print_stack_with_lis(stack_a, "a");
//}
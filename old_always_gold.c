//void	ft_print_from_top_to_tail(t_stack *top)
//{
//	printf("top  --> ");
//	while (top)
//	{
//		printf("%d --> ", top->value);
//		top = top->down;
//	}
//	printf("NULL\n");
//}

//void	ft_print_from_tail_to_top(t_stack *tail)
//{
//	printf("tail --> ");
//	while (tail)
//	{
//		printf("%d --> ", tail->value);
//		tail = tail->up;
//	}
//	printf("NULL\n");
//}

//void	ft_print_stack(t_stack *top, char *name)
//{
//	while (top)
//	{
//		printf("%d\n", top->value);
//		top = top->down;
//	}
//	printf("\n-\n%s\n", name);
//}

//void	ft_print_stack2(t_stack *top, char *name)
//{
//	int	counter;

//	if (!top)
//	{
//		printf("stack: %s is empty!!!\n\n", name);
//		return ;
//	}
//	counter = 0;
//	printf("\n");
//	while (top)
//	{
//		printf("\n|  %d  |", top->value);
//		if (counter == 0)
//			printf(" top");
//		counter++;
//		top = top->down;
//	}
//	printf(" tail\n");
//	printf("-------\t\n");
//	printf("stack: %s\n\n", name);
//}

//void	ft_print_stack_with_lis(t_stack *top, char *name)
//{
//	int	counter;

//	if (!top)
//	{
//		printf("stack: %s is empty!!!\n\n", name);
//		return ;
//	}
//	counter = 0;
//	printf("\n");
//	while (top)
//	{
//		printf("\n|  %d (%d) |", top->value, top->in_lis);
//		if (counter == 0)
//			printf(" top");
//		counter++;
//		top = top->down;
//	}
//	printf(" tail\n");
//	printf("-------\t\n");
//	printf("stack: %s\n\n", name);
//}


//void	ft_flagLISelements(t_stack **top_a)
//{
//	t_stack	*cur;
//	int	max;

//	cur = *top_a;
//	max = 1;
//	while (cur)
//	{
//		if (cur->lis > max)
//			max = cur->lis;
//		cur = cur->down;
//	}
//	cur = *top_a;
//	while (max > 0)
//	{
//		if (cur->lis == max)
//		{
//			cur->in_lis = 1;
//			max--;
//		}
//		else
//			cur->in_lis = 0;
//		cur = cur->down;
//	}
//}

//void	ft_LIS(t_stack **top_a, t_stack **tail_a)
//{
//	t_stack	*node_i;
//	t_stack	*node_j;

//	node_i = *top_a;
//	while (node_i)
//	{
//		node_i->lis = 1;
//		node_i = node_i->down;
//	}
//	node_i = (*tail_a)->up;
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
//	ft_flagLISelements(top_a);
//}

//void	ft_swap_rule(t_stack **top, t_stack **tail)
//{
//	t_stack	*new_top;

//	if (!(*top) || !((*top)->down))
//		return ;
//	new_top	= (*top)->down;
//	(*top)->down = new_top->down;
//	(*top)->up = new_top;
//	if (new_top->down)
//		new_top->down->up = *top;
//	else
//		*tail = *top;
//	new_top->down = *top;
//	new_top->up = NULL;
//	*top = new_top;
//}
//// pop from stack1 and push in stack2
//void	ft_push_rule(t_stack **top1, t_stack **tail1, t_stack **top2, t_stack **tail2)
//{
//	t_stack	*prev_top1;

//	if (!(*top1))
//		return ;
//	prev_top1 = *top1;
//	*top1 = (*top1)->down;
//	if (*top2)
//	{
//		prev_top1->down = *top2;
//		(*top2)->up = prev_top1;
//	}
//	else
//	{
//		*tail2 = prev_top1;
//		prev_top1->down = NULL;
//	}
//	*top2 = prev_top1;
//	if (*top1)
//		(*top1)->up = NULL;
//	else
//		*tail1 = NULL;
//}

//void	ft_rotate_rule(t_stack **top, t_stack **tail)
//{
//	if (!(*top) || !((*top)->down))
//		return ;
//	*top = (*top)->down;
//	(*top)->up->up = *tail;
//	(*top)->up->down = NULL;
//	*tail = (*top)->up;
//	(*top)->up = NULL;
//	(*tail)->up->down = *tail;
//}

//void	ft_reverse_rotate_rule(t_stack **top, t_stack **tail)
//{
//	if (!(*top) || !((*top)->down))
//		return ;
//	(*top)->up = *tail;
//	(*tail)->down = *top;
//	*top = *tail;
//	*tail = (*tail)->up;
//	(*top)->up = NULL;
//	(*tail)->down = NULL;
//}

//int	ft_stack_is_sorted(t_stack stack_a)
//{
//	t_node	*cur_node;

//	cur_node = stack_a.top;
//	if (!(cur_node) || !(cur_node->down))
//		return (1);
//	cur_node = cur_node->down;
//	while (cur_node)
//	{
//		if (cur_node->up->value > cur_node->value)
//			return (0);
//		cur_node = cur_node->down;
//	}
//	return (1);
//}


//int	ft_get_max_small(t_stack stack_a, int b)
//{
//	t_node	*cur_node;
//	int		max_small;
//	int		max_small_index;
//	int		index;

//	max_small_index = 0;
//	max_small = stack_a.top->value;
//	cur_node = stack_a.top->down;
//	index = 0;
//	while (cur_node)
//	{
//		if (cur_node->value < b && cur_node->value > max_small)
//		{
//			max_small = cur_node->value;
//			max_small_index = index;
//		}
//		index++;
//		cur_node = cur_node->down;
//	}
//	return (max_small_index);
//}


//int main(int ac, char **av)
//{
//	t_stack stack_a;
//	t_stack stack_b;

//	stack_a.top = NULL;
//	stack_a.tail = NULL;
//	stack_a.len = 0;
//	stack_a.len_lis = 0;
//	stack_b.top = NULL;
//	stack_b.tail = NULL;
//	stack_b.len = 0;
//	stack_b.len_lis = 0;
//	int	something_wrong;
//	int	val;

//	if (ac == 1)
//		return (0);
//	while (--ac > 0)
//	{
//		val = ft_atoi_plus(av[ac], &something_wrong);
//		if (something_wrong)
//			return (0);
//		ft_push(&stack_a, val);
//	}
	
//	ft_LIS(&stack_a);
//	if (stack_a.len == stack_a.len_lis)
//	{
//		printf("\n\nstack already sorted\n\n");
//		return (0);
//	}
//	ft_print_stack_with_lis(stack_a, "a");
//	ft_print_stack2(stack_b, "b");
//	printf("**********************************\n");
//	ft_move_not_in_lis_in_stack_b(&stack_a, &stack_b);
//	ft_print_stack2(stack_a, "a");
//	ft_print_stack2(stack_b, "b");
//	printf("**********************************\n");
//	char move[10];
//	int	help = 0;
//	while (1)
//	{
//		printf("help??\n");
//		scanf("%d", &help);
//		if (help)
//		{
//			ft_print_max_small_min_great(stack_a, stack_b);
//			ft_applay_best_move(&stack_a, &stack_b);
//		}
//		else
//		{
//			printf("\nmove??\n");
//			scanf("%s", move);
//			while (!ft_applay_move(move, &stack_a, &stack_b))
//			{
//				printf("invalid move try again!!!!\n");
//				scanf("%s", move);
//			}
//		}
//		ft_print_stack2(stack_a, "a");
//		ft_print_stack2(stack_b, "b");
//		printf("**********************************\n");
//		move[0] = 0;
//		move[1] = 0;
//		move[2] = 0;
//		move[3] = 0;
//		move[4] = 0;
//		help = 0;
//	}
//}


/////////
/////////
/////////
/////////
/////////
/////////
/////////
////// the best main ever
//int main(int ac, char **av)
//{
//	t_stack stack_a;
//	t_stack stack_b;

//	stack_a.top = NULL;
//	stack_a.tail = NULL;
//	stack_a.len = 0;
//	stack_a.len_lis = 0;
//	stack_b.top = NULL;
//	stack_b.tail = NULL;
//	stack_b.len = 0;
//	stack_b.len_lis = 0;
//	int	something_wrong;
//	int	val;

//	if (ac == 1)
//		return (0);
//	while (--ac > 0)
//	{
//		val = ft_atoi_plus(av[ac], &something_wrong);
//		if (something_wrong)
//			return (0);
//		ft_push(&stack_a, val);
//	}
	
//	ft_LIS(&stack_a);
//	if (stack_a.len == stack_a.len_lis)
//	{
//		printf("\n\nstack already sorted\n\n");
//		return (0);
//	}
//	ft_print_stack_with_lis(stack_a, "a");
//	ft_print_stack2(stack_b, "b");
//	printf("**********************************\n");
//	ft_move_not_in_lis_in_stack_b(&stack_a, &stack_b);
//	ft_print_stack2(stack_a, "a");
//	ft_print_stack2(stack_b, "b");
//	printf("**********************************\n");

//	while (stack_b.len > 0)
//	{
//		ft_applay_best_move(&stack_a, &stack_b);
//		ft_print_stack2(stack_a, "a");
//		ft_print_stack2(stack_b, "b");
//		printf("**********************************\n");
//	}
//	int min_index = ft_get_index_min(stack_a);
//	int i = -1;
//	if (min_index < stack_a.len - min_index)
//	{
//		while (++i < min_index)
//		{
//			ft_rotate_rule(&stack_a);
//			printf("ra\n");
//		}
//	}
//	else
//	{
//		while (++i < stack_a.len - min_index)
//		{
//			ft_reverse_rotate_rule(&stack_a);
//			printf("rra\n");
//		}
//	}
//	ft_print_stack2(stack_a, "a");
//	ft_print_stack2(stack_b, "b");
//	printf("**********************************\n");
//}
///* ************************************************************************** */
///*                                                                            */
///*                                                        :::      ::::::::   */
///*   push_swap2.c                                       :+:      :+:    :+:   */
///*                                                    +:+ +:+         +:+     */
///*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
///*                                                +#+#+#+#+#+   +#+           */
///*   Created: 2023/12/18 09:02:38 by zech-chi          #+#    #+#             */
///*   Updated: 2023/12/27 16:21:07 by zech-chi         ###   ########.fr       */
///*                                                                            */
///* ************************************************************************** */

//#include "push_swap.h"


//int	ft_atoi_plus(char *str, int *something_wrong)
//{
//	long long	res;
//	int			signe;
//	int			i;

//	i = 0;
//	while (str[i] == ' ')
//		i++;
//	signe = 1 - 2 * (str[i] == '-');
//	i = i + 1 * (str[i] == '-' || str[i] == '+');
//	if (!str[i])
//		return (*something_wrong = 1, 0);
//	res = 0;
//	while ('0' <= str[i] && str[i] <= '9')
//	{
//		res = res * 10 + str[i++] - '0';
//		if (res < -2147483648 || res > 2147483647)
//			return (*something_wrong = 1, 0);
//	}
//	return (*something_wrong = 1 * (str[i] != '\0'), signe * res);
//}


//int	ft_get_max_small(t_stack stack_b, int a)
//{
//	t_node 	*cur_node;
//	int	max_small;
//	int	max_small_index;
//	int	index;

//	max_small_index = -1;
//	index = 0;
//	cur_node = stack_b.top;
//	while (cur_node)
//	{
//		if (cur_node->value < a && (max_small_index == -1 || cur_node->value > max_small))
//		{
//			max_small = cur_node->value;
//			max_small_index = index;
//		}
//		index++;
//		cur_node = cur_node->down;
//	}
//	return (max_small_index);
//}

//int	ft_get_index_max(t_stack stack_a)
//{
//	int	max;
//	int	index_max;
//	int	index;
//	t_node	*node_a;

//	index_max = -1;
//	index = 0;
//	node_a = stack_a.top;
//	while (node_a)
//	{
//		if (index_max == -1 || node_a->value > max)
//		{
//			index_max = index;
//			max = node_a->value;
//		}
//		node_a = node_a->down;
//		index++;
//	}
//	return (index_max);
//}


//void	ft_applay_best_move(t_stack *stack_a, t_stack *stack_b)
//{
//	int	a_to_move = -1;
//	int	b_to_move = -1;
//	int	a = 0;
//	int	b;
//	int	cost;
//	int	min_cost = -1;
//	t_node	*node_a = stack_a->top;
//	int	ra = 0;
//	int	rb = 0;
//	int	rra = 0;
//	int	rrb = 0;
//	while (node_a)
//	{
//		if (node_a->in_lis == 0)
//		{
//			b = ft_get_max_small(*stack_b, node_a->value);
//			if (b == -1)
//			{
//				int	max_index = ft_get_index_max(*stack_b);
//				cost = min(a, stack_a->len - a) + min(max_index, stack_b->len - max_index);
//			}
//			// what if b == -1?????
//			else
//				cost = min(a, stack_a->len - a) + min(b, stack_b->len - b);
//			if (min_cost == -1 || cost < min_cost)
//			{
//				a_to_move = a;
//				b_to_move = b;
//				min_cost = cost;
//			}
//		}
//		node_a = node_a->down;
//		a++;
//	}
//	if (b_to_move == -1)
//		b_to_move = ft_get_index_max(*stack_b);
//	if (b_to_move < stack_b->len - b_to_move)
//		rb = b_to_move;
//	else
//		rrb = stack_b->len - b_to_move;
//	if (a_to_move < stack_a->len - a_to_move)
//		ra = a_to_move;
//	else
//		rra = stack_a->len - a_to_move;
	
//	while (ra > 0 || rb > 0)
//	{
//		if (ra > 0 && rb > 0)
//		{
//			ft_rotate_rule(stack_a);
//			ft_rotate_rule(stack_b);
//			ra--;
//			rb--;
//			printf("rr\n");
//		}
//		else if (ra > 0)
//		{
//			ft_rotate_rule(stack_a);
//			ra--;
//			printf("ra\n");
//		}
//		else if (rb > 0)
//		{
//			ft_rotate_rule(stack_b);
//			rb--;
//			printf("rb\n");
//		}
//	}
//	while (rra > 0 || rrb > 0)
//	{
//		if (rra > 0 && rrb > 0)
//		{
//			ft_reverse_rotate_rule(stack_a);
//			ft_reverse_rotate_rule(stack_b);
//			rra--;
//			rrb--;
//			printf("rrr\n");
//		}
//		else if (rra > 0)
//		{
//			ft_reverse_rotate_rule(stack_a);
//			rra--;
//			printf("rra\n");
//		}
//		else if (rrb > 0)
//		{
//			ft_reverse_rotate_rule(stack_b);
//			rrb--;
//			printf("rrb\n");
//		}
//	}
//	ft_push_rule(stack_a, stack_b);
//	printf("pb\n");
//}


//int	ft_get_min_great(t_stack stack_a, int b)
//{
//	t_node	*cur_node;
//	int	min_great;
//	int	min_great_index;
//	int	index;

//	min_great_index = -1;
//	index = 0;
//	cur_node = stack_a.top;
//	while (cur_node)
//	{
//		if (cur_node->value > b && (min_great_index == -1 || cur_node->value < min_great))
//		{
//			min_great = cur_node->value;
//			min_great_index = index;
//		}
//		index++;
//		cur_node = cur_node->down;
//	}
	
//	return (min_great_index);
//}

//int	ft_get_index_min(t_stack stack_a)
//{
//	int	min;
//	int	index_min;
//	int	index;
//	t_node	*node_a;

//	index_min = -1;
//	index = 0;
//	node_a = stack_a.top;
//	while (node_a)
//	{
//		if (index_min == -1 || node_a->value < min)
//		{
//			index_min = index;
//			min = node_a->value;
//		}
//		node_a = node_a->down;
//		index++;
//	}
//	return (index_min);
//}


//void	ft_from_b_to_a(t_stack *stack_a, t_stack *stack_b)
//{
//	int	index_a;
//	int	index_b;
//	int	a;
//	int	b;
//	int	cost;
//	int	min_cost;
//	t_node	*node_b;
//	int	ra = 0;
//	int	rb = 0;
//	int	rra = 0;
//	int	rrb = 0;

//	index_a = -1;
//	index_b = -1;
//	min_cost = -1;
//	b = 0;
//	node_b = stack_b->top;
//	while (node_b)
//	{
//		a = ft_get_min_great(*stack_a, node_b->value);
//		/////
//		if (a == -1)
//		{
//			int	j = ft_get_index_min(*stack_a);
//			cost = min(j, stack_a->len - j) + min(b, stack_b->len - b);
//		}
//		else
//		//////
//			cost = min(a, stack_a->len - a) + min(b, stack_b->len - b);
//		//printf("b = %d a = %d cost = %d\n", node_b->value, a, cost);
//		if ((min_cost == -1) || cost < min_cost)
//		{
//			index_a = a;
//			index_b = b;
//			min_cost = cost;
//		}
//		node_b = node_b->down;
//		b++;
//	}
//	if (index_a == -1)
//	{
//		int	min_index = ft_get_index_min(*stack_a);
//		if (min_index < stack_a->len - min_index)
//			ra = min_index;
//		else
//			rra = stack_a->len - min_index;
//	}
//	else if (index_a < stack_a ->len - index_a)
//		ra = index_a;
//	else
//		rra = stack_a->len - index_a;
//	if (index_b < stack_b->len - index_b)
//		rb = index_b;
//	else
//		rrb = stack_b->len - index_b;
//	while (ra > 0 || rb > 0)
//	{
//		if (ra > 0 && rb > 0)
//		{
//			ft_rotate_rule(stack_a);
//			ft_rotate_rule(stack_b);
//			ra--;
//			rb--;
//			printf("rr\n");
//		}
//		else if (ra > 0)
//		{
//			ft_rotate_rule(stack_a);
//			ra--;
//			printf("ra\n");
//		}
//		else if (rb > 0)
//		{
//			ft_rotate_rule(stack_b);
//			rb--;
//			printf("rb\n");
//		}
//	}
//	while (rra > 0 || rrb > 0)
//	{
//		if (rra > 0 && rrb > 0)
//		{
//			ft_reverse_rotate_rule(stack_a);
//			ft_reverse_rotate_rule(stack_b);
//			rra--;
//			rrb--;
//			printf("rrr\n");
//		}
//		else if (rra > 0)
//		{
//			ft_reverse_rotate_rule(stack_a);
//			rra--;
//			printf("rra\n");
//		}
//		else if (rrb > 0)
//		{
//			ft_reverse_rotate_rule(stack_b);
//			rrb--;
//			printf("rrb\n");
//		}
//	}
//	ft_push_rule(stack_b, stack_a);
//	printf("pa\n");
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
//	//ft_print_stack_with_lis(stack_a, "a");
//	//ft_print_stack2(stack_b, "b");
//	//printf("**********************************\n");
//	//ft_move_not_in_lis_in_stack_b(&stack_a, &stack_b);
//	//ft_print_stack2(stack_a, "a");
//	//ft_print_stack2(stack_b, "b");
//	//printf("**********************************\n");

//	while (stack_a.len_lis < stack_a.len)
//	{
//		//printf("here\n");
//		ft_applay_best_move(&stack_a, &stack_b);
//		//ft_print_stack2(stack_a, "a");
//		//ft_print_stack2(stack_b, "b");
//		//printf("**********************************\n");
//	}

//	while (stack_b.len > 0)
//	{
//		ft_from_b_to_a(&stack_a, &stack_b);
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
//}

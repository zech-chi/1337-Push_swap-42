///* ************************************************************************** */
///*                                                                            */
///*                                                        :::      ::::::::   */
///*   push_swap3.c                                       :+:      :+:    :+:   */
///*                                                    +:+ +:+         +:+     */
///*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
///*                                                +#+#+#+#+#+   +#+           */
///*   Created: 2023/12/18 09:02:38 by zech-chi          #+#    #+#             */
///*   Updated: 2023/12/27 16:21:14 by zech-chi         ###   ########.fr       */
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

//// this function after LIS
//// return index of the number for applay best move to stack b
//int	ft_get_best_move_to_stack_b(t_stack stack_a)
//{
//	t_node	*cur_node;
//	int		index;
//	int		best_index;
//	int		best_moves;
//	int		moves;

//	cur_node = stack_a.top;
//	best_index = -1;
//	index = 0;
//	best_moves = -1;
//	while (cur_node)
//	{
//		if (cur_node->in_lis == 0)
//		{
//			moves = min(index, stack_a.len - index);
//			if (best_moves == -1 || moves < best_moves)
//			{
//				best_moves = moves;
//				best_index = index;
//			}
//		}
//		cur_node = cur_node->down;
//		index++;
//	}
//	return (best_index);
//}

//void	ft_move_not_in_lis_in_stack_b(t_stack	*stack_a, t_stack *stack_b)
//{
//	int	index_to_move;
//	int	i;

//	while (stack_a->len_lis < stack_a->len)
//	{
//		index_to_move = ft_get_best_move_to_stack_b(*stack_a);
//		i = -1;
//		if (index_to_move < stack_a->len - index_to_move)
//		{
//			while (++i < index_to_move)
//			{
//				ft_rotate_rule(stack_a);
//				printf("ra\n");
//			}
//		}
//		else
//		{
//			while (++i < stack_a->len - index_to_move)
//			{
//				ft_reverse_rotate_rule(stack_a);
//				printf("rra\n");
//			}
//		}
//		ft_push_rule(stack_a, stack_b);
//		printf("pb\n");
//	}
//}

//// this stack return 1 if stack_a sorted
//// return 0 in otherwise


////int	main(int ac, char **av)
////{
////	int	somethig_wrong;
////	int	i;
////	int	r;
////	char **res;
////	int k;

////	ac = 0;
////	i = 1;
////	while (av[i])
////	{
////		res = ft_split(av[i], ' ');
////		r = 0;
////		while (res[r])
////		{
////			k = ft_atoi_plus(res[r], &somethig_wrong);
////			if (somethig_wrong)
////				return (ft_putstr_fd("ERROR!\n", 2), 0);
////			r++;
////		}	
////		i++;
////	}
////	somethig_wrong = 0;
////	ft_putstr_fd("Yes\n", 1);
////	return (0);
////}

//int	ft_get_min_great(t_stack stack_a, int b, int *store_it_here)
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
//	if (min_great_index != -1)
//		*store_it_here = min_great;
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


//void	ft_applay_best_move(t_stack *stack_a, t_stack *stack_b)
//{
//	int	index_a;
//	int	index_b;
//	int	less_greater_in_a;
//	int	less_greater_in_b;
//	int	less_greater_in_a_index;
//	int	less_greater_in_b_index;
//	int	min_index;
//	int	b;
//	int	cost;
//	int	min_cost;
//	t_node	*node_b = stack_b->top;
//	int	ra;
//	int	rb;
//	int	rra;
//	int	rrb;
//	ra = 0;
//	rb = 0;
//	rra = 0;
//	rrb = 0;
//	b = 0;
//	index_a = -1;
//	index_b = -1;
//	less_greater_in_a = -2147483648;
//	less_greater_in_b = -2147483648;
//	min_cost = -1;
//	while (node_b)
//	{
//		less_greater_in_a_index = ft_get_min_great(*stack_a, node_b->value, &less_greater_in_a);
//		less_greater_in_b_index = ft_get_min_great(*stack_b, node_b->value, &less_greater_in_b);
//		//printf("val = %d, a = %d, a_index = %d , b = %d, b_index = %d\n", node_b->value,less_greater_in_a, less_greater_in_a_index, less_greater_in_b, less_greater_in_b_index);
//		//this a big number
//		if (less_greater_in_a_index == -1 && less_greater_in_b_index == -1)
//		{
//			//printf("hna1\n");
//			min_index = ft_get_index_min(*stack_a);
//			cost = min(b, stack_b->len - b) + min(min_index, stack_a->len - min_index);
//			if (min_cost == -1 || cost < min_cost)
//			{
//				index_a = min_index;
//				index_b = b;
//				min_cost = cost;
//				//printf("cost = %d\n", cost);
//				//printf("index_a = %d\n", index_a);
//				//printf("index_b = %d\n", index_b);
//			}
//		}
//		else if (less_greater_in_a_index != -1 && less_greater_in_b_index != -1)
//		{
//			//printf("hna2\n");
//			if (less_greater_in_a < less_greater_in_b)
//			{
//				//printf("hna2_1\n");
//				cost = min(b, stack_b->len - b) + min(less_greater_in_a_index, stack_a->len - less_greater_in_a_index);
//				//printf("cost_cal = %d\n", cost);
//				//printf("min_cost = %d\n", min_cost);
//				if (min_cost == -1 || cost < min_cost)
//				{
//					index_a = less_greater_in_a_index;
//					index_b = b;
//					min_cost = cost;
//					//printf("cost = %d\n", cost);
//					//printf("index_a = %d\n", index_a);
//					//printf("index_b = %d\n", index_b);
//				}
//			}
//		}
//		else if (less_greater_in_a_index != -1)
//		{
//			//printf("hna3\n");
//			cost = min(b, stack_b->len - b) + min(less_greater_in_a_index, stack_a->len - less_greater_in_a_index);
//			if (min_cost == -1 || cost < min_cost)
//			{
//				index_a = less_greater_in_a_index;
//				index_b = b;
//				min_cost = cost;
//				//printf("cost = %d\n", cost);
//				//printf("index_a = %d\n", index_a);
//				//printf("index_b = %d\n", index_b);
//			}
//		}
//		b++;
//		node_b = node_b->down;
//	}
	
//	if (index_a < stack_a ->len - index_a)
//		ra = index_a;
//	else
//		rra = stack_a->len - index_a;
//	if (index_b < stack_b->len - index_b)
//		rb = index_b;
//	else
//		rrb = stack_b->len - index_b;
//	//printf("###########################\n");
//	//printf("cost = %d\n", min_cost);
//	//printf("index_a = %d\n", index_a);
//	//printf("index_b = %d\n", index_b);
//	//printf("ra = %d\n", ra);
//	//printf("rra = %d\n", rra);
//	//printf("rb = %d\n", rb);
//	//printf("rrb = %d\n", rrb);
//	//printf("###########################\n");
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
//	while (rra > 0 || rrb  > 0)
//	{
//		if (rra && rrb)
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

////void	ft_print_max_small_min_great(t_stack stack_a, t_stack stack_b)
////{
////	t_node	*node_b;

////	node_b = stack_b.top;
////	while (node_b)
////	{
////		printf("val: %d , ltaht: %d\n", node_b->value, \
////		ft_get_min_great(stack_a, node_b->value));
////		node_b = node_b->down;
////	}
////}

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
//	ft_move_not_in_lis_in_stack_b(&stack_a, &stack_b);
//	//ft_print_stack2(stack_a, "a");
//	//ft_print_stack2(stack_b, "b");
//	//printf("**********************************\n");

//	while (stack_b.len > 0)
//	{
//		ft_applay_best_move(&stack_a, &stack_b);
//		//ft_print_stack2(stack_a, "a");
//		//ft_print_stack2(stack_b, "b");
//		//printf("**********************************\n");
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
//	//ft_print_stack2(stack_a, "a");
//	//ft_print_stack2(stack_b, "b");
//	//printf("**********************************\n");
//}

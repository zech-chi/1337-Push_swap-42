/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 19:33:13 by zech-chi          #+#    #+#             */
/*   Updated: 2023/12/30 16:09:21 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_node
{
	int				value;
	int				lis;
	int				in_lis;
	struct s_node	*up;
	struct s_node	*down;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*tail;
	int		len;
	int		len_lis;
	int		maximus;
	int		minimus;
}	t_stack;

typedef struct s_from_b_to_a
{
	int	best_a;
	int	best_b;
	int	cur_a;
	int	cur_b;
	int	min_cost;
	int	cur_cost;
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	best_ra;
	int	best_rb;
	int	best_rra;
	int	best_rrb;
}	t_from_b_to_a;

// stack.c
int		ft_push(t_stack *stack, int value);
void	ft_swap_rule(t_stack *stack);
void	ft_push_rule(t_stack *stack_1, t_stack *stack_2);
void	ft_rotate_rule(t_stack *stack);
void	ft_reverse_rotate_rule(t_stack *stack);

// ft_split.c
char	**ft_split(char const *s, char c);

// push_swap_utils1.c
void	ft_putstrnl_fd(char *s, int fd);
int		max(int a, int b);
int		min(int a, int b);
int		ft_atoi_plus(char *str, int *something_wrong);
int		ft_is_valid_input(int ac, char **av, t_stack *stack_a);

//push_swap_utils2.c
void	ft_sort_3(t_stack *stack_a);
int		ft_stack_is_sorted(t_stack stack_a);
int		ft_is_already_in_stack(t_stack stack_a, int val);
void	ft_applay_ra_rb(t_stack *stack_a, t_stack *stack_b, int ra, int rb);

// from_a_to_b.c
void	ft_flag_lis_elements(t_stack *stack);
int		ft_get_max_lis(t_stack stack);
int		ft_lis(t_stack *stack);
void	ft_applay_best_lis(t_stack *stack_a);
void	ft_from_a_to_b(t_stack *stack_a, t_stack *stack_b);
void	ft_applay_rra_rrb(t_stack *stack_a, t_stack *stack_b, int rra, int rrb);

// from_b_to_a.c
int		ft_get_index_min(t_stack stack_a);
int		ft_get_min_great(t_stack stack_a, int b);
int		ft_get_cost(t_from_b_to_a *info, t_stack stack_a, t_stack stack_b);
void	ft_b_to_a_help(t_stack *stack_a, t_stack *stack_b, t_from_b_to_a *info);
void	ft_from_b_to_a(t_stack *stack_a, t_stack *stack_b);

// push_swap.c
void	ft_stack_clear(t_stack *stack);
void	ft_free_res(char **res);
void	ft_sort_5(t_stack *stack_a, t_stack *stack_b);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:00:34 by zech-chi          #+#    #+#             */
/*   Updated: 2023/12/24 11:58:08 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

//typedef struct s_stack
//{
//	int				value;
//	int				lis;
//	int				in_lis;
//	struct s_stack	*up;
//	struct s_stack	*down;
//}	t_stack;

//typedef struct s_node
//{
//    int				*value;
//    struct s_stack	*up;
//    struct s_stack	*down;
//}	t_node;

//typedef struct s_stack
//{
//	t_node	*top;
//	t_node	*tail;
//	int	len;
//	int	max;
//	int	max_index;
//	int	min;
//	int	min_index;
//}	t_stack;

typedef struct s_node
{
	int		value;
	int		lis;
	int		in_lis;
	int		len_lis;
	struct s_node	*up;
	struct s_node	*down;
}	t_node;

typedef	struct s_stack
{
	t_node	*top;
	t_node	*tail;
	int		len;
	int		len_lis;
}	t_stack;


// utils
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
int		ft_strcmp(char *s1, char *s2);
void	ft_flagLISelements(t_stack *stack);
void	ft_LIS(t_stack *stack);
int		ft_stack_is_sorted(t_stack stack_a);
int		max(int	a, int b);
int		min(int	a, int b);

void	ft_print_from_top_to_tail(t_stack stack);
void	ft_print_from_tail_to_top(t_stack stack);
void	ft_print_stack(t_stack stack, char *name);
void	ft_print_stack2(t_stack stack, char *name);
void	ft_print_stack_with_lis(t_stack stack, char *name);

// must implemted 
// int	ft_is_stack_already_sorted;

//pushinstack
int	ft_push(t_stack *stack, int value);

//rules
void	ft_swap_rule(t_stack *stack);
void	ft_push_rule(t_stack *stack_1, t_stack *stack_2);
void	ft_rotate_rule(t_stack *stack);
void	ft_reverse_rotate_rule(t_stack *stack);

int	ft_applay_move(char *move, t_stack *stack_a, t_stack *stack_b);

#endif

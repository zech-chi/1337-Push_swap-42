/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:00:34 by zech-chi          #+#    #+#             */
/*   Updated: 2023/12/19 21:26:39 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_stack
{
    int				*value;
    struct s_stack	*up;
    struct s_stack	*down;
}	t_stack;

char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);

void	ft_print_from_top_to_tail(t_stack *top);
void	ft_print_from_tail_to_top(t_stack *tail);
void	ft_print_stack(t_stack *top, char *name);
void	ft_print_stack2(t_stack *top, char *name);

// must implemted 
// int	ft_is_stack_already_sorted;

//pushinstack
void	ft_push(t_stack **top, t_stack **tail, int *value);

//rules
void	ft_swap_rule(t_stack **top, t_stack **tail);
void	ft_push_rule(t_stack **top1, t_stack **tail1, t_stack **top2, t_stack **tail2);
void	ft_rotate_rule(t_stack **top, t_stack **tail);
void	ft_reverse_rotate_rule(t_stack **top, t_stack **tail);


#endif

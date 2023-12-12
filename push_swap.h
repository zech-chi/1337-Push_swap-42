/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:00:34 by zech-chi          #+#    #+#             */
/*   Updated: 2023/12/12 16:23:38 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
    int				*value;
    struct s_stack	*up;
    struct s_stack	*down;
}	t_stack;

void	ft_print_from_top_to_tail(t_stack *top);
void	ft_print_from_tail_to_top(t_stack *tail);
void	ft_print_stack(t_stack *top, char *name);
void	ft_print_stack2(t_stack *top, char *name);


#endif
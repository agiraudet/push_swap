/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 17:31:04 by agiraude          #+#    #+#             */
/*   Updated: 2021/03/22 19:56:21 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct		s_stack
{
	struct s_stack	*next;
	int				data;
}					t_stack;

void				stack_print(t_stack *stack_a, t_stack *stack_b);
t_stack				*stack_create(int data);
void				stack_add(t_stack **stack, t_stack *new);
void				stack_swap(t_stack **stack);
t_stack				*stack_pop(t_stack **stack);
void				stack_push(t_stack **src, t_stack **dst);
t_stack				*stack_last(t_stack *stack);
t_stack				*stack_before_last(t_stack *stack);
void				stack_rotate(t_stack **stack);
void				stack_rev_rotate(t_stack **stack);
void				stack_free(t_stack **stack);
int					stack_is_sorted(t_stack *stack);

#endif

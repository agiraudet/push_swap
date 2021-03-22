/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 17:19:48 by agiraude          #+#    #+#             */
/*   Updated: 2021/03/22 19:51:15 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	stack_print(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			ft_putnbr(stack_a->data);
			stack_a = stack_a->next;
		}
		else
			ft_putchar(' ');
		ft_putchar(' ');
		if (stack_b)
		{
			ft_putnbr(stack_b->data);
			stack_b = stack_b->next;
		}
		else
			ft_putchar(' ');
		ft_putchar(' ');
		ft_putchar('\n');
	}
	ft_putendl("_ _\na b\n");
}

t_stack	*stack_create(int data)
{
	t_stack		*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->data = data;
	new->next = 0;
	return (new);
}

void	stack_add(t_stack **stack, t_stack *new)
{
	new->next = *stack;
	*stack = new;
}

void	stack_swap(t_stack **stack)
{
	t_stack		*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = tmp->next->next;
	(*stack)->next = tmp;
}

t_stack	*stack_pop(t_stack **stack)
{
	t_stack		*pop;

	pop = *stack;
	*stack = (*stack)->next;
	return (pop);
}

void	stack_push(t_stack **src, t_stack **dst)
{
	if (!src)
		return ;
	stack_add(dst, stack_pop(src));
}

t_stack	*stack_last(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*stack_before_last(t_stack *stack)
{
	if (!stack)
		return (0);
	if (!stack->next)
		return (0);
	while (stack->next->next)
		stack = stack->next;
	return (stack);
}

void	stack_rotate(t_stack **stack)
{
	t_stack		*last;

	if (!stack || !(*stack))
		return ;
	last = stack_last(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	last->next->next = 0;
}

void	stack_rev_rotate(t_stack **stack)
{
	t_stack		*bef_last;
	t_stack		*last;

	if (!stack || !(*stack))
		return ;
	bef_last = stack_before_last(*stack);
	last = bef_last->next;
	bef_last->next = 0;
	last->next = *stack;
	*stack = last;
}

void	stack_free(t_stack **stack)
{
	t_stack		*tmp;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

int		stack_is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

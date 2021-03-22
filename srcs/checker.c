/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 17:18:08 by agiraude          #+#    #+#             */
/*   Updated: 2021/03/22 19:44:19 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "push_swap.h"

int		exec_cmd(char *cmd, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(cmd, "sa") == 0)
		stack_swap(stack_a);
	else if (ft_strcmp(cmd, "sb") == 0)
		stack_swap(stack_b);
	else if (ft_strcmp(cmd, "ss") == 0)
	{
		stack_swap(stack_a);
		stack_swap(stack_b);
	}
	else if (ft_strcmp(cmd, "pa") == 0)
		stack_push(stack_b, stack_a);
	else if (ft_strcmp(cmd, "pb") == 0)
		stack_push(stack_a, stack_b);
	else if (ft_strcmp(cmd, "ra") == 0)
		stack_rotate(stack_a);
	else if (ft_strcmp(cmd, "rb") == 0)
		stack_rotate(stack_b);
	else if (ft_strcmp(cmd, "rr") == 0)
	{
		stack_rotate(stack_a);
		stack_rotate(stack_b);
	}
	else if (ft_strcmp(cmd, "rra") == 0)
		stack_rev_rotate(stack_a);
	else if (ft_strcmp(cmd, "rrb") == 0)
		stack_rev_rotate(stack_b);
	else if (ft_strcmp(cmd, "rrr") == 0)
	{
		stack_rev_rotate(stack_a);
		stack_rev_rotate(stack_b);
	}
	else
		return (0);
	return (1);
}

int		ft_isnumber(const char *str)
{
	if (!str)
		return (0);
	while (*str)
		if (!ft_isdigit(*str++))
			return (0);
	return (1);
}

t_stack	*parse_arg(int argc, char **argv)
{
	int		i;
	t_stack	*stack;

	stack = 0;
	i = argc - 1;
	while (i > 0)
	{
		if (!ft_isnumber(argv[i]))
		{
			stack_free(&stack);
			return (0);
		}
		stack_add(&stack, stack_create(ft_atoi(argv[i])));
		i--;
	}
	return (stack);
}

int		result(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_is_sorted(stack_a) || stack_b != 0)
	{
		ft_putendl("KO");
		return (0);
	}
	ft_putendl("OK");
	return (1);
}

char	*read_input(void)
{
	char		buffer[256];
	
	read(0, &buffer, 255);
	if (ft_strchr(buffer, '\n') == 0)
		return (0);
	return (ft_substr(buffer, 0, ft_strlen(buffer) - 1));
}

int		main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	char		*cmd;


	if (argc <= 1)
		return (0);
	stack_b = 0;
	stack_a = parse_arg(argc, argv);
	if (!stack_a)
	{
		ft_putendl_fd("Error", 2);
		exit(0);
	}
	while (get_next_line(0, &cmd) > 0)
	{
		if (!exec_cmd(cmd, &stack_a, &stack_b))
			ft_putendl_fd("Error", 2);
		free(cmd);
	}
	return (result(stack_a, stack_b));
}

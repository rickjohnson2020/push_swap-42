/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riyano <riyano@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:42:21 by riyano            #+#    #+#             */
/*   Updated: 2025/01/23 16:42:26 by riyano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap_top(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (stack->size < 2)
		return ;
	first = stack_pop_top(stack);
	second = stack_pop_top(stack);
	stack_push_top(first);
	stack_push_top(second);
}

void	sa(t_stack *a)
{
	swap_top(a);
	ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	swap_top(b);
	ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	swap_top(a);
	swap_tpo(b);
	ft_printf("ss\n");
}

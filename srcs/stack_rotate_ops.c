/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate_ops.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riyano <riyano@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:22:01 by riyano            #+#    #+#             */
/*   Updated: 2025/01/23 17:34:44 by riyano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	rotate_stack(t_stack *stack)
{
	t_node	*temp;

	if (stack->size < 2)
		return ;
	temp = stack_pop_top(stack);
	stack_push_bottom(stack, temp);
}

void	ra(t_stack *a)
{
	rotate_stack(a);
	printf("ra\n");
}

void	rb(t_stack *b)
{
	rotate_stack(b);
	printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	rotate_stack(a);
	rotate_stack(b);
	printf("rr\n");
}

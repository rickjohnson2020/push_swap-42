/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_r_rotate_ops.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riyano <riyano@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:39:03 by riyano            #+#    #+#             */
/*   Updated: 2025/01/23 17:45:08 by riyano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	r_rotate_stack(t_stack *stack)
{
	t_node	*temp;

	if (stack->size < 2)
		return ;
	temp = stack_pop_bottom(stack);
	stack_push_top(stack, temp);
}

void	rra(t_stack *a)
{
	r_rotate_stack(a);
	printf("rra\n");
}

void	rrb(t_stack *b)
{
	r_rotate_stack(b);
	printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	r_rotate_stack(a);
	r_rotate_stack(b);
	printf("rrr\n");
}

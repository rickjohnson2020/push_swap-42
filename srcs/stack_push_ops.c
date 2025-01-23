/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riyano <riyano@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:57:46 by riyano            #+#    #+#             */
/*   Updated: 2025/01/23 17:15:48 by riyano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pb(t_stack *a, t_stack *b)
{
	t_node	*temp;

	if (a->size == 0)
		return ;
	temp = stack_pop_top(a);
	stack_push_top(b, temp);
}

void	pa(t_stack *a, t_stack *b)
{
	t_node	*temp;

	if (b->size == 0)
		return ;
	temp = stack_pop_top(b);
	stack_push_top(a, temp);
}

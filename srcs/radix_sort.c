/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riyano <riyano@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:40:20 by riyano            #+#    #+#             */
/*   Updated: 2025/01/27 17:16:07 by riyano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_max_bits(t_stack *stack)
{
	int		max_num;
	int		bits;
//	t_node	*current;

//	max_num = 0;
//	current = stack->top;
//	while (current)
//	{
//		if (current->value > max_num)
//			max_num = current->next;
//		current = current->next;
//	}
	max_num = stack->size - 1;
	bits = 0;
	while ((max_num >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	i;
	int j;
	int	max_bits;
	int size;
	int	bit;

	max_bits = get_max_bits(a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < a->size)
		{
			bit = (a->top->value >> i) & 1;
			if (bit == 0)
				pb(a, b);
			else
				ra(a);
			j++;
		}
		i++;
	}
	while (b->size > 0)
		pa(a, b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riyano <riyano@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:33:53 by riyano            #+#    #+#             */
/*   Updated: 2025/01/28 17:24:38 by riyano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack *a)
{
	int	top;
	int	mid;
	int	bot;

	top = a->top->value;
	mid = a->top->next->value;
	bot = a->bottom->value;
	if (top > mid && top < bot)
		sa(a);
	else if (top < mid && top > bot)
		rra(a);
	else if (top < bot && mid > bot)
	{
		sa(a);
		ra(a);
	}
	else if (top > mid && top > bot && mid > bot)
	{
		sa(a);
		rra(a);
	}
	else if (top > mid && top > bot && mid < bot)
		ra(a);
}

//static void	push_back_a_4(t_stack *a, t_stack *b, int n)
//{
//	if (n == 0)
//		pa(a, b);
//	else if (n == 1)
//	{
//		ra(a);
//		pa(a, b);
//		rra(a);
//	}
//	else if (n == 2)
//	{
//		rotate_n_times(a, 2);
//		pa(a, b);
//		r_rotate_n_times(a, 2);
//	}
//	else if (n == 3)
//	{
//		pa(a, b);
//		ra(a);
//	}
//}

//static void	push_back_a_5(t_stack *a, t_stack *b, int n)
//{
//	if (n == 0 || n == 4)
//		pa(a, b);
//	if (n == 4)
//		ra(a);
//	else if (n == 1)
//	{
//		ra(a);
//		pa(a, b);
//		rra(a);
//	}
//	else if (n == 2)
//	{
//		rotate_n_times(a, 2);
//		pa(a, b);
//		r_rotate_n_times(a, 2);
//	}
//	else if (n == 3)
//	{
//		rotate_n_times(a, 3);
//		pa(a, b);
//		r_rotate_n_times(a, 3);
//	}
//}

static int	find_smallest_idx(t_stack *a)
{
	int		i;
	int		min_idx;
	int		min_val;
	t_node	*cur;

	i = 0;
	min_idx = 0;
	cur = a->top;
	min_val = cur->value;
	while (cur)
	{
		if (cur->value < min_val)
		{
			min_val = cur->value;
			min_idx = i;
		}
		cur = cur->next;
		i++;
	}
	return (min_idx);
}

static void	rotate_minimal(t_stack *a, int idx, int size)
{
	int	i;

	i = 0;
	if (idx <= size / 2)
	{
		while (i < idx)
		{
			ra(a);
			i++;
		}
	}
	else
	{
		while (i < (size - idx))
		{
			rra(a);
			i++;
		}
	}
}

static void	push_smallest_to_b(t_stack *a, t_stack *b)
{
	int	idx;
	int	size;

	idx = find_smallest_idx(a);
	size = a->size;
	rotate_minimal(a, idx, size);
	pb(a, b);
}

void	sort_four(t_stack *a, t_stack *b)
{
	push_smallest_to_b(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack *a, t_stack *b)
{
	push_smallest_to_b(a, b);
	push_smallest_to_b(a, b);
	sort_three(a);
//	if (b->size == 2 && b->top->value > b->top->next->value)
//		sb(b);
	pa(a, b);
	pa(a, b);
}

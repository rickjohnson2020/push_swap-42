/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riyano <riyano@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:57:09 by riyano            #+#    #+#             */
/*   Updated: 2025/01/28 17:33:07 by riyano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include "../includes/push_swap.h"
#include "../libft/libft.h"

long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] == '\0')
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		result = result * 10 + (str[i] - '0');
		if ((sign == 1 && result > INT_MAX) ||
			(sign == -1 && result < INT_MIN))
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (result * sign);
}

int	count_tokens(int argc, char **argv)
{
	int i;
	int j;
	int count;
	char **split;

	count = 0;
	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		j = 0;
		while (split[j])
		{
			count++;
			j++;
		}
		j = 0;
		while (split[j])
			free(split[j++]);
		free(split);
		i++;
	}
	return (count);
}

int	find_index(int *sorted, int n, int value)
{
	int	left;
	int	right;
	int	mid;

	left = 0;
	right = n - 1;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (sorted[mid] == value)
			return (mid);
		else if (sorted[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (-1);
}

int	parse_args(int **arr, int argc, char **argv)
{
	int		total;
	int		i;
	int		j;
	int		index;
	long	val;
	char	**split;

	if (argc < 2)
		return (0);
	total = count_tokens(argc, argv);
	if (total == 0)
		return (0);
	*arr = (int *)malloc(sizeof(int) * total);
	if (!*arr)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	index = 0;
	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		j = 0;
		while (split[j])
		{
			val = ft_atol(split[j]);
			(*arr)[index] = (int)val;
			index++;
			j++;
		}
		j = 0;
		while (split[j])
			free(split[j++]);
		free(split);
		i++;
	}
	return (total);
}

#include <stdio.h>
int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		*arr;
	int		*sorted;
	int		n;
	int		i;
	t_node	*node;

	n = parse_args(&arr, argc, argv);

	sorted = malloc(sizeof(int) * n);
	i = 0;
	while (i < n)
	{
		sorted[i] = arr[i];
		i++;
	}
	quick_sort(sorted, 0, n - 1);

	// check if there is no duplicate
	i = 0;
	while (i < n - 1)
	{
		if (sorted[i] == sorted[i + 1])
		{
			write(2, "Error\n", 6);
			free(arr);
			free(sorted);
			return (1);
		}
		i++;
	}

	// value -> index
	i = 0;
	while (i < n)
	{
		arr[i] = find_index(sorted, n, arr[i]);
		i++;
	}

	//initialize satcks
	init_stack(&a);
	init_stack(&b);

	i = 0;
	while (i < n)
	{
		node = create_node(arr[i++]);
		stack_push_bottom(&a, node);
	}
	if (a.size == 2)
	{
		if (a.top->value > a.bottom->value)
			sa(&a);
	}
	else if (a.size == 3)
		sort_three(&a);
	else if (a.size == 4)
		sort_four(&a, &b);
	else if (a.size == 5)
		sort_five(&a, &b);
	else
		radix_sort(&a, &b);


	while (a.top)
	{
		printf("%d\n", a.top->value);
		a.top = a.top->next;
	}
	
	free(arr);
	free_stack(&a);
	free_stack(&b);
	return (0);
}

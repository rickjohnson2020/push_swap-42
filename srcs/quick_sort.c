/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riyano <riyano@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:31:40 by riyano            #+#    #+#             */
/*   Updated: 2025/01/27 17:31:59 by riyano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	swap(int *i , int *j)
{
	int temp = *i;
	*i = *j;
	*j = temp;
}

static int	partition(int arr[], int l, int  r)
{
	int pivot = arr[r];
	int i = l - 1;
	int j = l;
	while (j < r)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
		j++;
	}
	swap(&arr[i + 1], &arr[r]);
	return (i + 1);
}

void	quick_sort(int *arr, int l, int r)
{
	int	p;

	if (l >= r)
		return ;
	p = partition(arr, l, r);
	quick_sort(arr, l, p - 1);
	quick_sort(arr, p + 1, r);
}
//
//#include <stdio.h>
//int	main()
//{
//	int arr[] = {3, 5, 2, 6, 9, -2, 0};
//	int i = 0;
//	while (i < 7)
//	{
//		printf("%d\n", arr[i++]);
//	}
//	printf("=========\n");
//	qs(arr, 0, 6);
//	i = 0;
//	while (i < 7)
//	{
//		printf("%d\n", arr[i++]);
//	}
//	return 0;
//}

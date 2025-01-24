

void	swap(int *i , int *j)
{
	int temp = *i;
	*i = *j;
	*j = temp;
}

int	partition(int arr[], int l, int  r)
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

void	qs(int *arr, int l, int r)
{
	if (l >= r)
		return ;
	int p = partition(arr, l, r);
	qs(arr, l, p - 1);
	qs(arr, p + 1, r);
}

#include <stdio.h>
int	main()
{
	int arr[] = {3, 5, 2, 6, 9, -2, 0};
	int i = 0;
	while (i < 7)
	{
		printf("%d\n", arr[i++]);
	}
	printf("=========\n");
	qs(arr, 0, 6);
	i = 0;
	while (i < 7)
	{
		printf("%d\n", arr[i++]);
	}
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS 

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "stack.h"

void InsertSort(int* a, int n);
void ShellSort(int* a, int n);

void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
	
}

void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}	
}

void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

//选择排序
void SelectSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		int min = i;
		for (int j = i; j < n; j++)
		{
			
			if (a[j] < a[min] )
			{
				min = j;
			}
		}
		Swap(&a[min], &a[i]);
	}
}

//冒泡排序
void BuobleSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < n - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
			}
		}
		
	}
}

//推排序
void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (a[child] < a[child + 1] && child + 1 < n)
		{
			child++;
		}
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* a, int n)
{
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	int i = 1;
	while (i < n)
	{
		Swap(&a[0], &a[n - i]);
		AdjustDown(a, n - i, 0);
		i++;
	}
}

//快速排序  
//递归
int GetMidIndex(int* a, int left, int right)
{
	int mid = (left + right) / 2;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] > a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left] < a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}

int PartSort1(int* a, int left, int right)
{
	int mid = GetMidIndex(a, left, right);
	Swap(&a[left], &a[mid]);

	int keyi = left;
	while (left < right)
	{
		while (a[right] >= a[keyi] && right > left)
		{
			right--;
		}
		while (a[left] <= a[keyi] && right > left)
		{
			left++;
		}
		if (left < right)
		{
			Swap(&a[left], &a[right]);
		}
	}
	Swap(&a[keyi], &a[left]);
	return left;
}

int PartSort2(int* a, int left, int right)
{
	int mid = GetMidIndex(a, left, right);
	Swap(&a[left], &a[mid]);

	int key = a[left];
	int hole = left;
	while (left < right)
	{
		while (a[right] >= key && left < right)
		{
			right--;
		}
		a[hole] = a[right];
		hole = right;
		while (a[left] <= key && left < right)
		{
			left++;
		}
		a[hole] = a[left];
		hole = left;
	}
	a[hole] = key;
	return left;
}

int PartSort3(int* a, int left, int right)
{
	int mid = GetMidIndex(a, left, right);
	Swap(&a[left], &a[mid]);

	int prev = left;
	int cur = left + 1;
	int keyi = left;
	while (cur <= right)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
		{
			Swap(&a[prev], &a[cur]);
		}
		cur++;
	}
	Swap(&a[keyi], &a[prev]);
	return prev;
}

void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}
	if (end - begin <= 8)
	{
		InsertSort(a + begin, end - begin + 1);
	}
	int keyi = PartSort1(a, begin, end);
	//int keyi = PartSort2(a, begin, end);
	//int keyi = PartSort3(a, begin, end);
	QuickSort(a, begin, keyi - 1);
	QuickSort(a, keyi + 1, end);
}

//非递归
void QuickSortNonR(int* a, int begin, int end)
{
	ST st;
	StackInit(&st);

	StackPush(&st, begin);
	StackPush(&st, end);

	while (!StackEmpty(&st))
	{
		int right = StackTop(&st);
		StackPop(&st);

		int left = StackTop(&st);
		StackPop(&st);

		if (left >= right)
		{
			continue;
		}

		int keyi = PartSort1(a, left, right);
		if (keyi + 1 < right)
		{
			StackPush(&st, keyi + 1);
			StackPush(&st, right);
		}
		if (left < right - 1)
		{
			StackPush(&st, left);
			StackPush(&st, keyi - 1);
		}
	}
	StackDestroy(&st);
}


int main()
{
	int a[] = { 5,4,9,8,1,6,2,3,7,0 };
	int n = sizeof(a) / sizeof(a[0]);

	//InsertSort(a, n);
	//ShellSort(a, n);
	//SelectSort(a, n);
	//BuobleSort(a, n);
	//HeapSort(a, n);
	//QuickSort(a, 0, n - 1);
	QuickSortNonR(a, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}

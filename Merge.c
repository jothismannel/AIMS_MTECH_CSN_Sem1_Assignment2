/*
 * Merge.c
 *
 *	Program to implement merge sort
 *	input: input array and size of array
 *	output: sorted array
 *
 *  Created on: 07-Oct-2012
 */
#include<stdio.h>
#include<math.h>
#include<time.h>
#include <process.h>

void merge(int *, int, int);
void simplemerge(int *, int, int, int);

int temp[10];

int main()
{

	int array[10], *temp_array, limit, i, start, finish;

	printf("Enter the limit \n");
	scanf("%d", &limit);

	
	//reading array
	for (i = 0; i < limit; i++)
	{
		scanf("%d",&array[i]);
	}

	temp_array = array;
	start = 0;
	finish = i-1;
	
	merge(temp_array, start, finish);
	
	for (i = 0; i < limit; i++)
	{
		printf("%d\t",temp_array[i]);
	}

return 0;

}


//spliting array into subarrays
void merge(int *temp_array, int start, int finish)
{
	int size, middle;
	size = finish - start +1 ;

	if (size <= 1)
	{
		return;
	}

	middle = start+ceilf((size / 2))-1;

	merge(temp_array, start, middle);
	merge(temp_array, middle + 1, finish);
	simplemerge(temp_array, start, middle + 1, finish);

	return;
}


/* Merging two subarrays and sorting */
void simplemerge(int *temp_array, int first, int second, int third)
{
	int i, j, l = 0,k;
	i = first;
	j = second;

	while ((i < second) && (j <= third))
	{
		if (temp_array[i] <= temp_array[j])
		{
			temp[l] = temp_array[i];
			i += 1;
			l = l + 1;
		} else
		{
			temp[l] = temp_array[j];
			l += 1;
			j = j + 1;
		}
	}
	if (i >= second)
	{
		while (j <= third)
		{
			temp[l] = temp_array[j];
			l += 1;
			j = j + 1;
		}
	}
	else
	{
		while (i < second)
		{
			temp[l] = temp_array[i];
			l = l + 1;
			i = i+1;
		}
	}
	for(k = 0;k < l;k++)
	{
		temp_array[first + k]=temp[k];
	}
}

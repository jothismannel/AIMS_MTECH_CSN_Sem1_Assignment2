/*
 * Bubblesort.c
 *
 *
 *	Program to implement bubble sort
 *	input: input array and its size
 *	output: sorted array
 *
 *  Created on: 07-Oct-2012
 */

#include<stdio.h>
#include<conio.h>


int main() 
{

	int array[100], limit, i , j, temp;

	printf("Enter the limit :\n");
	scanf("%d", &limit);

	for (i = 0; i <= limit - 1; i++)
	{
		scanf("%d", &array[i]);
	}
	
	
	//Bubblesort	
	for (i = limit - 2; i >= 0; i--)
	{
		for (j = 0; j <= i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				
				//swapping
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}

	printf("\n sorted array is: ");

	//displaying sorted array
	for (i = 0; i <= limit - 1; i++)
	{
		printf("%d \t", array[i]);
	}

return 0;
}

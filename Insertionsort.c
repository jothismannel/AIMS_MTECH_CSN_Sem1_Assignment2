/*
 * insertionsort.c
 *
 *  program to implement insertion sort
 *  input :limit
 *  output:sorted array
 *     
 *  Created on: 07-Oct-2012
 */
#include<stdio.h>

int main() {
	
	int array[10], limit, key, j, i,temp;
	scanf("%d",&limit);
	
	
	//reading array
	for (i = 0; i < limit; i++) 
	{
		scanf("%d",&array[i]);
	}
	
	for(j = 1;j < limit;j++)
	{
		key = array[j];
		i  = j - 1;
		
		while(array[i] > key && i >= 0)
		{
			temp = array[i+1];
			
			//swapping
			array[i+1] = array[i];
			array[i] = temp;
			i--;
		}
		
	}
	
	
	//display
	for(i = 0; i < limit ;i++)
	{
		printf("%d\t",array[i]);
	}
	return 0;
}

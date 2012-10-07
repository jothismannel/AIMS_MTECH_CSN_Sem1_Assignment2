/*
 * stack.c
 *
 *	Program to implement a static stack 
 *	input: size_of_stack
 *	output: performs stack operation PUSH and POP operation
 *
 *  Created on: 04-Oct-2012
 *     
 */



#include<stdio.h>
#include<conio.h>

void push_operation();
void pop_operation();

int stack[20],size_of_stack,length;

int main() 
{

	char choice;
	length=0;


	printf("Enter the size of stack: ");		
	scanf("%d", &size_of_stack);			//reading the size of stack


	printf("\n a.Push Operation ");
	printf("\n b.Pop Operation ");
	printf("\n Press $ to exit ");
	
	do
	{
		printf("\n Enter the choice: ");
		scanf("%c",&choice);

		if(choice == 'a')
		{
			push_operation();
		}
		else if(choice == 'b')
		{
			pop_operation();
		}
		else if(choice !='a' && choice !='b' && choice !='$')
		{
			printf("\n Invalid option");
		}
	}while(choice != '$');

	return 0;
}

void push_operation()
{

	int data,i;
	
	length = length + 1;
	
	//checking overflow condition
	if(length > size_of_stack)
	{
		printf("\n STACK OVERFLOW ");
		length=length - 1;
		return;
	}

	printf("\nEnter the data :");
	scanf("%d",&data);

	stack[length-1] = data;

	printf("Stack Content :");
	for(i = 0;I < length;i++)
	{
		printf("%d\t",stack[i]);
	}
	return;
}

void pop_operation()
{
	int i;

	
	//checking underflow condition
	if(length <= 0)
	{
		printf(" \nSTACK UNDERFLOW ");
		return;
	}

	printf("\n Poped data : %d", stack[length-1]);
	length = length - 1;

	printf("\n Stack Content :");
	for(i = 0;i < length;i++)
	{
		printf("%d\t",stack[i]);
	}
}

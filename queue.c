/*
 * queue.c
 *
 *	Program to implement a static queue
 *	input: size
 *	output: performs insertion and deletion from queue
 *
 *  Created on: 07-Oct-2012
 *
 */

# include <stdio.h>

int queue[10], front_pointer = -1, rear_pointer = -1, i, size;

void q_Insert();
void q_Delete();
void q_Display();

int main() 
{
	int choice;

	printf("Enter the size of queue\n");		//reading size of queue
	scanf("%d", &size);

	do {
		printf("\n1.INSERT 2.DELETE 3.DISPLAY 4.Exit\n");
		printf("Enter your choice : ");
		scanf("%d", &choice);

		switch (choice)
		{

			
			//Enqueue operation
			case 1:
				q_Insert();
				break;

			

			//Dequeue operation
			case 2:
				q_Delete();
				break;

			case 3:
				q_Display();
				break;

			case 4:
				break;

			default:
				printf("Invalid option\n");
				break;
		}
	} while (choice != 4);
}

void q_Insert()
{
		
		//Checking queue overflow
		if (rear_pointer == size - 1)
		{
			printf("Queue overflow\n");
			return;
		}

	rear_pointer += 1;
	printf("Enter the element : ");
	scanf("%d", &queue[rear_pointer]);

	if (front_pointer == -1)
	{
		front_pointer++;
	}
}

void q_Delete() 
{
	
	//checking queue underflow
	if (front_pointer == -1) 
	{
		printf("QUEUE UNDERFLOW \n");
		return;
	}

	printf("Element Removed : %d\n", queue[front_pointer]);

	if (front_pointer == rear_pointer)
	{
		front_pointer = rear_pointer = -1;
	}
	else
	{
		front_pointer++;
	}

}

void q_Display()
{
	
	//checking queue is empty 
	if (front_pointer == -1)
	{
		printf("Queue is empty \n");
		return;
	}

	printf("The elements in queue are : ");

	for (i = front_pointer; i <= rear_pointer; i++)
	{
		printf("%d\t", queue[i]);
	}

}

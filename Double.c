/*
 *  Double.c
 *
 *
 *	Program to implement doubly linked list
 *	input: choice
 *	output: performs insertion deletion in doubly linked list
 *
 *  Created on: 07-Oct-2012
 */


#include <stdlib.h>
#include<stdio.h>

struct node {
 int data;
 struct node *next, *prev;
};

struct node * DoubleLS_InsFront(struct node *, int);
struct node * DoubleLS_InsBefore(struct node *, int, int);
struct node * DoubleLS_DelNode(struct node *, int);
void DoubleLS_Display(struct node *);

int main()
{

	struct node *start = NULL;					/* Main Program */
	int option, elem, info, limit, i;
	do
	{
		printf("\n Press 1-Creation with front Insertion 2-Insert Before a Given Node 3-Delete a Given Node 4-Display 5-Exit\n");
		scanf("%d", &option);
		switch (option)
		{
			case 1:
				printf("\n\nEnter number of elements");
				scanf("%d", &limit);

				for (i = 1; i <= limit; i++)
				{
					scanf("%d", &elem);
					start = DoubleLS_InsFront(start, elem);
				}
			break;

			case 3:

				printf(" Enter the data to be deleted ");
				scanf("%d", &info);
				start = DoubleLS_DelNode(start, info);
			break;

			case 2:
				printf("Enter Data for New node\n");
				scanf("%d", &elem);
				printf("Enter the data of the Node which comes after the new node:\n ");
				scanf("%d", &info);
				start = DoubleLS_InsBefore(start, elem, info);
			break;

			case 4:
				printf(" Doubly Linked List is \n");
				DoubleLS_Display(start);
			break;

			case 5:
				break;
			break;

			default:
				printf("Invalid Option\n");
			break;
		}
	} while (option != 5);

return 0;
}

struct node *DoubleLS_InsFront(struct node *start, int elem)
{
	struct node *temp;
	temp = (struct node *) malloc(sizeof(struct node));
	if (temp == NULL)
	{
		printf(" Out of Memory!");
		return (start);
	}
	else
	{
		temp->data = elem;
		temp->prev = NULL;
		temp->next = start;
		start->prev = temp;
		return (temp);
	}
}

struct node *DoubleLS_InsBefore(struct node *start, int elem, int info)
{
	struct node *temp, *t;
	temp = (struct node *) malloc(sizeof(struct node));
	if (temp == NULL)
	{
		printf(" Out of Memory!");
		return (start);
	}
	else
	{
		temp->data = elem;
		temp->next = NULL;
		temp->prev = NULL;

		if (start->data == info)				/* Front Insertion */
		{
			temp->next = start;
			start->prev = temp;
			return (temp);
		}
		else
		{
			t = start;
			while (t != NULL && t->data != info)
			{
				t = t->next;
			}
			if (t->data == info)				/* Node found */
			{
				temp->next = t;
				temp->prev = t->prev;
				t->prev->next = temp;
				t->prev = temp;
			} else
			{
				printf(" Node not found !");
			}
			return (start);
		}
	}
}

struct node *DoubleLS_DelNode(struct node *start, int info)
{
	struct node *t;
	if (start == NULL)
	{
		printf(" Underflow!");
		return (start);
	}
	else
	{
		t = start;
		if (start->data == info)				/* Front Deletion */
		{
			start = start->next;
			start->prev = NULL;
			t->next = NULL;
			free(t);
			return (start);
		}
		else
		{
			while (t != NULL && t->data != info)
				t = t->next;
			if (t->data == info)				/* node to be deleted  found*/
			{
				t->prev->next = t->next;
				t->next->prev = t->prev;
				t->next = t->prev = NULL;
				free(t);
			}
			else
			{
				printf("Node not found");
			}
				return (start);
		}
	}
}

void DoubleLS_Display(struct node *start)
{
	struct node *t;
	if (start == NULL)
	{
		printf("Empty List\n");
	}
	else
	{
		t = start;
		while (t)
		{
			printf("%d\t", t->data);
			t = t->next;
		}
		printf("Null\n");
	}
}

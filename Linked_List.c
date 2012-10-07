/*
 * Linked_List.c
 *
 *
 *	Program to implement singly linked list
 *	input: choice
 *	output: performs insertion deletion in linked list
 *
 *  Created on: 07-Oct-2012
 */

#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int info;
	struct node *next;
}*head;

void insert_at_beg(int);
void insert_at_last(int);
void insert_at_middle(int,int);
void delete_operation(int);
void display_list();

int main() 
{
	int choice,data,location;

	printf("Enter the choice \n");
	

	do {
		printf("1.Insert at beginning 2.Insert at middle 3.Insert at last 4.Delete a node 5.Display  6.Exit \n");
		scanf("%d", &choice);

		if (choice == 1)
		{
			printf("Enter the data :\n");
			scanf("%d",&data);
			insert_at_beg(data);
		}
		else if (choice == 2)
		{
			printf("Enter the data :\n");
			scanf("%d",&data);

			printf("Enter the position :\n");
			scanf("%d",&location);

			insert_at_middle(data,location);
		}
		else if (choice == 3)
		{
			printf("Enter the data :\n");
			scanf("%d",&data);

			insert_at_last(data);
		}
		else if (choice == 4)
		{
			printf("Enter the data :\n");
			scanf("%d",&data);
			
			delete_operation(data);
		}
		else if (choice == 5)
		{
			display_list();
		}
		else if (choice == 6)
		{
			break;
		}
		else
		{
			printf("Invalid choice\n");
		}

	} while (choice != 5);

return 0;
}

int length()
{
   struct node *cur_ptr;
   int count = 0;

   cur_ptr = head;

   while(cur_ptr != NULL)
   {
      cur_ptr = cur_ptr->next;
      count++;
   }
   return(count);
}

void insert_at_beg(int data)
{
	struct node *temp;

	temp = (struct node *) malloc(sizeof(struct node));
	temp->info = data;

	if (head == NULL )
	{
		head = temp;
		head->next = NULL;
	}
	else
	{
		temp->next = head;
		head = temp;
	}
}

void insert_at_middle(int data, int loc)
{
   int i;
   struct node *temp, *prev_ptr, *cur_ptr;

   cur_ptr = head;

   if(loc > (length()+1) || loc <= 0)
   {
      printf("\nInsertion at given location is not possible\n ");
   }
   else
   {
       // If the location is starting of the list
       if (loc == 1)
       {
           insert_at_beg(data);
       }
       else
       {
           for(i = 1;i < loc;i++)
           {
               prev_ptr = cur_ptr;
               cur_ptr = cur_ptr->next;
           }

           temp = (struct node *)malloc(sizeof(struct node));
           temp->info = data;

           prev_ptr->next = temp;
           temp->next = cur_ptr;
       }
   }
}

void insert_at_last(int num)
 {
    struct node *temp1, *temp2;

    temp1 = (struct node *)malloc(sizeof(struct node));
    temp1->info = num;

    // Copying the Head location into another node.
    temp2 = head;

    if(head == NULL)
    {
       // If List is empty we create First Node.
       head = temp1;
       head->next = NULL;
    }
    else
    {
       // Traverse down to end of the list.
       while(temp2->next != NULL)
       temp2 = temp2->next;

       // Append at the end of the list.
       temp1->next = NULL;
       temp2->next = temp1;
    }
 }




void delete_operation(int num)
{
   struct node *prev_ptr, *cur_ptr;

   cur_ptr=head;

   while(cur_ptr != NULL)
   {
      
      //checking data of node equals the data to be deleted	
      if(cur_ptr->info == num)
      {
         if(cur_ptr == head)
         {
            head = cur_ptr->next;
            free(cur_ptr);
         }
         else
         {
            prev_ptr->next = cur_ptr->next;
            free(cur_ptr);
         }
      }
      else
      {
         prev_ptr = cur_ptr;
         cur_ptr = cur_ptr->next;
      }
   }

   printf("\n%d is not found ", num);
   
}

void display_list()
{
   struct node *cur_ptr;

   cur_ptr = head;

   if(cur_ptr == NULL)
   {
      printf("\nList is Empty");
   }
   else
   {
       printf("Elements in the List: ");
       
	//traverse the entire linked list
       while(cur_ptr!=NULL)
       {
           printf("%d \t",cur_ptr->info);
           cur_ptr = cur_ptr->next;
       }
       printf("\n");
   }
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void insert_beg(int num);
void insert_end(int num);
void insert_at_node(int num,int loc);
void insert_after_value(int num, int val);
void delete_beg();
void delete_end();
void delete_node(int loc);
void delete_value(int num);
void replace_value(int num,int val);
void replace_node(int num, int loc);
void sortlist();
void display();
void clear(void);

typedef struct dlist
{
	int info;
	struct dlist* next;
	struct dlist* prev;
}dlist;

dlist *start = NULL,*curr = NULL, *node = NULL, *pre = NULL;

int main()
{
	int n,a,b;
	printf("WELCOME TO THE LINKED LIST APPLICATION\n");
	clear();
	usleep(500000);
	
	do
	{
		clear();
		usleep(500000);
		
		printf("1. Insert at beginning\n");
		printf("2. Insert at end\n");
		printf("3. Insert at a particular location\n");
		printf("4. Insert after a particular value\n");
		printf("5. Delete a number from beginning of list\n");
		printf("6. Delete a number from end of list\n");
		printf("7. Delete a particular node in the list\n");
		printf("8. Delete a particular value in the list\n");
		printf("9. Replace a particular value with another in a list\n");
		printf("10. Replace a particular node in the list\n");
		printf("11. Sort the list in ascending order\n");
		printf("12. Display\n");
		printf("13. Quit\n");
		
		printf("Select the operation you want to perform (9 to Quit): ");
		scanf("%d",&n);
		
		switch(n)
		{
			case 1:
					printf("Enter the number you want to insert: ");
					scanf("%d",&a);
					insert_beg(a);
					break;
			case 2:
					printf("Enter the number you want to insert: ");
					scanf("%d",&a);
					insert_end(a);
					break;
			case 3:
					printf("Enter the number you want to insert: ");
					scanf("%d",&a);
					printf("Enter the location in which to insert: ");
					scanf("%d",&b);
					insert_at_node(a,b);
					break;
			case 4:
					printf("Enter the number you want to insert: ");
					scanf("%d",&a);
					printf("Enter the value after which to insert: ");
					scanf("%d",&b);
					insert_after_value(a,b);
					break;
			case 5:
					delete_beg();
					break;
			case 6:
					delete_end();
					break;
			case 7:
					printf("Enter the location of node to delete: ");
					scanf("%d",&a);
					delete_node(a);
					break;
			case 8:
					printf("Enter the value you want to delete: ");
					scanf("%d",&a);
					delete_value(a);
					break;
			case 9:
					printf("Enter the value you want to replace: ");
					scanf("%d",&a);
					printf("Enter the new value: ");
					scanf("%d",&b);
					replace_value(a,b);
					break;
			case 10:
					printf("Enter the node location you want to replace: ");
					scanf("%d",&a);
					printf("Enter the new number: ");
					scanf("%d",&b);
					replace_node(a,b);
					break;
			case 11:
					sortlist();
					break;
			case 12:
					display();
					usleep(5000000);
					break;
			case 13:
					break;
		}		
	}while(n!=13);
}

void insert_beg(int num)
{
	if(start == NULL)
	{
		node = (dlist*)malloc(sizeof(dlist*));
		node->info = num;
		node->next = NULL;
		node->prev = NULL;
		start = node;
	}
	else
	{
		node = (dlist*)malloc(sizeof(dlist*));
		node->info = num;
		node->prev = NULL;
		node->next = start;
		start->prev = node;
		start = node;
	}
}

void insert_end(int num)
{
	if(start == NULL)
	{
		node = (dlist*)malloc(sizeof(dlist*));
		node->info = num;
		node->next = NULL;
		node->prev = NULL;
		start = node;
	}
	else
	{
		node = (dlist*)malloc(sizeof(dlist*));
		node->info = num;
		node->next = NULL;
		curr = start;
		while(curr->next != NULL)
			curr = curr->next;
		curr->next = node;
		node->prev = curr;
	}
}

void insert_at_node(int num,int loc)
{
	if(start == NULL)
	{
		node = (dlist*)malloc(sizeof(dlist*));
		node->info = num;
		node->next = NULL;
		node->prev = NULL;
		start = node;
	}
	else
	{
		node = (dlist*)malloc(sizeof(dlist*));
		node->info = num;
		curr = start;
		int i=1;
		while(curr != NULL && i < loc)
		{
			pre = curr;
			curr = curr->next;
			i++;
		}
		pre->next = node;
		node->next = curr;
		node->prev = pre;
		curr->prev = node;
	}
}

void insert_after_value(int num, int val)
{
	if(start == NULL)
	{
		node = (dlist*)malloc(sizeof(dlist*));
		node->info = num;
		node->next = NULL;
		node->prev = NULL;
		start = node;
	}
	else
	{
		node = (dlist*)malloc(sizeof(dlist*));
		node->info = num;
		curr = start;
		while(curr != NULL && curr->info != val)
		{
			curr = curr->next;
		}
		node->next = curr->next;
		curr->next->prev = node;
		curr->next = node;
		node->prev = curr;
	}
}

void delete_beg()
{
	curr = start;
	start = start->next;
	start->prev = NULL;
	free(curr);
}

void delete_end()
{
	curr = start;
	while(curr->next != NULL)
	{
		pre = curr;
		curr = curr->next;
	}
	pre->next = NULL;
	free(curr);
}

void delete_node(int loc)
{
	curr = start;
	int i = 1;
	while(curr != NULL && i<loc)
	{
		pre = curr;
		curr = curr->next;
		i++;
	}
	pre->next = curr->next;
	curr->next->prev = pre;
	free(curr);
}

void delete_value(int num)
{
	curr = start;
	while(curr != NULL && curr->info != num)
	{
		pre = curr;
		curr = curr->next;
	}
	pre->next = curr->next;
	curr->next->prev = pre;
	free(curr);
}

void replace_value(int num,int val)
{
	curr = start;
	while(curr != NULL && curr->info != num)
	{
		curr = curr->next;
	}
	curr->info = val;
}

void replace_node(int loc, int num)
{
	curr = start;
	int i = 1;
	while(curr != NULL && i<loc)
	{
		curr = curr->next;
		i++;
	}
	curr->info = num;
}

void sortlist()
{/
	for(curr=start;curr!= NULL;curr=curr->next)
	{
		for(pre=curr->next; pre!=NULL; pre=pre->next)
		{
			if((curr->info > pre->info))
			{
				int temp = curr->info;
				curr->info = pre->info;
				pre->info = temp;
			}
		}
	}
}

void display()
{
	curr = start;
	while(curr != NULL)
	{
		printf("%d\n",curr->info);
		curr = curr->next;
	}
}

void clear(void)
{
	printf("\033[2J");
	printf("\033[%d;%dH",0,0);
}















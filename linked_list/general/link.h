#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
	int info;
	struct list* next;
}list;

list *start=NULL,*node=NULL,*curr=NULL,*prev=NULL;

void insert_beg(int);
void insert_end(int);
void insert_at_loc(int,int);
void insert_after_value(int,int);
void delete_beg();
void delete_end();
void delete_node(int);
void delete_value(int);
void replace_node(int,int);
void replace_value(int,int);
void delete_dup_vals();
int length();
void display();
void reverse();
void clear(void);
void sortlist();

void insert_beg(int num)
{
	node = (list*)malloc(sizeof(list*));
	node->info = num;
	
	if(start == NULL)
	{
		node->next = NULL;
		start = node;
	}
	else
	{
		node->next = start;
		start = node;
	}
}

void insert_end(int num)
{
	node = (list*)malloc(sizeof(list*));
	node->info = num;
	node->next = NULL;
	
	if(start == NULL)
		start = node;
	else
	{
		curr = start;
		while(curr->next!=NULL)
		{
			curr=curr->next;
		}
		curr->next=node;
	}
}

void insert_at_loc(int num,int loc)
{
	int n = length();
	if(loc > n || loc < 0)
	{
		printf("Location is invalid!! Try again\n");
		return;
	}
	node = (list*)malloc(sizeof(list*));
	node->info = num;
	node->next = NULL;
	
	if(start == NULL)
		start = node;
	else
	{
		curr = start;
		int i = 1;
	
		while(curr != NULL && i<loc)
		{
			prev = curr;
			curr = curr->next;
			i++;
		}

		prev->next = node;
		node->next = curr;
	}
}

void insert_after_value(int num,int val)
{
	node = (list*)malloc(sizeof(list*));
	node->info = num;
	
	if(start == NULL)
		start = node;
	else
	{
		curr = start;
		while(curr != NULL && curr->info != val)
			curr=curr->next;
		
		if(curr == NULL)
		{
			printf("Value was not found!! Try again\n");
			return;
		}
		node->next = curr->next;
		curr->next = node;
	}
}

void delete_beg()
{
	if(start == NULL)
	{
		printf("List is empty\n");
		return;
	}
	curr = start;
	start = curr->next;
	free(curr);
}

void delete_end()
{
	if(start == NULL)
	{
		printf("List is empty\n");
		return;
	}
	curr = start;
	while(curr->next != NULL)
	{
		prev = curr;
		curr = curr->next;
	}
	prev->next = NULL;
	free(curr);
}

void delete_node(int num)
{
	int n = length();
	
	if(num > n || num < 0)
	{
		printf("Location is invalid!! Try again\n");
		return;
	}
	
	if(start == NULL)
	{
		printf("List is empty\n");
		return;
	}
	curr = start;
	int i = 1;
	while(curr != NULL && i < num)
	{
		prev = curr;
		curr = curr->next;
		i++;
	}
	prev->next = curr->next;
	free(curr);
}

void delete_value(int num)
{
	if(start == NULL)
	{
		printf("List is empty\n");
		return;
	}
	curr = start;
	if(start->info == num)
	{
		start = start->next;
		free(curr);
	}
	curr = start;
	while(curr != NULL && curr->info != num)
	{
		prev = curr;
		curr = curr->next;
	}
	
	if(curr == NULL)
	{
		printf("Value not found! Try again\n");
		return;
	}
	prev->next = curr->next;
	free(curr);
}

void replace_node(int num, int loc)
{
	int n = length();
	
	if(loc > n || loc < 0)
	{
		printf("Location is invalid!! Try again\n");
		return;
	}
	
	if(start == NULL)
	{
		printf("List is empty\n");
		return;
	}
	curr = start;
	int i = 1;
	
	while(curr != NULL && i < loc)
	{
		curr = curr->next;
		i++;
	}
	curr->info = num;
}

void replace_value(int num, int val)
{
	if(start == NULL)
	{
		printf("List is empty\n");
		return;
	}
	curr = start;
	while(curr != NULL && curr->info != val)
		curr = curr->next;
	if(curr == NULL)
	{
		printf("Value not found! Try again\n");
		return;
	}
	curr->info = num;
}

void delete_dup_vals()
{
	if(start == NULL)
	{
		printf("List is empty\n");
		return;
	}
	sortlist();
	curr = start;
	
	while(curr->next != NULL)
	{
		if(curr->info == curr->next->info)
		{
			prev = curr->next->next;
			free(curr->next);
			curr->next = prev;
		}
		else
			curr = curr->next;
	}
}

int length()
{
	if(start == NULL)
		return 0;
	int i = 1;
	curr = start;
	while(curr != NULL)
	{
		curr = curr->next;
		i++;
	}
	return i;
}

void display()
{
	if(start == NULL)
	{
		printf("List is empty\n");
		return;
	}
	curr = start;
	while(curr!=NULL)
	{
		printf("%d\n",curr->info);
		curr = curr->next;
	}
}

void reverse()
{
	if(start == NULL)
	{
		printf("List is empty\n");
		return;
	}
	curr = start;
	prev = curr->next;
	curr->next = NULL;
	while(prev->next != NULL)
	{
		node = prev->next;
		prev->next = curr;
		curr = prev;
		prev = node;
	}
	prev->next = curr;
	start = prev;
}

void sortlist()
{
	if(start == NULL)
	{
		printf("List is empty\n");
		return;
	}
	for(curr=start;curr!= NULL;curr=curr->next)
	{
		for(prev=curr->next; prev!=NULL; prev=prev->next)
		{
			if((curr->info > prev->info))
			{
				int temp = curr->info;
				curr->info = prev->info;
				prev->info = temp;
			}
		}
	}
}


#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
	int info;
	struct list* next;
}list;

list *start=NULL,*node=NULL,*curr=NULL,*prev=NULL;

void insert_beg(int num);
void insert_end(int num);
void insert_at_loc(int num,int loc);
void insert_after_value(int num);
void delete_beg();
void delete_end();
void delete_node(int num);
void delete_value(int num);
void replace_node(int num, int loc);
void delete_dup_vals();
void display();
void reverse();
void clear(void);
void sortlist();

void insert_beg(int num)
{
	if(start == NULL)
	{
		node = (list*)malloc(sizeof(list*));
		node->info = num;
		node->next = NULL;
		start = node;
	}
	else
	{
		node = (list*)malloc(sizeof(list*));
		node->info = num;
		node->next = start;
		start = node;
	}
}

void insert_end(int num)
{
	if(start == NULL)
	{
		node = (list*)malloc(sizeof(list*));
		node->info = num;
		node->next = NULL;
		start = node;
	}
	else
	{
		node = (list*)malloc(sizeof(list*));
		node->info = num;
		node->next = NULL;
		curr = start;
		while(curr->next!=NULL)
		{
			curr=curr->next;
		}
		curr=node;
	}
}

void insert_at_loc(int num,int loc)
{

	if(start == NULL)
	{
		node = (list*)malloc(sizeof(list*));
		node->info = num;
		node->next = NULL;
		start = node;
	}
	else
	{
		node = (list*)malloc(sizeof(list*));
		node->info = num;
		node->next = NULL;
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

void insert_after_value(int num)
{
	if(start == NULL)
	{
		node = (list*)malloc(sizeof(list*));
		node->info = num;
		node->next = NULL;
		start = node;
	}
	else
	{
		node = (list*)malloc(sizeof(list*));
		node->info = num;
		node->next = NULL;
		
		curr = start;
		while(curr != NULL && curr->info != num)
		{
			curr=curr->next;
		}
		node->next = curr->next;
		curr->next = node;
	}
}

void delete_beg()
{
	if(start == NULL)
		return;
	curr = start;
	start = curr->next;
	free(curr);
}

void delete_end()
{
	if(start == NULL)
		return;
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
	if(start == NULL)
		return;
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
		return;
	curr = start;
	while(curr != NULL && curr->info != num)
	{
		prev = curr;
		curr = curr->next;
	}
	prev->next = curr->next;
	free(curr);
}

void replace_node(int num, int loc)
{
	if(start == NULL)
		return;
	curr = start;
	int i = 1;
	
	while(curr != NULL && i < loc)
	{
		curr = curr->next;
		i++;
	}
	curr->info = num;
}

void delete_dup_vals()
{
	if(start == NULL)
		return;
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

void display()
{
	curr = start;
	while(curr!=NULL)
	{
		printf("%d\n",curr->info);
		curr = curr->next;
	}
}

void reverse()
{
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


#include <stdio.h>
#include <stdlib.h>

void insert_beg(int num);
void insert_end(int num);
void insert_at_loc(int num, int loc);
void insert_after_val(int num,int val);
void delete_beg();
void delete_end();
void delete_node(int loc);
void delete_val(int num);
void display();
void clear(void);

typedef struct clist
{
	int info;
	struct clist *next;
}clist;

clist *start=NULL,*curr=NULL,*node=NULL,*prev=NULL,*temp = NULL;


void insert_beg(int num)
{
	node = (clist*)malloc(sizeof(clist*));
	node->info = num;
	
	if(start == NULL)
	{
		start = node;
		node->next = start;
	}
	else
	{
		curr = start;
		while(curr->next != start)
			curr = curr->next;
		node->next = start;
		start = node;
		curr->next = start;
	}
}

void insert_end(int num)
{
	node = (clist*)malloc(sizeof(clist*));
	node->info = num;
	
	if(start == NULL)
	{
		start = node;
		node->next = start;
	}
	else
	{
		curr = start;
		while(curr->next != start)
			curr = curr->next;
		curr->next = node;
		node->next = start;
	}
}

void insert_at_loc(int num,int loc)
{
	node = (clist*)malloc(sizeof(clist*));
	node->info = num;
	int i = 2;
	
	if(start == NULL)
	{
		start = node;
		node->next = start;
	}
	curr = temp = start;
	
	if(loc == 1)
		insert_beg(num);
	
	else if(loc > 1)
	{
		while(i < loc)
		{
				curr = curr->next;
				i++;
		}
				
		node->next = curr->next;
		curr->next = node;
	}
}

void insert_after_val(int num,int val)
{
	node = (clist*)malloc(sizeof(clist*));
	node->info = num;
	
	if(start == NULL)
	{
		start = node;
		node->next = start;
	}

	curr = start;
	while(curr->info != val)
		curr = curr->next;
	
	node->next = curr->next;
	curr->next = node;
}

void delete_beg()
{
	if(start == NULL)
	{
		printf("List is empty\n");
		return;
	}
	curr = temp = start;
	while(curr->next != start)
		curr = curr->next;
	start = start->next;
	free(temp);
	curr->next = start;
}

void delete_end()
{
	if(start == NULL)
	{
		printf("List is empty\n");
		return;
	}
	curr = start;
	while(curr->next != start)
	{
		prev = curr;
		curr = curr->next;
	}
	prev->next = start;
	free(curr);
}

void delete_node(int loc)
{
	if(start == NULL)
		return;
		
	if(loc == 1)
		delete_beg();
	
	else if(loc > 1)
	{
		int i = 1;
		curr = start;
		while(curr->next != start && i < loc)
		{
			prev = curr;
			curr = curr->next;
			i++;
		}
		prev->next = curr->next;
		free(curr);
	}
}

void delete_val(int num)
{
	if(start == NULL)
		return;
		
	if(start->info == num)
		delete_beg();
	
	else
	{
		curr = start;
		while(curr->info != num)
		{
			prev = curr;
			curr = curr->next;
		}
		prev->next = curr->next;
		free(curr);
	}
}

void display()
{
	curr = start;
	do
	{
		printf("%d\n",curr->info);
		curr = curr->next;
	}while(curr!=start);
}




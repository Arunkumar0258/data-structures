#include <stdio.h>
#include <stdlib.h>

void insert_beg(int num);
void insert_end(int num);
void insert_at_loc(int num,int loc);
void insert_after_value(int num, int val);
void delete_beg();
void delete_end();
void delete_node(int loc);
void delete_value(int num);
void replace_value(int num,int val);
void replace_node(int num, int loc);
void sortlist();
int length();
void display();
void clear(void);

typedef struct dlist
{
	int info;
	struct dlist* next;
	struct dlist* prev;
}dlist;

dlist *start = NULL,*curr = NULL, *node = NULL, *pre = NULL;


void insert_beg(int num)
{
	node = (dlist*)malloc(sizeof(dlist*));
	node->info = num;
	node->prev = NULL;
	
	if(start == NULL)
	{
		node->next = NULL;
		start = node;
	}
	else
	{
		node->next = start;
		start->prev = node;
		start = node;
	}
}

void insert_end(int num)
{
	node = (dlist*)malloc(sizeof(dlist*));
	node->info = num;
	node->next = NULL;
	
	if(start == NULL)
	{
		node->prev = NULL;
		start = node;
	}
	else
	{
		curr = start;
		while(curr->next != NULL)
			curr = curr->next;
		curr->next = node;
		node->prev = curr;
	}
}

void insert_at_loc(int num,int loc)
{
	int n = length();
	if(loc > n)
	{
		printf("Location is invalid!!\n");
		return;
	}
	
	node = (dlist*)malloc(sizeof(dlist*));
	node->info = num;
	
	if(start == NULL)
	{
		node->next = NULL;
		node->prev = NULL;
		start = node;
	}
	else
	{
		curr = start;
		int i=1;
		while(curr != NULL && i < loc)
		{
			pre = curr;
			curr = curr->next;
			i++;
		}
		if(pre != NULL)
			pre->next = node;
		node->next = curr;
		node->prev = pre;
		if(curr != NULL)
			curr->prev = node;
	}
}

void insert_after_value(int num, int val)
{
	node = (dlist*)malloc(sizeof(dlist*));
	node->info = num;
	
	if(start == NULL)
	{
		node->next = NULL;
		node->prev = NULL;
		start = node;
	}
	else
	{
		curr = start;
		while(curr != NULL && curr->info != val)
		{
			curr = curr->next;
		}
		if(curr == NULL)
		{
			printf("Value not found!! Please enter again\n");
			return;
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
	int n = length();
	
	if(loc > n)
	{
		printf("Location is invalid\n");
		return;
	}
	
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
	
	if(curr == NULL)
	{
		printf("Value not found! Please try again\n");
		return;
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
{
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

int length()
{
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
	curr = start;
	while(curr != NULL)
	{
		printf("%d\n",curr->info);
		curr = curr->next;
	}
}

void display_reverse()
{
	curr = start;
	while(curr->next != NULL)
		curr = curr->next;
	
	while(curr != NULL)
	{
		printf("%d\n",curr->info);
		curr = curr->prev;
	}
}

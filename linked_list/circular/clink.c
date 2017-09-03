#include <unistd.h>
#include "clink.h"

void print();
int menu();

int main()
{
	int n;
	printf("WELCOME TO THE LINKED LIST APPLICATION\n");
	clear();
	usleep(500000);
	
	do
	{
		clear();
		usleep(500000);
		print();
		n = menu();
		
	}while(n!=10);
	clear();
}

void print()
{
	printf("1. Insert at beginning\n");
	printf("2. Insert at end\n");
	printf("3. Insert at any particular location\n");
	printf("4. Insert after a particular value\n");
	printf("5. Delete at beginning\n");
	printf("6. Delete at end\n");
	printf("7. Delete a particular node\n");
	printf("8. Delete a particular value\n");
	printf("9. Display\n");
	printf("10. Quit\n");
}

int menu()
{
	int n,a,b;
	printf("Select the operation you want to perform (10 to Quit): ");
	scanf("%d",&n);
	
	switch(n)
	{
		case 1:
				printf("Enter the number you want to insert: ");
				scanf("%d",&a);
				insert_beg(a);
				break;
		case 2:
				printf("Enter a number you want to insert: ");
				scanf("%d",&a);
				insert_end(a);
				break;
		case 3:
				printf("Enter the number you want to insert: ");
				scanf("%d",&a);
				printf("Enter the location at which to insert: ");
				scanf("%d",&b);
				insert_at_loc(a,b);
				break;
		case 4:
				printf("Enter the number you want to insert: ");
				scanf("%d",&a);
				printf("Enter the value after which to insert: ");
				scanf("%d",&b);
				insert_after_val(a,b);
				break;
		case 5:
				delete_beg(a);
				break;
		case 6:
				delete_end(a);
				break;
		case 7:
				printf("Enter the location of node you want to delete: ");
				scanf("%d",&a);
				delete_node(a);
				break;
		case 8:
				printf("Enter the value you want to delete: ");
				scanf("%d",&a);
				delete_val(a);
				break;
		case 9:
				display();
				usleep(5000000);
				break;
		case 10:
				return n;
				break;
	}
}

void clear(void)
{
	printf("\033[2J");
	printf("\033[%d;%dH",0,0);
}

















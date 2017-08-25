#include "dlink.h"
#include <unistd.h>
int menu();
void print();

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
		
	}while(n!=14);
}

void print()
{
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
	printf("13. Display in reverse\n");
	printf("14. Quit\n");
		
}

int menu()
{
	int n,a,b;
	printf("Select the operation you want to perform (14 to Quit): ");
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
					insert_at_loc(a,b);
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
					display_reverse();
					usleep(5000000);
					break;
			case 14:
					return 14;
		}		
}
void clear(void)
{
	printf("\033[2J");
	printf("\033[%d;%dH",0,0);
}
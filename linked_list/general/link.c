#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "link.h"

void print();
void clear();
int menu();

int main()
{	
	int c;
	printf("WELCOME TO THE LINKED LIST APPLICATION\n");
	clear();
	usleep(500000);
	
	do
	{	
		c = menu();

	}while(c!=14);
}

void print()
{
	printf("1. Insert at beginning\n");
	printf("2. Insert at end\n");
	printf("3. Insert at a particular location\n");
	printf("4. Insert after a particular value\n");
	printf("5. Delete from beginning\n");
	printf("6. Delete from end\n");
	printf("7. Delete a particular node\n");
	printf("8. Delete a particular value\n");
	printf("9. Replace a value at a particular node\n");
	printf("10. Delete all duplicate values\n");
	printf("11. Display\n");
	printf("12. Reverse\n");
	printf("13. Sort(Ascending)\n");
	printf("14. Quit\n\n");
}

int menu()
{
	int n,a,b;
	clear();
	usleep(500000);
	
	print();
	
	printf("Select the operation you want to perform (6 to Quit): ");
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
					insert_beg(a);
					break;
			case 3:
					printf("Enter the number you want to insert: ");
					scanf("%d",&a);
					printf("Enter the location in which you want to insert: ");
					scanf("%d",&b);
					if(b < 0)
					{
						printf("WARNING!!!! Invalid location. Enter value again\n");
						usleep(800000);
						break;
					}
					insert_at_loc(a,b);
					break;
			case 4:
					printf("Enter the value after which to insert: ");
					scanf("%d",&a);
					insert_after_value(a);
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
					if(a < 0)
					{
						printf("WARNING!!!! Invalid location. Enter value again\n");
						usleep(800000);
						break;
					}
					delete_node(a);
					break;
			case 8:
					printf("Enter the value you want to delete: ");
					scanf("%d",&a);
					delete_value(a);
					break;
			case 9:
					printf("Enter the location of node you want to replace: ");
					scanf("%d",&b);
					printf("Enter the value to replace it with: ");
					scanf("%d",&a);
					replace_node(a,b);
					break;
			case 10:
					delete_dup_vals();
					break;
			case 11: 
					display();
					usleep(5000000);
					break;
			case 12: 
					reverse();
					break;
			case 13:
					sortlist();
					break;
			case 14:
					return n;
					break;
		}
}

void clear(void)
{
	printf("\033[2J");
	printf("\033[%d;%dH",0,0);
}





































/*
 *	Stack : Program 2 : Dynamically sized Stack using Dynamic Array
 *		& user controlled menu based operations on the stack
 *
 * 	1. Ask user about max stack elements that stack will hold
 * 	   Will be from 1-10000 elements
 *	2. Allocate dynamic memory for the array instead of static arrays 
 *	3. Provide a menu for the operations - which keeps on asking
 * 	   in a loop until user asks to exit
 *	4 Overflow and underflow should be based on the max number
 *
 *	@author Jagannathdas Rath <jrathindia@gmail.com>
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_ELEMENTS 10000

int max_stack_elements;

typedef enum {
	STACK_OVERFLOW = 1,
	STACK_UNDERFLOW,
	STACK_EMPTY
} stack_err_code_t;

int * stack_array;
int stack_top = -1;

int
push(int element)
{
	if (stack_top == max_stack_elements - 1) {
		printf("push : Stack Overflow\n");

		return (-STACK_OVERFLOW);
	}

	stack_array[++stack_top] = element;
	printf("push : Element pushed : %d\n", element);

	return (0);
}

int
pop(void)
{
	int element = 0;

	if (stack_top == -1) {
		printf("pop : Stack Underflow\n");

		return (-STACK_UNDERFLOW);
	}

	element = stack_array[stack_top--];
	printf("pop : Element popped : %d\n", element);

	return (element);
}


int
peek(void)
{
	int element = 0;

	if (stack_top == -1) {
		printf("peek : Stack Underflow\n");

		return (-STACK_UNDERFLOW);
	}

	element = stack_array[stack_top];
	printf("peek : Top element : %d\n", element);


	return (element);
}


void
display(void)
{
	int i = 0;
	
	printf("\nStack elements (%d elems)\n", (stack_top + 1));
	for (i = stack_top; i >= 0; i--) {
		printf("[Element %3d]  %d\n", i, stack_array[i]);
	}
	printf("\n");
}


void
exit_stack(void)
{
	if (stack_array)
		free(stack_array);

	exit(0);
}

void
display_menu(void)
{

	int choice = 0, elem = 0, ret = 0;

	while (1) {
		elem = -1;

		printf("Stack Operations\n");
		printf("------------------------------\n");
		printf("1. Push \n");
		printf("2. Pop \n");
		printf("3. Peek \n");
		printf("4. Display \n");
		printf("5. Exit \n");
		printf("------------------------------\n");
		printf("Please enter choice : "); 
		scanf("%d", &choice);
		getchar();
		

		printf("\n");

		switch (choice) {
				
			case 1 : 
				printf("Please enter element to be pushed: ");
				scanf("%d", &elem);
				getchar();
				push(elem);
				break;

			case 2 :
				pop();
				break;

			case 3 :
				peek();
				break;

			case 4 : 
				display();
				break;
			case 5 :
				exit_stack();
				break;
			default : 
				printf("Invalid option. Please enter from "
				    "(1-5)\n");

		}
		printf("\n\n");
				

	}

}

int
main(int argc, char **argv)
{
	printf("Please enter the maximum number of "
	    "elements the stack will hold : ");
	scanf("%d", &max_stack_elements);
	getchar();

	if (max_stack_elements <= 0 ||
		max_stack_elements > MAX_STACK_ELEMENTS) {
		printf("Provide a valid max no. of "
		    "stack elements (1-%d)\n",
		    MAX_STACK_ELEMENTS);

		exit(1);
	}

	printf("Max stack elements : %d\n", max_stack_elements);
	
	stack_array = malloc(sizeof(int) * max_stack_elements);

	if (!stack_array) {
		printf("Memory allocation for stack failed\n");

		return (1);
	}

	memset(stack_array, 0, max_stack_elements);

	display_menu();	

	return (0);
}

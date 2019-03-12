/*
 *
 *	Stack : Program 1 : Basic Stack using Fixed Array
 *
 *
 *	@author Jagannathdas Rath <jrathindia@gmail.com>
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_ELEMENTS 10

typedef enum {
	STACK_OVERFLOW = 1,
	STACK_UNDERFLOW,
	STACK_EMPTY
} stack_err_code_t;

int stack_array[MAX_STACK_ELEMENTS];

int stack_top = -1;

int
push(int element)
{
	if (stack_top == MAX_STACK_ELEMENTS - 1) {
		printf("Stack Overflow\n");

		return (-STACK_OVERFLOW);
	}

	stack_array[++stack_top] = element;
	printf("pushed %d\n", element);

	return (0);
}

int
pop(void)
{
	int element = 0;

	if (stack_top == -1) {
		printf("Stack Underflow\n");

		return (-STACK_UNDERFLOW);
	}

	element = stack_array[stack_top--];

	printf("popped %d\n", element);

	return (element);
}


int
peek(void)
{
	int element = 0;

	if (stack_top == -1) {
		printf("Stack Underflow\n");

		return (-STACK_UNDERFLOW);
	}

	element = stack_array[stack_top];

	printf("peek %d\n", element);

	return (element);
}


void
display(void)
{
	int i = 0;
	
	printf("\nStack elements\n");
	for (i = stack_top; i >= 0; i--) {
		printf("[Element %3d]  %d\n", i, stack_array[i]);
	}
	printf("\n");
}




int
main(int argc, char **argv)
{
	push(1);
	push(3);
	push(4);
	push(5);
	display();
	peek();
	pop();
	printf("Pop : %d\n", pop());
	display();
	pop();
	pop();
	pop();

	return (0);
}

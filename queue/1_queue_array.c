/*
 * Queue : Program 1
 * 	   Basic queue with fixed size Array
 *
 * @author Jagannathdas Rath <jrathindia@gmail.com>
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_ELEMENTS	5

int front = -1, rear = -1;
int queue[MAX_QUEUE_ELEMENTS];


int
enqueue(int element)
{
	if (rear == MAX_QUEUE_ELEMENTS - 1) {
		printf("Queue overflow\n");
		return (1);
	}
	
	// first element addition
	if (rear == -1)
		front = 0;
		
	queue[++rear] = element;

	printf("Enqueued element %d\n", element);
	// printf("f:%d, r:%d\n", front, rear);

	return (0);
}

int
dequeue(void)
{
	int element = 0;

	if (front == -1) {
		printf("Queue Underflow\n");
		return (1);
	}

	element = queue[front++];

	// last element deletion
	if (front == MAX_QUEUE_ELEMENTS) {
		front = -1;
		rear = -1;
	}

	printf("Dequeued %d\n", element);
	// printf("f:%d, r:%d\n", front, rear);

	return (0);
}

int
peek(void)
{
	if (front == -1) {
		printf("Queue Underflow\n");
		return (1);
	}

	printf("peek : %d\n", queue[front]);

	return (queue[front]);
}

void
display_queue(void)
{
	int i = 0;

	printf("Queue members : [FRONT] ");
	for (i = front; i <= rear; i++) {
		printf(" %d ", queue[i]);
	}

	printf(" [REAR]\n");
}

int
main(int argc, char **argv)
{
	enqueue(10);
	enqueue(12);
	enqueue(13);
	enqueue(14);
	enqueue(15);

	// overflow
	enqueue(16);
	display_queue();
	dequeue();
	peek();
	display_queue();
	dequeue();
	dequeue();
	dequeue();
	dequeue();

	// underflow
	dequeue();
	enqueue(10);
	enqueue(12);
	enqueue(13);
	enqueue(14);
	enqueue(15);
	enqueue(18);
	display_queue();
	
	return (0);
}

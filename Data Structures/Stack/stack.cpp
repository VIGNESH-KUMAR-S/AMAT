#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}NODE;

NODE* createNode()
{
	NODE* temp = NULL;
	temp = (NODE*)malloc(sizeof(NODE));
	return temp;
}

// In cpp the structure member can be both data and functions but in c it can be only data.
typedef struct stack {
	int stackSize;
	NODE* top;
	void push(int item)
	{
		NODE* temp = createNode();
		temp->next = top;
		temp->data = item;
		top = temp;
		++stackSize;
		printf("\n\tItem %d pushed at top", item);
		return;
	}
	int* pop()
	{
		NODE* temp = top;
		if (top == NULL)
		{
			puts("\n\tStack is Empty!");
			return NULL;
		}
		top = top->next;
		temp->next = NULL;
		--stackSize;
		int* address = (int *)temp;
		// We shouldn't free temp.
		// free(temp);
		return address;
	}
}STACK;

int main(void)
{
	STACK s;
	s.stackSize = 0;
	// PUSH 5 items in stack
	s.push(11);	s.push(21);	s.push(31);	s.push(41);	s.push(51);

	// Get size of stack
	int size = s.stackSize;
	printf("\n\n\tSize of stack is\t\t: %d", size);

	// Get top of the stack
	printf("\n\n\tTop item in the stack is\t: %d", (s.top)->data);

	// POP 5 items in stack
	// pop() function returns NODE* 
	printf("\n\n\tStack items in top order\n");
	
	for (int i = 0; i < size; i++)
	{
		int* item = s.pop();
		printf("\tItem %d\t: %d\n", i+1, *item);
	}
}
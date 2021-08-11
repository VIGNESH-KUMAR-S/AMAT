#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}NODE;

int count = 0;
NODE* head = NULL;
NODE* tail = NULL;

void print()
{
	NODE* temp = head;
	if (temp == NULL)
	{
		puts("\n\tList Empty");
		return;
	}
	while (temp != NULL)
	{
		printf("%d\t%d\t%d\n", temp, temp->data, temp->next);
		temp = temp->next;
	}
}

NODE* createNode()
{
	NODE* temp = NULL;
	temp = (NODE*)malloc(sizeof(NODE));
	printf("\n\tEnter Data\t: ");
	scanf("%d", &temp->data);
	temp->next = NULL;
	return temp;
}

void addFirst()
{
	NODE* temp = NULL;
	if (head == NULL)
	{
		head = createNode();
		tail = head;
		++count;
		return;
	}
	temp = createNode();
	temp->next = head;
	head = temp;
	++count;
}

void addLast()
{
	NODE * temp = NULL;
	if (tail == NULL)
	{
		tail = createNode();
		head = tail;
		++count;
		return;
	}
	temp = createNode();
	tail->next = temp;
	tail = temp;
	++count;
}

void addAnyWhere(int position)
{
	// Assume starting node's position considered as zero
	int pos = 0;
	NODE* temp = head;
	NODE* newNode = NULL;
	NODE* copyNode = NULL;
	if (position > count)
	{
		puts("\n\tInvalid Position - Insertion not possible!");
		return;
	}
	while (pos != position)
	{
		copyNode = temp;
		temp = temp->next;
		++pos;
	}
	// It's possible to use this without temp
	newNode = createNode();
	copyNode->next = newNode;
	newNode->next = temp;
	++count;
}

void deleteFirst()
{
	NODE* temp = head;
	if (head == NULL)
	{
		puts("\n\tList already Empty!");
		return;
	}
	head = head->next;
	if (head == NULL)
	{
		tail = NULL;
	}
	free(temp);
	--count;
}

void deleteLast()
{
	NODE* temp = head;
	if (tail == NULL)
	{
		puts("\n\tList already Empty!");
		return;
	}
	if (head == tail)
	{
		head = tail = NULL;
		return;
	}
	while (temp->next != tail)
	{
		temp = temp->next;
	}
	tail = temp;
	tail->next = NULL;
	free(temp->next);
	--count;
}

void deleteAnyWhere(int position)
{
	// Assume starting node's position considered as zero
	int pos = 0;
	NODE* temp = head;
	NODE* copyNode = NULL;
	if (position > count)
	{
		puts("\n\tInvalid Position - Deletion not possible!");
		return;
	}
	while (pos != position)
	{
		copyNode = temp;
		temp = temp->next;
		pos++;
	}
	copyNode->next = temp->next;
	free(temp);
	--count;
}

int main(void)
{
	while (1)
	{
		int one;
		printf("\n\tPress 1 to continue\t: ");
		scanf("%d", &one);
		if (one != 1)
			break;
		int swich;
		puts("\n\t1 to Print LL\n\t2 to addFirst\n\t3 to addLast");
		puts("\t4 to addAnyWhere\n\t5 to deleteFirst\n\t6 to deleteLast");
		scanf("%d", &swich);
		switch (swich)
		{
			int position;
		case 1:
			print();
			break;
		case 2:
			addFirst();
			break;
		case 3:
			addLast();
			break;
		case 4:
			printf("\n\tEnter Node's position Assume 0 is starting node's position\t: ");
			scanf("%d", &position);
			addAnyWhere(position);
			break;
		case 5:
			deleteFirst();
			break;
		case 6:
			deleteLast();
			break;
		case 7:
			printf("\n\tEnter Node's position Assume 0 is starting node's position\t: ");
			scanf("%d", &position);
			deleteAnyWhere(position);
			break;
		default:
			break;
		}
	}
}
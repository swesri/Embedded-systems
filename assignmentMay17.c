/*assignmentMay17.c
May 17 assignment:
Reverse linked list 
Author: Swetha Varadarajan
Date created: May 18,2017

Reversal of linked list

*/


#include<stdio.h>
#include<stdlib.h>
#include"linked_list.h"

struct node *a = NULL;

void reverse_May17(struct node *r)
{
	struct node *p, *q=NULL;
	while(r!=NULL)
	{
		p = q;
		q = r;
		r = r->next;
		q->next = p;
	}
	a = q;
}


void main(int argc,char** argv) 
{

	//struct node *a = NULL;
	push(&a, 5);
	push(&a, 20);
	push(&a, 4);
	push(&a, 3);
	push(&a, 30);
	push(&a, 71);

	printf("Linked List before reversing\n");
	printList(a);

	reverse_May17(a);

	printf("Linked List after reversing\n");
	printList(a);

}

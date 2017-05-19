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
#define diagram 0

struct node *a = NULL;


void printfile()
{
	FILE *fptr;
 
	char filename[100]= "diagram.txt", c;

	fptr = fopen(filename, "r");
	if (fptr == NULL)
	{
	printf("Cannot open file \n");
	exit(0);
	}

	c = fgetc(fptr);
	while (c != EOF)
	{
		printf ("%c", c);
		c = fgetc(fptr);
	}

	fclose(fptr);
}

void reverse_May17(struct node *r)
{
	struct node *p, *q=NULL;
	while(r!=NULL)
	{
		p = q;
		q = r;
		r = r->next;
		q->next = p;
		if(p!=NULL)
			printf("q value:%d\t pvalue:%d\n",q->data,p->data);
	}
	
	if(diagram)
		printfile();
	/*
	p points to q pointer.
	q points to the head of the current list. current list pointer is incremented in each iteration.
	q->next points to q. 

		|r0|r1|r2|r3|r4|r5(head)|NULL| ---> moves with each iteration.	
					  
			     	  ^	   	
				  |	  
					  	
			q->next	| q |NULL|  ---> grows with each iteration.
		           |	       ^	
			   | 	       |
			   |	       |
			   |  	       | 
			   |->>>>|p| --|			 
	*/
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

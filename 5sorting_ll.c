/*5sorting_ll.c
Author: Swetha Varadarajan
Date created: May 9,2017

Reversal of linked list

*/


#include<stdio.h>
#include<stdlib.h>
#include"linked_list.h"


void main(int argc,char** argv) 
{
	struct node *a = NULL;
	push(&a, 5);
	push(&a, 20);
	push(&a, 4);
	push(&a, 3);
	push(&a, 30);

	printf("Linked List before sorting \n");
	printList(a);

	quickSort(&a);

	printf("Linked List after sorting \n");
	printList(a);

}
